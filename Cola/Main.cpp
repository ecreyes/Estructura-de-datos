#include <iostream>
#include <stdlib.h>

struct nodo{
	int dato;
	nodo *sgte;
};

//insertar en la cola
void push(nodo *&Frente,nodo *&Fin,int n){
	nodo *nuevo = new nodo();
	nuevo->dato = n;
	nuevo->sgte = NULL;
	if(Frente==NULL){
		Frente = nuevo;
	}
	else{
		Fin->sgte = nuevo;		
	}
	Fin = nuevo;
}
//eliminar de la cola
void pop(nodo *&Frente){
	nodo *aux;
	aux = Frente;
	Frente = Frente->sgte;
	delete aux;
}

void mostrar(nodo *Frente){
	printf("FRENTE->");
	while(Frente->sgte!=NULL){
		printf("%d->",Frente->dato);
		Frente = Frente->sgte;
	}
	printf("%d(FIN)->||\n",Frente->dato);
}

int main(){
	nodo *frente = NULL;
	nodo *fin = NULL;
	push(frente,fin,3);
	push(frente,fin,4);
	push(frente,fin,8);
	mostrar(frente);
	pop(frente);
	push(frente,fin,40);
	mostrar(frente);
	return 0;
}
