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
bool Escalera(int v[],int tam);
bool encontrarsexteto (int v[], int tam);
int puntajedeunsexteto(int v[], int tam);
void ModoUnJugador(int &puntajeMaximo, std::string &nombreMaximo);
//void ModoSimulado(int &puntajeMaximo, std::string &nombreMaximo);
//void CargaManualVector(int v[], int tam);
bool simular();

