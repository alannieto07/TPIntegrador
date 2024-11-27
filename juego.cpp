
typedef unsigned char byte;
#include <cstdint>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include"juego.h"
#include "rlutil.h"
using namespace std;

// INTERFACES

void pantallaEntreTurnos(int ronda, string jugadorActual, int puntaje) {
    rlutil::cls();
    rlutil::hidecursor();
    int posX = 5, posY = 2;
    int ancho = 40, alto = 8;

    // caja
    rlutil::locate(posX, posY);         cout << char(218);
    rlutil::locate(posX + ancho, posY); cout << char(191);
    rlutil::locate(posX, posY + alto);  cout << char(192);
    rlutil::locate(posX + ancho, posY + alto); cout << char(217);

    // Dibuja los bordes horizontales
    for (int i = posX + 1; i < posX + ancho; i++) {
        rlutil::locate(i, posY); cout << char(196); //linea superior
        rlutil::locate(i, posY + alto); cout << char(196); //linea inferior
    }

    // Dibuja los bordes verticales
    for (int i = posY + 1; i < posY + alto; i++) {
        rlutil::locate(posX, i); cout << char(179); //linea izquierda
        rlutil::locate(posX + ancho, i); cout << char(179); //linea derecha
    }

    // info denmtro de la caja
    rlutil::locate(posX + 5, posY + 2);
    cout << "RONDA Numero " << ronda;

    rlutil::locate(posX + 5, posY + 3);
    cout << "PROXIMO TURNO DE JUGADOR: " << jugadorActual;

    rlutil::locate(posX + 5, posY + 5);
    cout << "PUNTAJE " << jugadorActual << " : " << puntaje << " PUNTOS";

    // frase fuera del cuadro
    rlutil::locate(posX + 1, posY + alto + 1);
    cout << "PRESIONAR UNA TECLA PARA CONTINUAR...";

    rlutil::anykey();
    rlutil::cls();
}

string solicitarNombreJugador() {

    rlutil::cls();
    cout<<endl<<endl;
    string nombreJugador;


    cout << "                                === INGRESA TU NOMBRE PARA COMENZAR ===" << endl;
    cout << "                                    Nombre del jugador: ";
    cin >> nombreJugador;

    rlutil::setColor(rlutil::WHITE);
    cout << "\n\n\n\n\n\n\n\t                              Que comience tu juego, " << nombreJugador << "!\n" << endl;
    rlutil::anykey();
    return nombreJugador;
}
///Soliticar nombres para modo DOS JUGADORES
void solicitarNombresJugadores(std::string &nombreJugador1, std::string &nombreJugador2) {
    rlutil::cls();
    cout << endl << endl;

    cout << "                                === INGRESA LOS NOMBRES PARA COMENZAR ===" << endl;

    cout << "                                    Nombre del jugador 1: ";
    cin >> nombreJugador1;

    cout << "                                    Nombre del jugador 2: ";
    cin >> nombreJugador2;

    rlutil::setColor(rlutil::WHITE);
    cout << "\n\n\n\n\n\n\n\t                              ¡Que comience el juego, "
         << nombreJugador1 << " y " << nombreJugador2 << "!" << endl;
    rlutil::anykey();
}
/// mensaje victoria para un jugador
void mostrarMensajeVictoria( string nombreJugador, int puntaje) {
    rlutil::cls();
    rlutil::hidecursor();

    int posX = 5, posY = 2;


// Caja bordes
                                    cout<<  "                FELICIDADES!!!          ";
rlutil::locate(posX, posY);         cout << "**************************************";
rlutil::locate(posX, posY + 1);     cout << "*          Has ganado con:           *" ;
rlutil::locate(posX, posY + 2);     cout << "*                                    *";
rlutil::locate(posX, posY + 3);     cout << "*            "<<puntaje<<" puntos             *";
rlutil::locate(posX, posY + 4);     cout << "**************************************";

}


