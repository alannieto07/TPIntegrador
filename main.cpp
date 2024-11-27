typedef unsigned char byte;
#include <iostream>
#include <cstdint>
#include "menu.h"
#include "juego.h"
#include "rlutil.h"
using namespace std;

int main()
{
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::WHITE);
    srand(time(NULL));
    rlutil::cls();
    cout<<"                                             | BIENVENIDO/S | "<<endl;

    int opcion;
    int puntajeMaximo = 0;
    string nombreJugador;
    string nombreMaximo = "";

    do
    {
        opcion=seleccionarOpcion();
        mostrarMenu(opcion, puntajeMaximo, nombreMaximo);
    }
    while (opcion!=0);
    return 0;
}
