#include "datos.h"

// opcion 3: consultar promedio individual
void consultarPromedio(const Estudiante estudiantes[], int totalEstudiantes) {
    if (totalEstudiantes == 0) {
        cout << "\n[!] No hay estudiantes registrados.\n";
        return;
    }

    cout << "\n--- CONSULTAR PROMEDIO INDIVIDUAL ---\n";
    string codigo = leerTexto("Código del estudiante: ");
    int pos = buscarEstudiante(estudiantes, totalEstudiantes, codigo);
    if (pos == -1) {
        cout << "[!] No se encontró un estudiante con ese código.\n";
        return;
    }

    cout << "\nEstudiante: " << estudiantes[pos].nombre << " (" << estudiantes[pos].codigo << ")\n";

    // si no tiene notas no hay promedio que mostrar
    if (!estudiantes[pos].notasRegistradas) {
        cout << "Aún no tiene calificaciones registradas.\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "Notas: ";
    for (int j = 0; j < NUM_NOTAS; j++) {
        cout << estudiantes[pos].notas[j] << (j < NUM_NOTAS - 1 ? " | " : "\n");
    }
    cout << "Promedio final: " << estudiantes[pos].promedio << "\n";
}
