#ifndef TABLAHASH_H
#define TABLAHASH_H

typedef struct TablaHash TablaHash;

struct TablaHash{
    int funcionHash(int llv, int M);
    int dobleDispersion(int llv, int i);
    double porcentajeLlenado();
    void insertar(int d);
    void mostrar();
    bool buscar(int d);
    bool eliminar(int d);
};

#endif // TABLAHASH_H
