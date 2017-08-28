#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *izq;
	struct nodo *der;
};

//Crear Nodo
struct nodo *crear(int valor){
	struct nodo *nuevo = (struct nodo*)malloc(sizeof(struct nodo));
	nuevo->dato = valor;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	return nuevo;	
}
//Insertar un nodo hijo a la derecha de su padre
struct nodo *addDerecha(struct nodo *Padre,struct nodo *Hijo){
	Padre->der = Hijo;
	return Padre;	
}
//Insertar un nodo hijo a la izquierda de su padre
struct nodo *addIzquierda(struct nodo *Padre,struct nodo *Hijo){
	Padre->izq = Hijo;
	return Padre;
}
//imprimir un nodo
void imprimirNodo(struct nodo *vNodo){
	if(vNodo != NULL){
		printf(" %d ",vNodo->dato);
	}
}

//Funciones para recorrer un arbol BINARIO

//PRE-ORDEN  R-I-D
void preOrden(struct nodo *vNodo){
	if(vNodo!=NULL){
		imprimirNodo(vNodo);
		preOrden(vNodo->izq);
		preOrden(vNodo->der);
	}
}

//IN-ORDEN I-R-D
void inOrden(struct nodo *vNodo){
	if(vNodo!=NULL){
		inOrden(vNodo->izq);
		imprimirNodo(vNodo);
		inOrden(vNodo->der);
	}
}

//POST-ORDEN I-D-R
void postOrden(struct nodo *vNodo){
	if(vNodo!=NULL){
		postOrden(vNodo->izq);
		postOrden(vNodo->der);
		imprimirNodo(vNodo);
	}
}

int main(){
	//Creación del árbol
	struct nodo *raiz;
	raiz = crear(1);
	raiz->izq = crear(2);
	raiz->izq->izq = crear(4);
	raiz->der = crear(3);
	raiz->der->izq = crear(5);
	raiz->der->der= crear(6);
	
	//Mostrar busquedas
	printf("Preorden\n");
	preOrden(raiz);
	printf("\n");
	
	printf("Inorden\n");
	inOrden(raiz);
	printf("\n");
	
	printf("Postorden\n");
	postOrden(raiz);
	printf("\n");
	
	return 0;
}
