#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
	int dato;
	nodo *sgte;
};

//Agregar elemento a la pila = PUSH
//se pasa un puntero por referencia con *&
void push(nodo *&pila,int n){
	nodo *nuevo = new nodo();
	nuevo->dato = n;
	nuevo->sgte = pila;
	pila = nuevo;
}

//quitar elemento de la pila = POP
void pop(nodo *&pila){
	nodo *aux;
	aux = pila;
	pila = pila->sgte;
	delete aux;
}

void mostrar(nodo *pila){
	cout<<"P->";
	while(pila->sgte!=NULL){
		cout<<pila->dato<<"->";
		pila = pila->sgte;
	}
	cout<<pila->dato<<"->||\n";
}

int main(){
	nodo *Pila = NULL;
	push(Pila,4);
	push(Pila,3);
	push(Pila,2);
	mostrar(Pila);
	pop(Pila);
	mostrar(Pila);
	push(Pila,9);
	mostrar(Pila);
	return 0;
}
