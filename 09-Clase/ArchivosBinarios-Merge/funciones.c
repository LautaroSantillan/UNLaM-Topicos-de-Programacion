#include "funciones.h"

void imprimirArgs(int argc, char* argv[]){
	printf("argc: %d\n", argc);
	for(int i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);
    puts("\n");
}

int generarProductos(const char* nomArchProds){
	Producto vProds[CANT_PRODS] ={
        {1, "Anana", 300.0, 30},
		{2, "Kiwi", 500.0, 50},
		{4, "Ciruela", 900.0, 90},
		{5, "Manzana", 200.0, 20},
		{6, "Uva", 1000.0, 100},
		{8, "Pera", 100.0, 10},
		{9, "Banana", 400.0, 40},
		{10, "Durazno", 800.0, 80},
		{11, "Naranja", 600.0, 60}
    };

	FILE *pf = fopen(nomArchProds, "wb");
	if (pf == NULL){
		printf("Error al abrir el archivo\n");
		return ERR_ARCHIVO;
	}

	fwrite(vProds, sizeof(Producto), CANT_PRODS, pf);
	fclose(pf);
	return TODO_OK;
}

int generarMovimientos(const char* nomArchMovi){
	Movimiento vMovi[CANT_MOVS] = {
		{1, 50},
		{2, 20},
		{3, 10},
		{3, 20},
		{5, 50},
		{5, 10},
		{6, 40},
		{7, 90},
		{8, 70},
		{9, 30},
		{10, 100},
		{12, 30},
		{12, 10},
		{12, 20}
	};

	FILE *pf = fopen(nomArchMovi, "wb");
	if (pf == NULL){
		printf("Error al abrir el archivo\n");
		return ERR_ARCHIVO;
	}

	fwrite(vMovi, sizeof(Movimiento), CANT_MOVS, pf);
	fclose(pf);
	return TODO_OK;
}

int mostrarProductos(const char* nomArchProds){
	Producto prod;

	FILE *pf = fopen(nomArchProds, "rb");
	if (pf == NULL){
		printf("Error al abrir el archivo\n");
		return ERR_ARCHIVO;
	}

	fread(&prod, sizeof(Producto), 1, pf);
	while(!feof(pf)){
		printf("%2d, %-*s, %8.2f, %3d\n", prod.codigo, TAM_DESCR, prod.descripcion, prod.precio, prod.stock);
		fread(&prod, sizeof(Producto), 1, pf);
	}

	fclose(pf);
	return TODO_OK;
}

int cmpIndProd(const void* e1, const void* e2){
	const IndProducto* i1 = e1;
	const IndProducto* i2 = e2;
	return i1->codigo - i2->codigo;
}

int actualizarStockProductos(const char* nomArchProds, const char* nomArchMov){
	FILE* archProd = fopen(nomArchProds, "rb");
	if(!archProd)
		return ERR_ARCHIVO;

	FILE* archMov = fopen(nomArchMov, "rb");
	if(!archMov){
		fclose(archProd);
		return ERR_ARCHIVO;
	}

	FILE* archProdTmp = fopen("Productos.tmp", "wb");
	if(!archProdTmp){
		fclose(archProd);
		fclose(archMov);
		return ERR_ARCHIVO;
	}

	Producto prod;
	Movimiento mov;
	int comp;

	fread(&prod, sizeof(Producto), 1, archProd);
	fread(&mov, sizeof(Movimiento), 1, archMov);
	while(!feof(archProd) && !feof(archMov)){
		comp = prod.codigo - mov.codigo;

		if(comp == 0){
			prod.stock += mov.cantidad;
			fread(&mov, sizeof(Movimiento), 1, archMov);
		}

		/// Prod sin/mas Mov
		if(comp < 0){
			fwrite(&prod, sizeof(Producto), 1, archProdTmp);
			fread(&prod, sizeof(Producto), 1, archProd);
		}

		/// Prod nuevo
		if(comp > 0)
			procesarProductoNuevo(&mov, archMov, archProdTmp);
	}

	/// Prods sin Movs
	while(!feof(archProd)){
		fwrite(&prod, sizeof(Producto), 1, archProdTmp);
		fread(&prod, sizeof(Producto), 1, archProd);
	}

	/// Prods nuevos
	while(!feof(archMov))
		procesarProductoNuevo(&mov, archMov, archProdTmp);

	fclose(archProd);
	fclose(archMov);
	fclose(archProdTmp);
	remove(nomArchProds);
	rename("Productos.tmp", nomArchProds);
	return TODO_OK;
}

