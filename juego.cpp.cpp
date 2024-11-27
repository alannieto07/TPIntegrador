/* errores a corregir:
los vectores no pueden contener el numero de una variable entera, kloster nos va a matar

agregar:
modo de numeros manuales
modo 2 jugadores
limpiar pantalla y luego mostrar vector mas alto

funcion:
tabla de puntajes (que identifique el mejor puntaje) por referencia en teoria
para guardar un vector de mayor tirada
*/
typedef unsigned char byte;
#include <cstdint>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include"juego.h"
#include "rlutil.h"
using namespace std;

// INTERFAZ PANTALLA ENTRE TURNOS
void pantallaEntreTurnos(int ronda, const string& jugadorActual, int puntaje) {
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
    cout << "PROXIMO TURNO: " << jugadorActual;

    rlutil::locate(posX + 5, posY + 5);
    cout << "PUNTAJE " << jugadorActual << " : " << puntaje << " PUNTOS";

    // frase fuera del cuadro
    rlutil::locate(posX + 1, posY + alto + 1);
    cout << "PRESIONAR UNA TECLA PARA CONTINUAR...";

    rlutil::anykey();
    rlutil::cls();
    rlutil::showcursor();
}
// INTERFAZ SOLICITAR NOMBRE
string solicitarNombreJugador() {
    rlutil::cls();
    string nombreJugador;


    cout << "                                === INGRESA TU NOMBRE PARA COMENZAR ===" << endl;
    cout << "                                    Nombre del jugador: ";
    cin >> nombreJugador;

    rlutil::setColor(rlutil::WHITE);
    cout << "\n\n\n\n\n\n\n\t                              Que comience tu juego, " << nombreJugador << "!\n" << endl;
    rlutil::anykey();
    rlutil::cls();
    return nombreJugador;
}
void mostrarMensajeVictoria(const string& nombreJugador, int puntaje) {
    rlutil::cls();
    rlutil::hidecursor();

    int posX = 5, posY = 2;

    // caja bordes
// Caja bordes
rlutil::locate(posX, posY);         cout << "**************************************";
rlutil::locate(posX, posY + 1);     cout << "*  FELICIDADES "<< nombreJugador <<" *";
rlutil::locate(posX, posY + 2);     cout << "*  Has ganado con:                   *";
rlutil::locate(posX, posY + 3);     cout << "*  " << puntaje << " puntos          *";
rlutil::locate(posX, posY + 4);     cout << "***********************************";


    // Mensaje para continuar
    rlutil::locate(posX, posY + 6);
    cout << "Presiona cualquier tecla para salir...";

    rlutil::anykey();

    rlutil::cls();
    rlutil::showcursor();
}