/// mensaje victoria para dos jugadores
// Agregue esta funcion porque al haber dos jugadores cambian los parametros que le pasamos al ganador
void mostrarMensajeVictoriaDosJugadores(std::string nombreGanador, int puntajeGanador,
                                         std::string nombrePerdedor, int puntajePerdedor) {
    rlutil::cls();
    rlutil::hidecursor();

    int posX = 5, posY = 2;

    // Mensaje de victoria
    std::cout << "                FELICIDADES!!!          \n";
    rlutil::locate(posX, posY);         std::cout << "**************************************\n";
    rlutil::locate(posX, posY + 1);     std::cout << "*          Ganador:                  *\n";
    rlutil::locate(posX, posY + 2);     std::cout << "*          " << nombreGanador << "           *\n";
    rlutil::locate(posX, posY + 3);     std::cout << "*          Puntaje: " << puntajeGanador << "          *\n";
    rlutil::locate(posX, posY + 4);     std::cout << "**************************************\n";

    // Agregue el msj mostrar puntaje del perdedor
    rlutil::locate(posX, posY + 6);     std::cout << "**************************************\n";
    rlutil::locate(posX, posY + 7);     std::cout << "*          Perdedor:                 *\n";
    rlutil::locate(posX, posY + 8);     std::cout << "*          " << nombrePerdedor << "           *\n";
    rlutil::locate(posX, posY + 9);     std::cout << "*          Puntaje: " << puntajePerdedor << "         *\n";
    rlutil::locate(posX, posY + 10);    std::cout << "**************************************\n";

    rlutil::anykey();
    rlutil::cls();
}

//MODOS
void ModoUnJugador(int &puntajeMaximo, string &nombreMaximo)
{

    int puntaje = 0;
    int ronda = 1;
    bool gano;  ///variable q si es true va a anular el resto de tiradas (por si sale escalera )
    gano=false;
    bool esc,combo,seis;
    int maxpuntosdetirada/*mayor puntaje de entre todas las tiradas*/,tirada/*cantidad de tiradas*/,sumadetirada/*suma de una tirada*/;
    ronda=1;
    puntaje=0;
    maxpuntosdetirada=0;

    bool sim=simular();
    string nombreJugador = solicitarNombreJugador();
    cout<<endl<< "Que Comience tu juego " <<nombreJugador<<"..."<<endl<<endl;

    while(puntaje<=99)
    {
        int rondaactual=ronda;
        maxpuntosdetirada=0;

        pantallaEntreTurnos(ronda, nombreJugador, puntaje);

        while(rondaactual==ronda&&gano==false)
        {
            cout<<"TU PUNTAJE  ES DE: "<<puntaje<<endl;
            tirada=0;
            while(tirada<3&&gano==false)
            {
                sumadetirada=0;
                tirada++;
                cout<<endl<<" RONDA Numero "<<ronda<<endl;
                cout<<" LANZAMIENTO Numero "<<tirada<<endl;
                int tamanio=6;/*cantidad de dados*/
                int v[6]; /*vector con cada dado*/
                cout<<endl;

                if(sim==false)
                {
                    cargarAleatorio(v,tamanio);
                    // mostrar vector y/O dados dibujados
                    mostrarVector(v,tamanio); // lo comento para probar dibujod e dados
                    //dibujarDados(v, tamanio, 10, 5); // dibuja los dados en la pantalla
                    std::cout << "\n\n";
                }
                else
                {
                    CargaManualVector(v,tamanio);
                     dibujarDados(v, tamanio, 10, 5); // dibuja los dados en la pantalla
                     std::cout << "\n\n";
                }

                esc= Escalera(v);
                seis=SeisSeis(v,tamanio);
                combo=encontrarsexteto(v,tamanio);

                if(esc==true)
                {
                    gano=true;
                    sumadetirada=100;

                    cout<<"BUENA SUERTE :) ,sacaste Escalera"<<endl;
                }
                else if(seis==true)
                {
                    tirada=3;
                    puntaje=0;
                    cout<<"MALA SUERTE :( , sacaste Sexteto de SEIS tu puntaje se reinicia a 0"<<endl;

                }
                else if(combo==true)
                {
                    sumadetirada=puntajedeunsexteto(v,tamanio);
                }
                else
                {
                    sumadetirada=SumaDedados(v,tamanio);
                }

                cout<<endl<<"PUNTAJE DE ESTA TIRADA: " "\n" <<sumadetirada <<endl;
                if(maxpuntosdetirada==0)
                {
                    maxpuntosdetirada=sumadetirada;
                }
                else if(sumadetirada>=maxpuntosdetirada)
                {
                    maxpuntosdetirada=sumadetirada;
                }

                system("pause");


                if(tirada==3)
                {
                    cout<<endl;
                    rlutil::cls();
                    ronda++;
                }
            }
        }
        puntaje+=maxpuntosdetirada;
    }

    cout<<"FELICIDADES "<<nombreJugador<<" GANASTE EL JUEGO CON "<<puntaje<<" PUNTOS!!"<<endl;
    mostrarMensajeVictoria(nombreJugador, puntaje);

    // Actualizar la puntuacion maxima si este puntaje es superior
    if (puntaje > puntajeMaximo)
    {
        puntajeMaximo = puntaje;
        nombreMaximo = nombreJugador;
    }
    cout<<endl;
    system ("pause");
}

