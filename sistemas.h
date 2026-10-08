#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
using namespace std;

const int MAX = 50;

extern string codigos[MAX], nombres[MAX];
extern double n1[MAX], n2[MAX], n3[MAX], promedios[MAX];
extern bool tieneNotas[MAX];
extern int total;

int buscarEstudiante(const string& codigo);
void registrarEstudiante();
void registrarCalificaciones();
void consultarPromedio();

#endif