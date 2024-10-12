#include "funciones.h"

void imprimirArgs(int argc, char* argv[]){
	printf("argc: %d\n", argc);

	for(int i = 0; i < argc; i++)
    printf("argv[%d]: %s\n", i, argv[i]);
}

int generarProductos(const char* nomFileProd){
	T_Producto vProds[CANT_PROD] = {
        {8, "Pera", 100.0, 10},
        {5, "Manzana", 200.0, 20},
        {1, "Anana", 300.0, 30},
        {9, "Banana", 400.0, 40},
        {2, "Kiwi", 500.0, 50},
        {7, "Naranja", 600.0, 60},
        {3, "Mandarina", 700.0, 70},
        {10, "Durazno", 800.0, 80},
        {4, "Ciruela", 900.0, 90},
        {6, "Uva", 1000.0, 100}
    };

	FILE *pf = fopen(nomFileProd, "wb");
	if (pf == NULL){
		puts("Error al abrir el archivo\n");
		return ERROR_ARCHIVO;
	}

	fwrite(vProds, sizeof(T_Producto), CANT_PROD, pf);
	fclose(pf);
	return TODO_OK;
}

int generarIndiceProductos(const char* nomFileProd, const char* nomFileIdx){
    FILE *pf = fopen(nomFileProd, "rb");
	if (pf == NULL){
		puts("Error al abrir el archivo\n");
		return ERROR_ARCHIVO;
	}

    T_Producto prod;
	T_IndProducto indProd;
	unsigned nroReg = 0;
	T_Vector vIndice;
	vectorCrear(&vIndice, sizeof(T_IndProducto));

	fread(&prod, sizeof(T_Producto), 1, pf);
	while(!feof(pf)){
		indProd.codigo = prod.codigo;
		indProd.nroReg = nroReg++;
		vectorOrdInsertar(&vIndice, &indProd, cmpIndProd);
		fread(&prod, sizeof(T_Producto), 1, pf);
	}

	fclose(pf);
	vectorGrabar(&vIndice, nomFileIdx);
	vectorEliminar(&vIndice);
	return TODO_OK;
}

int mostrarProductos(const char* nomFileProd){
	T_Producto prod;
	FILE *pf = fopen(nomFileProd, "rb");
	if (pf == NULL){
		puts("Error al abrir el archivo\n");
		return ERROR_ARCHIVO;
	}

	fread(&prod, sizeof(T_Producto), 1, pf);
	while(!feof(pf)){
		printf("%2d, %-*s, %8.2f, %3d\n", prod.codigo, TAM_DESCRIP, prod.descripcion, prod.precio, prod.stock);
		fread(&prod, sizeof(T_Producto), 1, pf);
	}

	fclose(pf);
	return TODO_OK;
}

int actualizarPrecioProductos(const char* nomFileProd, float porcentaje){
	T_Producto prod;

	FILE *pf = fopen(nomFileProd, "r+b");
    if (pf == NULL){
		puts("Error al abrir el archivo\n");
		return ERROR_ARCHIVO;
	}

	float porcentajeProd = 1 + porcentaje / 100;

	fread(&prod, sizeof(T_Producto), 1, pf);
	while(!feof(pf)){
		prod.precio *= porcentajeProd;
		fseek(pf, -(long)sizeof(T_Producto), SEEK_CUR); /// SEEK_SET o SEEK_END
		fwrite(&prod, sizeof(T_Producto), 1, pf);
		fseek(pf, 0L, SEEK_CUR);
		fread(&prod, sizeof(T_Producto), 1, pf);
	}

	fclose(pf);
	return TODO_OK;
}

int cmpIndProd(const void* e1, const void* e2){
	const T_IndProducto* i1 = e1;
	const T_IndProducto* i2 = e2;
	return i1->codigo - i2->codigo;
}

int actualizarPrecio1Producto(const char* nomFileProd, int codProd, float porcentaje){
	FILE *pf = fopen(nomFileProd, "r+b");

	if(!pf)
		return ERROR_ARCHIVO;

	T_Vector vIndice;
	vectorCrearDesdeArchivo(&vIndice, sizeof(T_IndProducto), NOMBRE_IDX);

	T_IndProducto indProd;
	indProd.codigo = codProd;

	T_Producto prod;
	float porcProd = 1 + porcentaje / 100;

	int pos = vectorOrdBuscar(&vIndice, &indProd, cmpIndProd);
	if (pos == -1) {
		fclose(pf);
		vectorEliminar(&vIndice);
		return ERROR;
	}

	fseek(pf, pos * sizeof(T_Producto), SEEK_SET); /// Ubicamos el registro del producto
	fread(&prod, sizeof(T_Producto), 1, pf);
	prod.precio *= porcProd;
	fseek(pf, pos * sizeof(T_Producto), SEEK_SET); /// Guardamos el registro actualizado
	fwrite(&prod, sizeof(T_Producto), 1, pf);

	fclose(pf);
	vectorEliminar(&vIndice);
	return TODO_OK;
}

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
        return ERROR_ARCHIVO;

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
