#include "datos.h"

// opcion 2: registrar las 3 calificaciones de un estudiante
void registrarCalificaciones(Estudiante estudiantes[], int totalEstudiantes) {
    if (totalEstudiantes == 0) {
        cout << "\n[!] Primero debe registrar estudiantes.\n";
        return;
    }

    cout << "\n--- REGISTRAR CALIFICACIONES ---\n";
    string codigo = leerTexto("Código del estudiante: ");
    int pos = buscarEstudiante(estudiantes, totalEstudiantes, codigo);
    if (pos == -1) {
        cout << "[!] No se encontró un estudiante con ese código.\n";
        return;
    }

    cout << "Estudiante: " << estudiantes[pos].nombre << "\n";
    if (estudiantes[pos].notasRegistradas) {
        cout << "(ya tenía notas, se van a reemplazar)\n";
    }

    // pedimos las 3 notas, leerDecimal valida que esten entre 0 y 10
    for (int j = 0; j < NUM_NOTAS; j++) {
        estudiantes[pos].notas[j] = leerDecimal("Nota " + to_string(j + 1) + " (0-10): ", NOTA_MIN, NOTA_MAX);
    }

    // calculamos el promedio y el estado una sola vez aqui
    estudiantes[pos].promedio = calcularPromedio(estudiantes[pos]);
    estudiantes[pos].estado = determinarEstado(estudiantes[pos].promedio);
    estudiantes[pos].notasRegistradas = true;

    cout << fixed << setprecision(2);
    cout << "Calificaciones registradas. Promedio: " << estudiantes[pos].promedio
         << " (" << estudiantes[pos].estado << ")\n";
}