void procesarProductoNuevo(Movimiento* mov, FILE* archMov, FILE* archProdTmp){
	Producto prodNuevo;
	prodNuevo.codigo = mov->codigo;
	prodNuevo.descripcion[0] = '\0';
	prodNuevo.precio = 0;
	prodNuevo.stock = mov->cantidad;

	fread(mov, sizeof(Movimiento), 1, archMov);
	while(!feof(archMov) && prodNuevo.codigo == mov->codigo){
		prodNuevo.stock += mov->cantidad;
		fread(mov, sizeof(Movimiento), 1, archMov);
	}

	fwrite(&prodNuevo, sizeof(Producto), 1, archProdTmp);
}

/// VECTOR.C
bool vectorCrear(T_Vector* vec, size_t tamElem){
    vec->ce = 0;
    vec->vec = malloc(tamElem * CAP_INICIAL);

    if(vec->vec == NULL){
        vec->cap = 0;
        return false;
    }

    vec->cap = CAP_INICIAL;
    vec->tamElem = tamElem;
    return true;
}

int vectorGrabar(T_Vector* vec, const char* nomFile){
    FILE *pf = fopen(nomFile, "wb");

    if(!pf)
        return ERR_ARCHIVO;

    fwrite(vec->vec, vec->tamElem, vec->ce, pf);

    fclose(pf);
    return TODO_OK;
}

bool vectorCrearDesdeArchivo(T_Vector* vec, size_t tamElem, const char* nomFile){
    FILE *pf = fopen(nomFile, "rb");

    if(!pf)
        return false;

    fseek(pf, 0L, SEEK_END);
    vec->ce = ftell(pf) / tamElem;
    vec->vec = malloc(tamElem * vec->ce);

    if(vec->vec == NULL){
        vec->cap = 0;
        fclose(pf);
        return false;
    }

    vec->cap = vec->ce;
    vec->tamElem = tamElem;

    rewind(pf);
    fread(vec->vec, tamElem, vec->ce, pf);
    fclose(pf);
    return true;
}

int vectorOrdInsertar(T_Vector* vec, const void* elem, Cmp cmp){
    if(vec->ce == vec->cap){
        if(!redimensionarVector(vec, FACTOR_INCR))
            return SIN_MEM;
    }

    void* posIns = vec->vec;
    void* ult = vec->vec + (vec->ce - 1) * vec->tamElem;

    while(posIns <= ult && cmp(elem, posIns) > 0)
        posIns += vec->tamElem;

    if(posIns <= ult && cmp(elem, posIns) == 0)
        return DUPLICADO;

    for(void* i = ult; i >= posIns; i -= vec->tamElem)
       memcpy(i + vec->tamElem, i, vec->tamElem); /// *(i + 1) = *i;

    memcpy(posIns, elem, vec->tamElem);
    vec->ce++;
    return TODO_OK;
}

bool redimensionarVector(T_Vector* vec, float factor){
    size_t nCap = vec->cap * factor;

	if(nCap < CAP_INICIAL)
		return false;

	void* nVec = realloc(vec->vec, vec->tamElem * nCap);

    if(!nVec)
		return false;

	vec->vec = nVec;

	printf("Redimension de %lu a %lu\n", (unsigned long)vec->cap, (unsigned long)nCap);

	vec->cap = nCap;
	return true;
}

int vectorOrdBuscar(const T_Vector* vec, void* elem, Cmp cmp){
    void* li = vec->vec;
    void* ls = vec->vec + (vec->ce - 1) * vec->tamElem;
    void* m = NULL;
    int comp;

    while(li < ls){
        m = li + ((ls - li) / vec->tamElem / 2) * vec->tamElem;
        comp = cmp(elem, m);

        if(comp == 0){
            memcpy(elem, m, vec->tamElem);
            return (m - vec->vec) / vec->tamElem;
        }

        if(comp < 0)
            ls = m - vec->tamElem;

        if(comp > 0)
            li = m + vec->tamElem;
    }
    return -1;
}

void vectorEliminar(T_Vector* vec){
	free(vec->vec);
	vec->vec = NULL;
	vec->ce = 0;
	vec->cap = 0;
}
