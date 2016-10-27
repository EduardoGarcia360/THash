#include <QCoreApplication>
#include "iostream"
#include "arbolavl.h"
#include "listadc.h"
#include "tablahash.h"
#include "string.h"
#include "cstdlib"
#include "iostream"
#include "fstream"
#include "cstdlib"
#include "QString"

using namespace std;

TablaHash* mitabla = (TablaHash*)malloc(sizeof(TablaHash));
//ArbolAVL* miarbol= (ArbolAVL*)malloc(sizeof(ArbolAVL));
//ListaDC* milista= (ListaDC*)malloc(sizeof(ListaDC));

int main()
{

    mitabla->insertar(15);
    mitabla->insertar(26);
    mitabla->insertar(29);
    mitabla->insertar(2);
    mitabla->insertar(18);
    mitabla->insertar(28);
    mitabla->mostrar();

    /*
    miarbol->insertar(10);
    miarbol->insertar(5);
    miarbol->insertar(13);
    miarbol->insertar(1);
    miarbol->insertar(6);
    miarbol->insertar(17);
    miarbol->insertar(16);
    NodoAVL* raiz = miarbol->obtenerRaiz();
    miarbol->preOrden(raiz);
    cout<<"============="<<endl;
    if(miarbol->eliminar(10)){
        NodoAVL* raiz = miarbol->obtenerRaiz();
        miarbol->preOrden(raiz);
    }else{
        cout<<"el papu"<<endl;
    }
    **/
    /*
    milista->insertar(5);
    milista->insertar(10);
    milista->insertar(20);
    milista->insertar(30);
    milista->insertar(50);
    if(!milista->estaVacia()){
        milista->mostrarLista();
    }
    bool e=false;
    e=milista->eliminar(20);
    if(e){
        milista->mostrarLista();
    }else{
        cout<<"nel papu"<<endl;
    }
    **/
}
