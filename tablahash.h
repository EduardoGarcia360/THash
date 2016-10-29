#ifndef TABLAHASH_H
#define TABLAHASH_H
#include "QString"

typedef struct TablaHash TablaHash;

struct TablaHash{
    //QString tabla[13];
    double llenado;
    int funcionHash(int llv, int M);
    int dobleDispersion(int llv, int i);
    double porcentajeLlenado();
    void insertar(int d);
    void mostrar();
    QString buscar(int d);
    bool eliminar(int d);
    void modificar(int d, int n);
    void graficar();
};
#endif // TABLAHASH_H
