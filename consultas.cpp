#include <iostream>
#include <iomanip>
#include "datos.h"

// Opciones 3 y 4

void consultarPromedio() {
    if (totalEstudiantes == 0) {
        cout << "\nNo hay estudiantes registrados.\n";
        return;
    }

    string codigo = leerTexto("Código del estudiante: ");
    int pos = buscarEstudiante(codigo);
    if (pos == -1) {
        cout << "No se encontró un estudiante con ese código.\n";
        return;
    }
    if (!notasRegistradas[pos]) {
        cout << "Este estudiante aún no tiene calificaciones registradas.\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\nEstudiante: " << nombres[pos] << " (" << codigos[pos] << ")\n";
    cout << "Notas: ";
    for (int j = 0; j < NUM_NOTAS; j++) {
        cout << notas[pos][j] << (j < NUM_NOTAS - 1 ? " | " : "\n");
    }
    cout << "Promedio final: " << promedios[pos] << "\n";
}

void consultarEstado() {
    if (totalEstudiantes == 0) {
        cout << "\nNo hay estudiantes registrados.\n";
        return;
    }

    string codigo = leerTexto("Código del estudiante: ");
    int pos = buscarEstudiante(codigo);
    if (pos == -1) {
        cout << "No se encontró un estudiante con ese código.\n";
        return;
    }
    if (!notasRegistradas[pos]) {
        cout << "Este estudiante aún no tiene calificaciones registradas.\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\nEstudiante: " << nombres[pos] << " (" << codigos[pos] << ")\n";
    cout << "Promedio: " << promedios[pos] << "\n";
    cout << "Estado académico: " << estadoAcademico(promedios[pos]) << "\n";
}