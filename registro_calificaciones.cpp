#include <iostream>
#include <iomanip>
#include "datos.h"

// Opción 2

void registrarCalificaciones() {
    if (totalEstudiantes == 0) {
        cout << "\nPrimero debe registrar estudiantes.\n";
        return;
    }

    string codigo = leerTexto("Código del estudiante: ");
    int pos = buscarEstudiante(codigo);
    if (pos == -1) {
        cout << "No se encontró un estudiante con ese código.\n";
        return;
    }

    cout << "Estudiante: " << nombres[pos] << "\n";
    for (int j = 0; j < NUM_NOTAS; j++) {
        notas[pos][j] = leerDecimal("Nota " + to_string(j + 1) + ": ", NOTA_MIN, NOTA_MAX);
    }
    promedios[pos] = calcularPromedio(pos);
    notasRegistradas[pos] = true;

    cout << "Calificaciones registradas correctamente.\n";
}