void ModoUnJugador(int &puntajeMaximo, string &nombreMaximo)
{

    int puntaje = 0;
    int ronda = 1;
    //int puntaje,ronda,rondaactual;
    bool salir; ///variable q si es true va a anular el resto de tiradas (por si sale escalera o sexteto de seis)
    salir=false;
    bool esc,encont,seis;
    int maxpuntosdetirada/*mayor puntaje de entre todas las tiradas*/,tirada/*cantidad de tiradas*/,sumadetirada/*suma de una tirada*/, vectormejortirada[6]{}/*se guarda la tirada de dados mas alta*/;
    ronda=1;
    puntaje=0;
    maxpuntosdetirada=0;
    //string nombreJugador;
    //cout<< "Ingresa el nombre del jugador: ";
    //cin >>nombreJugador;
    string nombreJugador = solicitarNombreJugador();
    cout<<endl<< "Que Comience tu juego " <<nombreJugador<<"..."<<endl<<endl;

    while(puntaje<=99 && !salir)
    {
       int rondaactual=ronda;
        maxpuntosdetirada=0;

        // Mostrar la pantalla "Entre turnos" antes de cada ronda
        pantallaEntreTurnos(ronda, nombreJugador, puntaje);

        while(rondaactual==ronda)
        {   cout<<"TU PUNTAJE  ES DE: "<<puntaje<<endl;
            tirada=0;
            while(tirada<3||salir==true){
            tirada++;
            cout<<endl<<" RONDA Numero "<<ronda<<endl;
            cout<<" LANZAMIENTO Numero "<<tirada<<endl;
            int tamanio=6;/*cantidad de dados*/
            int v[tamanio]; /*vector con cada dado*/

            cargarAleatorio(v,tamanio);
            mostrarVector(v,tamanio);
            cout<<endl;
            esc= Escalera(v,tamanio);
            seis=SeisSeis(v,tamanio);
            encont=encontrarsexteto(v,tamanio);
            if(esc==true){salir=true; puntaje+=100; cout<<"FELICIDADES :) ,sacaste escalera y acabas de ganar el juego"<<endl; }
            //mostrarMensajeVictoria(nombreJugador1, puntaje);
            if(seis==true){salir=true; puntaje=0; cout<<"MALA SUERTE :( ,sacaste el sexteto de SEIS tu puntaje se reinicia a 0"<<endl; }
            if(encont==true)
            {
               sumadetirada=puntajedeunsexteto(v,tamanio);

            } else{ sumadetirada=SumaDedados(v,tamanio);}

            cout<<endl<<"PUNTAJE DE ESTA TIRADA: "<<sumadetirada<<endl;
                if(maxpuntosdetirada==0)
                {
                    maxpuntosdetirada=sumadetirada;
                }else if(sumadetirada>=maxpuntosdetirada){maxpuntosdetirada=sumadetirada;}
             system("pause");
             /*system ("cls");
             cout<<endl<<vectormejortirada;
             system ("pause");*/

            if(tirada==3)
                {
                    cout<<endl;
                    system("pause");
                    system ("cls");
                    ronda++;
                }
            }
        }
        puntaje+=maxpuntosdetirada;
   }

   cout<<"FELICIDADES "<<nombreJugador<<" GANASTE EL JUEGO CON "<<puntaje<<" PUNTOS!!"<<endl;
    mostrarMensajeVictoria(nombreJugador, puntaje);

     // Actualizar la puntuación máxima si este puntaje es superior
    if (puntaje > puntajeMaximo) {
        puntajeMaximo = puntaje;
        nombreMaximo = nombreJugador;
    }
   system ("pause");
}

bool simular ()
{
  bool simulacion;
  int opc;
  cout<<"quiere activar el modo simulado"<<endl;
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



//CARGA MANUAL DEL VECTOR
void CargaManualVector(int v[], int tam){
    cout<<"carga manual de vector "<<endl;

    for(int x=0;x<tam;x++){
        cin>> v[x];
    }

}

///carga numeros al azar
void cargarAleatorio(int v[], int tam)
 {
    int limite=6;
    srand(time(NULL));
    for(int i=0; i<tam; i++ )
    {
        v[i]=(rand()%limite)+1;
    }
 }

 //muestra vector
void mostrarVector(int v[], int tam)
 {
    for(int i=0; i<tam; i++)
    {
        cout<<v[i]<<"\t";
    }
 }

 //SUMA LOS VALORES DE LOS DADOS
int SumaDedados(int v[],int tam)
 {
    int suma=0;
    for(int x=0;x<tam;x++)
    {
        suma+=v[x];
    }
    return suma;
}

///corrobora si el jugador saco en el dado, 6 veces el numero 6
bool SeisSeis (int v[],int tam)
{
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

//CORROBORA SI HAY ESCALERA
bool Escalera(int v[],int tam)
        {
            int seis = 6;
            int Escalera[seis]= {1,2,3,4,5,6};
            int cont=0;
            bool esc=false;

            for(int x=0; x<tam; x++)    //Recorre ambos vectores y analiza si tienen los mismos numeros
            {
                if(v[x]==Escalera[x])
                {
                    cont++;
                }
            }

            if(cont==6)    //si el contador llega a 6 es escalera
            {
                esc=true;
            }

            return esc;
        }

///pregunta si todos los numeros son iguales pero diferentes al numero seis
bool encontrarsexteto(int v[], int tam)
{
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
int puntajedeunsexteto(int v[], int tam)
{   int suma;

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