///Modo dos jugadores
void ModoDosJugadores(int &puntajeMaximo, std::string &nombreMaximo) {

    std::string nombreJugador1, nombreJugador2;
    solicitarNombresJugadores(nombreJugador1, nombreJugador2);

    int puntajeJugador1 = 0, puntajeJugador2 = 0;
    int ronda = 1;
    bool gano = false;
    bool esc, combo, seis;
    int maxPuntosTirada, tirada, sumaTirada;

     while (!gano) {
        // turno del jugador 1
        maxPuntosTirada = 0;
        pantallaEntreTurnos(ronda, nombreJugador1, puntajeJugador1);
        tirada = 0;

        while (tirada < 3 && !gano) {
            sumaTirada = 0;
            tirada++;

            cout << "RONDA Numero " << ronda <<" JUGADOR: "<<nombreJugador1<<"\n"<<endl;
           cout << "LANZAMIENTO Numero " << tirada << "\n" <<endl;

            int v[6];
            cargarAleatorio(v, 6);
            mostrarVector(v, 6);

            esc = Escalera(v);
            seis = SeisSeis(v, 6);
            combo = encontrarsexteto(v, 6);

            if (esc) {
                sumaTirada = 100;
                puntajeJugador1 += sumaTirada;
                cout << "BUENA SUERTE :) " << nombreJugador1 << " saco Escalera y gano la partida!\n";
                gano = true;
                break;
            } else if (seis) {
                tirada = 3;
                puntajeJugador1 = 0;
                cout << "MALA SUERTE :( " << nombreJugador1 << " saco Sexteto de SEIS, su puntaje se reinicia a 0\n";
            } else if (combo) {
                sumaTirada = puntajedeunsexteto(v, 6);
            } else {
                sumaTirada = SumaDedados(v, 6);
            }

            cout <<endl << "PUNTAJE DE ESTA TIRADA: " << sumaTirada << "\n";

            if (sumaTirada > maxPuntosTirada) {
                maxPuntosTirada = sumaTirada;
            }

            system("pause");
            rlutil::cls();
        }

        puntajeJugador1 += maxPuntosTirada;

        if (puntajeJugador1 >= 100) {
            gano = true;
            break;
        }

        // turno del jugador 2
        maxPuntosTirada = 0;
        pantallaEntreTurnos(ronda, nombreJugador2, puntajeJugador2);

        tirada = 0;
        while (tirada < 3 && !gano) {
            sumaTirada = 0;
            tirada++;

           cout << "RONDA Numero " << ronda <<" JUGADOR: "<<nombreJugador2<<"\n"<<endl;
           cout << "LANZAMIENTO Numero " << tirada << "\n" <<endl;

            int v[6];
            cargarAleatorio(v, 6);
            mostrarVector(v, 6);

            esc = Escalera(v);
            seis = SeisSeis(v, 6);
            combo = encontrarsexteto(v, 6);

            if (esc) {
                sumaTirada = 100;
                puntajeJugador2 += sumaTirada;
                cout << "BUENA SUERTE :) " << nombreJugador2 << " saco Escalera y ganó la partida!\n";
                gano = true;
                break;
            } else if (seis) {
                tirada = 3;
                puntajeJugador2 = 0;
                cout << "MALA SUERTE :( " << nombreJugador2 << " saco Sexteto de SEIS, su puntaje se reinicia a 0\n";
            } else if (combo) {
                sumaTirada = puntajedeunsexteto(v, 6);
            } else {
                sumaTirada = SumaDedados(v, 6);
            }

            cout << endl << "PUNTAJE DE ESTA TIRADA: " << sumaTirada << "\n";

            if (sumaTirada > maxPuntosTirada) {
                maxPuntosTirada = sumaTirada;
            }

            system("pause");
            rlutil::cls();
        }

        puntajeJugador2 += maxPuntosTirada;

        if (puntajeJugador2 >= 100) {
            gano = true;
            break;
        }

        ++ronda;
    }

    if (puntajeJugador1 >= 100) {
        mostrarMensajeVictoriaDosJugadores(nombreJugador1, puntajeJugador1, nombreJugador2, puntajeJugador2);
    } else if (puntajeJugador2 >= 100) {
        mostrarMensajeVictoriaDosJugadores(nombreJugador2, puntajeJugador2, nombreJugador1, puntajeJugador1);
    }

    if (puntajeJugador1 > puntajeMaximo) {
        puntajeMaximo = puntajeJugador1;
        nombreMaximo = nombreJugador1;
    }
    if (puntajeJugador2 > puntajeMaximo) {
        puntajeMaximo = puntajeJugador2;
        nombreMaximo = nombreJugador2;
    }

    cout << "Fin del juego. Puntaje Final:\n"
              << nombreJugador1 << ": " << puntajeJugador1 << " puntos\n"
              << nombreJugador2 << ": " << puntajeJugador2 << " puntos\n";
}


