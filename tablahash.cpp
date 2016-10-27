#include "tablahash.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "iostream"
#include "sstream"

using namespace std;

/*variable global que nos ayudara a definir el tamanio de la tabla*/
int tamanio=0;

NodoTabla::NodoTabla(int dato){
    this->dato = dato;
    this->indice=NULL;
    this->siguiente=NULL;
}

void TablaHash::definirTam(int tam){
    tamanio = tam;
}

void TablaHash::insertar(int d){
    int indice = funcionHash(d, tamanio);
    NodoTabla* nuevo = new NodoTabla(d);
    nuevo->indice = indice;
    cout<<"dato: "<<endl;
    cout<<indice<<endl;
    cout<<"dato: "<<endl;
    cout<<d<<endl;
    if(inicio==NULL){
        inicio=nuevo;
    }else{
        int itera=1, colision=0;
        NodoTabla* actual = inicio;
        if(actual->indice > nuevo->indice){

        }else if(actual->indice < nuevo->indice){

        }else{
            //colision
            while(actual->indice!=nuevo->indice){
                colision = dobleDispersion(d, itera);
                actual = actual->siguiente;
                int tmp = actual->indice;

            }
        }
    }

}

int TablaHash::funcionHash(int llv, int M){
    return llv%M;
}

int TablaHash::dobleDispersion(int llv, int i){
    return (((llv%7)+1)*i);
}
