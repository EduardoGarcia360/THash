#ifndef TABLAHASH_H
#define TABLAHASH_H

typedef struct TablaHash TablaHash;

struct TablaHash{
    int funcionHash(int llv, int M);
    int dobleDispersion(int llv, int i);
    void insertar(int d);
    void mostrar();
};

#endif // TABLAHASH_H
