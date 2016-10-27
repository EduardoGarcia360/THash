#ifndef TABLAHASH_H
#define TABLAHASH_H
#include "QString"

typedef struct NodoTabla NodoTabla;
typedef struct TablaHash TablaHash;

struct NodoTabla{
    int dato;
    NodoTabla(int dato);
};

struct TablaHash{
    int funcionHash(int llv, int M);
    int dobleDispersion(int llv, int i);
    void insertar(int d);
    void mostrar();
};

#endif // TABLAHASH_H
