#pragma once
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include "rlutil.h"
#include <string>

void cargarAleatorio(int v[], int tam);
void mostrarVector(int v[], int tam);
int SumaDedados(int v[],int tam);
bool SeisSeis (int v[],int tam);
void VectorEn0(int v[],int tam);
bool Escalera(int v[]);
bool encontrarsexteto (int v[], int tam);
int puntajedeunsexteto(int v[], int tam);
void ModoUnJugador(int &puntajeMaximo, std::string &nombreMaximo);
void ModoDosJugadores(int &puntajeMaximo, std::string &nombreMaximo);
void CargaManualVector(int v[], int tam);
bool simular();
void dibujarDado(int valor, int posX, int posY);
void dibujarDados(int valores[], int cantidad, int posX, int posY);
//void solicitarNombresJugadores(std::string &nombreJugador1, std::string &nombreJugador2);
