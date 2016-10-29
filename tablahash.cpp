#include "tablahash.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "iostream"
#include "sstream"
#include "fstream"
#include "QString"
#include "cstdlib"

using namespace std;

/*tamaño ya definido en el proyecto*/
QString tabla[13];
double llenado;

void TablaHash::insertar(int d){
    int indice = funcionHash(d, 13);
    int iteracion=1, primero=indice;
    /*en caso de haber una colision*/
    while(tabla[indice]!="#" && tabla[indice]!=NULL){
        int colision = dobleDispersion(d, iteracion);
        indice=0;
        indice= primero+colision;
        iteracion++;
        colision=0;
    }
    tabla[indice]=QString::number(d);
    llenado += 1.0;
}

QString TablaHash::buscar(int d){

    int indice=funcionHash(d, 13);
    QString elemento = QString::number(d), retorno="";

    if(tabla[indice] == elemento){
        /*no hubo colision*/
        retorno = tabla[indice];
    }else{
        /*si hubo colision*/
        int iteracion=1, primero=indice;
        while(tabla[indice]!=elemento){
            int colision = dobleDispersion(d, iteracion);
            indice=0;
            indice=primero + colision;
            if(indice>=13){
                /*no encontro el numero, y sobrepaso el tamaño maximo*/
                break;
            }else{
                iteracion++;
                colision=0;
            }
        }
        if(indice<13){
            retorno = tabla[indice];
        }
    }

    return retorno;
}

bool TablaHash::eliminar(int d){
    bool elimino=false;
    int indice=funcionHash(d, 13);

    QString elemento = QString::number(d);

    if(tabla[indice] == elemento){
        /*no hubo colision*/
        tabla[indice]="#";
        llenado -= 1.0;
        elimino=true;
    }else{
        /*si hubo colision*/
        int iteracion=1, primero=indice;
        while(tabla[indice]!=elemento){
            int colision = dobleDispersion(d, iteracion);
            indice=0;
            indice=primero + colision;
            if(indice>=13){
                /*no encontro el numero, y sobrepaso el tamaño maximo*/
                break;
            }else{
                iteracion++;
                colision=0;
            }
        }
        if(indice<13){
            tabla[indice]="#";
            llenado -= 1.0;
            elimino=true;
        }
    }
    return elimino;
}

void TablaHash::modificar(int d, int n){
    int indice=funcionHash(d, 13);

    QString elemento = QString::number(d);

    if(tabla[indice] == elemento){
        /*no hubo colision*/
        tabla[indice]=QString::number(n);
    }else{
        /*si hubo colision*/
        int iteracion=1, primero=indice;
        while(tabla[indice]!=elemento){
            int colision = dobleDispersion(d, iteracion);
            indice=0;
            indice=primero + colision;
            if(indice>=13){
                /*no encontro el numero, y sobrepaso el tamaño maximo*/
                break;
            }else{
                iteracion++;
                colision=0;
            }
        }
        if(indice<13){
            tabla[indice]=QString::number(n);
        }
    }
}

void TablaHash::mostrar(){
    cout<<"====================="<<endl;
    for(int i=0; i<13; i++){
        if(tabla[i] == NULL || tabla[i] == "#"){
            QString tmp = "pos: "+QString::number(i)+" vacia.";
            cout<<tmp.toStdString()<<endl;
        }else{
            QString tmp = "pos: "+QString::number(i)+"->"+tabla[i];
            cout<<tmp.toStdString()<<endl;
        }
    }
    cout<<"====================="<<endl;
}

void TablaHash::graficar(){
    /*ver ejemplo en el manual de graphviz pag. 24*/

    QString encabezado="digraph G{\n nodesep=.05;\n rankdir=LR;\n node[shape=record,width=.1,height=.1];\n";
    QString cuerpo="";
    QString relacion="", nodocero="node0 [label = \"";
    int n=1;
    for(int i=0; i<13; i++){
        nodocero += "<f"+QString::number(i)+">"+QString::number(i)+" |";
        if(tabla[i]!=NULL && tabla[i]!="#"){
            QString dato = tabla[i];
            cuerpo += "node"+QString::number(n)+"[label=\"{<n> "+dato+" | 5 | 6}\"];\n ";
            int ant = n - 1;
            relacion += "node0:f"+QString::number(ant)+" -> node"+QString::number(n)+":n;\n ";
        }
        n += 1;
    }
    nodocero += "\", height=2.5];\n node[width = 1.5];\n ";
    /*=================================*/

    QString contenido = encabezado + nodocero + cuerpo + relacion + "\n}";

    ofstream escritura;
    escritura.open("/home/eduardo/Descargas/tablahash.dot", ios::out);
    if(escritura.is_open()){
        cout<<"abrio el archivo"<<endl;
        escritura<<contenido.toStdString()<<endl;
    }else{
        cout<<"nell prro"<<endl;
    }
    escritura.close();
    system("dot -Tpng /home/eduardo/Descargas/tablahash.dot -o /home/eduardo/tablahash.png");
}

double TablaHash::porcentajeLlenado(){
    return llenado/13.0;
}

int TablaHash::funcionHash(int llv, int M){
    int mod = llv%M;
    return mod;
}

int TablaHash::dobleDispersion(int llv, int i){
    return (((llv%7)+1)*i);
}
