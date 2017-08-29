#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
	int dato;
	nodo *izq;
	nodo *der;
};

nodo *crearNodo(int n){
	nodo *nuevo = new nodo();
	nuevo->dato = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	return nuevo;
}

void insertarNodo(nodo *&arbol,int n){
	if(arbol == NULL){
		nodo *aux = crearNodo(n);
		arbol = aux;		
	}
	else{
		if(n < arbol->dato){
			insertarNodo(arbol->izq,n);
		}
		else{
			insertarNodo(arbol->der,n);
		}
	}
	
}

void imprimirNodo(nodo *arbol){
	if(arbol != NULL){
		cout<<" "<<arbol->dato<<" ";
	}
}

void preOrden(nodo *arbol){
	if(arbol != NULL){
		imprimirNodo(arbol);
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void inOrden(nodo *arbol){
	if(arbol != NULL){
		inOrden(arbol->izq);
		imprimirNodo(arbol);
		inOrden(arbol->der);
	}
}

void postOrden(nodo *arbol){
	if(arbol != NULL){
		postOrden(arbol->izq);
		postOrden(arbol->der);
		imprimirNodo(arbol);
	}
}

void busqueda(nodo *arbol,int n){
	if(arbol == NULL){
		cout<<n<<" No se encuentra"<<endl;
	}
	else if(arbol->dato == n){
		cout<<n<<" Si se encuentra"<<endl;
	}
	else if(n < arbol->dato){
		busqueda(arbol->izq,n);
	}
	else{
		busqueda(arbol->der,n);
	}
}

int main(){
	nodo *arbol = NULL;
	insertarNodo(arbol,8);
	insertarNodo(arbol,3);
	insertarNodo(arbol,6);
	insertarNodo(arbol,1);
	insertarNodo(arbol,4);
	insertarNodo(arbol,7);
	insertarNodo(arbol,10);
	insertarNodo(arbol,14);
	insertarNodo(arbol,13);
	preOrden(arbol);
	cout<<endl;
	inOrden(arbol);
	cout<<endl;
	postOrden(arbol);
	cout<<endl;
	busqueda(arbol,1);
	return 0;
}
