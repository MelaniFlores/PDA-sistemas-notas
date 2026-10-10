#ifndef DATOS_H
#define DATOS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

// 
const int MAX_ESTUDIANTES = 50;
const int NUM_NOTAS = 3;
const double NOTA_MIN = 0.0;
const double NOTA_MAX = 10.0;
const double NOTA_APROBACION = 6.0;   // 6 o mas es aprobado

// los datos de cada estudiante
struct Estudiante {
    string codigo;
    string nombre;
    double notas[NUM_NOTAS];
    double promedio;
    string estado;             // "Aprobado" o "Reprobado"
    bool notasRegistradas;     // false mientras no le hayan puesto las notas
};

// funciones de utilidades.cpp 
int leerEntero(const string& mensaje, int minimo, int maximo);
double leerDecimal(const string& mensaje, double minimo, double maximo);
string leerTexto(const string& mensaje);
int buscarEstudiante(const Estudiante estudiantes[], int total, const string& codigo);  // devuelve -1 si no existe
double calcularPromedio(const Estudiante& e);
string determinarEstado(double promedio);
void pausar();
void limpiarPantalla();

// funciones del menu
void registrarEstudiantes(Estudiante estudiantes[], int& totalEstudiantes);            // opcion 1
void registrarCalificaciones(Estudiante estudiantes[], int totalEstudiantes);          // opcion 2
void consultarPromedio(const Estudiante estudiantes[], int totalEstudiantes);          // opcion 3
void consultarEstadoAcademico(const Estudiante estudiantes[], int totalEstudiantes);   // opcion 4
void reporteGeneralEstudiantes(const Estudiante estudiantes[], int totalEstudiantes);  // opcion 5
void mejorYPeorEstudiante(const Estudiante estudiantes[], int totalEstudiantes);       // opcion 6
void estadisticasAcademicas(const Estudiante estudiantes[], int totalEstudiantes);     // opcion 7

#endif
