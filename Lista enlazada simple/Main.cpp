#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
	int dato;
	nodo *sgte;
};

//insertar de forma ascendente los datos
void listaInsertar(nodo *&lista,int n){
	nodo *nuevo = new nodo();
	nuevo->dato = n;
	nodo *aux = lista; //lista  siempre apunta al inicio,si esta vacia apunta a NULL
	nodo *aux2; //siempre apunta al final,solo sirve para agregar nodos mayores al dato
	
	while((aux!=NULL) && (aux->dato<n)){
		aux2 = aux;
		aux = aux->sgte;
	}

	if(lista == aux){
		lista = nuevo;
	}
	else{
		aux2->sgte = nuevo;
	}
	nuevo->sgte = aux;
}

void listaMostrar(nodo *lista){
	while(lista->sgte!=NULL){
		cout<<lista->dato<<"->";
		lista = lista->sgte;
	}
	cout<<lista->dato<<"->||\n";
}

void listaBuscar(nodo *lista,int n){
	bool encontrado = false;
	while((lista != NULL) && (lista->dato <= n)){
		if(lista->dato == n){
			encontrado = true;
			break;
		}
		lista = lista->sgte;
	}
	if(encontrado){
		cout<<n<<" si esta en la lista"<<endl;
	}
	else{
		cout<<n<<" no esta en la lista"<<endl;
	}
}

void listaEliminarNodo(nodo *&lista,int n){
	if(lista != NULL){
		nodo *aux;
		nodo *anterior = NULL;
		aux = lista;
		while((aux!=NULL) && (aux->dato != n)){
			anterior = aux;
			aux = aux->sgte;
		}
		if(aux == NULL){
			cout<<"El elemento no esta en la lista"<<endl;;
		}
		else if(anterior == NULL){
			lista = lista->sgte;
			delete aux;
		}
		else{
			anterior->sgte = aux->sgte;
			delete aux;
		}
	}
}

int main(){
	nodo *Lista = NULL;
	listaInsertar(Lista,3);
	listaInsertar(Lista,2);
	listaInsertar(Lista,4);
	listaMostrar(Lista);
	return 0;
}
