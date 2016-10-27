#include "tablahash.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "iostream"
#include "sstream"
#include "QString"

using namespace std;

/*tamaño ya definido en el proyecto*/
QString tabla[13];

void TablaHash::insertar(int d){
    int indice = funcionHash(d, 13);
    int iteracion=1, colision=0;
    while(tabla[indice]!=NULL){
        colision = dobleDispersion(d, iteracion);
        int tmp = indice;
        indice=0;
        indice=tmp+colision;
        iteracion++;
    }

    tabla[indice]=QString::number(d);
}

void TablaHash::mostrar(){
    cout<<"====================="<<endl;
    for(int i=0; i<13; i++){
        if(tabla[i] == NULL){
            QString tmp = "pos: "+QString::number(i)+" vacia.";
            cout<<tmp.toStdString()<<endl;
        }else{
            QString tmp = "pos: "+QString::number(i)+"->"+tabla[i];
            cout<<tmp.toStdString()<<endl;
        }
    }
    cout<<"====================="<<endl;
}

int TablaHash::funcionHash(int llv, int M){
    int mod = llv%M;
    return mod;
}

int TablaHash::dobleDispersion(int llv, int i){
    return (((llv%7)+1)*i);
}
