#include <QCoreApplication>
#include "tablahash.h"

using namespace std;

TablaHash* mitabla = (TablaHash*)malloc(sizeof(TablaHash));

int main()
{

    mitabla->insertar(15);
    mitabla->insertar(26);
    mitabla->insertar(29);
    mitabla->insertar(2);
    mitabla->insertar(18);
    mitabla->insertar(28);
    mitabla->modificar(29, 40);
    mitabla->mostrar();
    mitabla->graficar();

}
