#include <iostream>
using namespace std;
#include"juego.h"
#include "rlutil.h"
#include <string>

void mostrarPuntuacionMasAlta(int puntajeMaximo, const string &nombreMaximo) {
    if (puntajeMaximo > 0) {
        cout << "---------------------------------" << endl;
        cout << "PUNTUACION MAS ALTA" << endl;
        cout << "Jugador: " << nombreMaximo << endl;
        cout << "Puntaje: " << puntajeMaximo << " puntos" << endl;
        cout << "---------------------------------" << endl;
    } else {
        cout << "No se ha registrado ningun puntaje alto en esta sesion." << endl;
    }
}

/// muestra opciones y te deja seleccionar una opcion
    int seleccionarOpcion(){

    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::WHITE);
    int posX = 35, posY = 5;

    rlutil::locate(posX, posY);     cout << "-----------------------------------------";
    rlutil::locate(posX, posY + 1); cout << " === Juego de Dados: CIEN o Escalera ===";
    rlutil::locate(posX, posY + 2); cout << "-----------------------------------------";
    rlutil::locate(posX, posY + 3); cout << "1. Juego nuevo para UN jugador";
    rlutil::locate(posX, posY + 4); cout << "2. Juego nuevo para DOS jugadores";
    rlutil::locate(posX, posY + 5); cout << "3. Mostrar la puntuacion mas alta";
    //rlutil::locate(posX, posY + 6); cout << "4. Modo simulado";
    rlutil::locate(posX, posY + 7); cout << "0. Salir";
    rlutil::locate(posX, posY + 8); cout << "-----------------------------------------";
    rlutil::locate(posX, posY + 9); cout << "Seleccione su opcion para continuar: ";
    int op;
    cout <<endl;
    rlutil::locate(posX + 37, posY + 9); cin  >>op;
    cout <<endl;
    rlutil::cls();
    return op;
}

///switch parte codigo (ejecuta)
void mostrarMenu(int opcion, int &puntajeMaximo, string &nombreMaximo){ // agregue por ref las dos varibles
        switch(opcion)
        {

        case 1:
            ModoUnJugador(puntajeMaximo, nombreMaximo);
            system ("cls");
            break;

        case 2:

            system ("cls");
            break;

        case 3:
            mostrarPuntuacionMasAlta(puntajeMaximo, nombreMaximo);
            system ("pause");
            system ("cls");
            break;

        case 4:
               //ModoSimulado(puntajeMaximo, nombreMaximo);
               system ("cls");
               break;

        case 0:
            cout<<endl<<endl<< "MUCHAS GRACIAS POR UTILIZAR NUESTRO JUEGO!!!" <<endl<<endl;
            system("pause");
            system ("cls");
            break;

        default:
                   int posX= 5, posY = 2;
                   rlutil::locate(posX + 6, posY + 1); cout << "**********************" << endl;
                   rlutil::locate(posX + 6, posY + 2); cout << "*  OPCION NO VALIDA  *" << endl;
                   rlutil::locate(posX + 6, posY + 3); cout << "*  INTENTA DE NUEVO  *" << endl;
                   rlutil::locate(posX + 6, posY + 4); cout << "**********************" << endl<<endl;
                system("pause");
                system ("cls");
        }


}