/// dibujo de los dados
// Funciones auxiliares para dibujar dados
void dibujarDado(int valor, int posX, int posY) {
    rlutil::locate(posX, posY);         std::cout << char(218);
    rlutil::locate(posX + 7, posY);     std::cout << char(191);
    rlutil::locate(posX, posY + 3);     std::cout << char(192);
    rlutil::locate(posX + 7, posY + 3); std::cout << char(217);

    for (int i = posX + 1; i < posX + 7; i++) {
        rlutil::locate(i, posY);     std::cout << char(196);
        rlutil::locate(i, posY + 3); std::cout << char(196);
    }
    for (int i = posY + 1; i < posY + 3; i++) {
        rlutil::locate(posX, i);     std::cout << char(179);
        rlutil::locate(posX + 7, i); std::cout << char(179);
    }

    if (valor == 1 || valor == 3 || valor == 5) rlutil::locate(posX + 4, posY + 2), std::cout << char(254);
    if (valor == 2 || valor == 3 || valor == 4 || valor == 5 || valor == 6) rlutil::locate(posX + 2, posY + 1), std::cout << char(254), rlutil::locate(posX + 6, posY + 3), std::cout << char(254);
    if (valor == 4 || valor == 5 || valor == 6) rlutil::locate(posX + 2, posY + 3), std::cout << char(254), rlutil::locate(posX + 6, posY + 1), std::cout << char(254);
    if (valor == 6) rlutil::locate(posX + 2, posY + 2), std::cout << char(254), rlutil::locate(posX + 6, posY + 2), std::cout << char(254)<<endl;

}

//del video de brian
void dibujarDados(int valores[], int cantidad, int posX, int posY) {
    rlutil::cls();
    for (int i = 0; i < cantidad; i++) {
        dibujarDado(valores[i], posX + (i * 15), posY);
    }
}




// FUNCIONES
bool simular (){
  bool simulacion;
  int opc;

  cout<<"Quiere activar el modo simulado"<<endl;
  cout<<"1 - Para Si"<<endl<<"2 - Para No"<<endl;
  cin>>opc;
        switch(opc)
        {
        case 1:
            simulacion=true;
            break;
        case 2:
            simulacion=false;
            break;
        default:
            cout<<"opcion incorrecta";


        }
        rlutil::cls();
    return simulacion;
}


void CargaManualVector(int v[], int tam){
    cout<<"Carga manual de dado "<<endl;
    int numerodedado=1;

    for(int x=0;x<tam;x++){
        cout<<"dado "<<numerodedado<<": ";
        cin>> v[x];
        numerodedado++;
    }

}


void cargarAleatorio(int v[], int tam){
    int limite=6;
    for(int i=0; i<tam; i++ )
    {
        v[i]=(rand()%limite)+1;
    }
 }



void mostrarVector(int v[], int tam){
    for(int i=0; i<tam; i++)
    {
        cout<<v[i]<<"\t";
    }
 }


int SumaDedados(int v[],int tam){
///PUNTAJES
    int suma=0;
    for(int x=0;x<tam;x++)
    {
        suma+=v[x];
    }
    return suma;
}


///6 veces el numero 6
bool SeisSeis (int v[],int tam){
    int Seis[6]= {6,6,6,6,6,6};
    int cont=0;
    bool seis=false;

    ///Recorre ambos vectores y analiza si tienen los mismos numeros
    for(int x=0; x<tam; x++)
    {
        if(v[x]==Seis[x])
        {
            cont++;
        }
    }
    //si el contador llega a 6 es sexteto
    if(cont==6)
    {
        seis=true;
    }

    return seis;
}

//ESCALERA
bool Escalera(int v[]){
    bool esc = true;
    for (int i = 1; i <= 6; i++)
    {
        bool encontrado = false;

        for (int j = 0; j < 6; j++)
        {
            if (v[j] == i)
            {
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
        {
            esc = false;
            break;
        }
    }
        return esc;
}

///si los numeros son iguales pero diferentes al numero seis
bool encontrarsexteto(int v[], int tam){
  for (int x=0;x<tam;x++)
    {
        if(v[x]==6){return false;}
       for(int i=0;i<tam;i++)
        {
           if(v[i]!=v[x]){return false;}
        }
    }
    return true;
}

/// puntaje especial (numero*10)
int puntajedeunsexteto(int v[], int tam){
    int suma;

    switch(v[0])
    {
        case 1: suma=10;
                break;

        case 2: suma=20;
                break;

        case 3: suma=30;
                break;

        case 4: suma=40;
                break;

        case 5: suma=50;
                break;
    }
    return suma;
}




