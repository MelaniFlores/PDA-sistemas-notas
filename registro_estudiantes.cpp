#include <iostream>
#include <iomanip>
#include "datos.h"

// Opción 1

void registrarEstudiantes() {
    if (totalEstudiantes >= MAX_ESTUDIANTES) {
        cout << "\nSe alcanzó el límite de estudiantes.\n";
        return;
    }

    string codigo = leerTexto("Código del estudiante: ");
    if (codigo.empty()) {
        cout << "El código es obligatorio.\n";
        return;
    }
    if (buscarEstudiante(codigo) != -1) {
        cout << "Ya existe un estudiante con ese código.\n";
        return;
    }

    string nombre = leerTexto("Nombre del estudiante: ");
    if (nombre.empty()) {
        cout << "El nombre es obligatorio.\n";
        return;
    }

    int i = totalEstudiantes;
    codigos[i] = codigo;
    nombres[i] = nombre;
    for (int j = 0; j < NUM_NOTAS; j++) notas[i][j] = 0;
    promedios[i] = 0;
    notasRegistradas[i] = false;
    totalEstudiantes++;

    cout << "Estudiante registrado correctamente.\n";
}