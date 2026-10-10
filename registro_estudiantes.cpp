#include "datos.h"

// opcion 1: registrar estudiantes
void registrarEstudiantes(Estudiante estudiantes[], int& totalEstudiantes) {
    // primero revisamos que todavia haya espacio en el arreglo
    if (totalEstudiantes >= MAX_ESTUDIANTES) {
        cout << "\n[!] Se alcanzó el límite de estudiantes (" << MAX_ESTUDIANTES << ").\n";
        return;
    }

    cout << "\n--- REGISTRAR ESTUDIANTE ---\n";
    string codigo = leerTexto("Código del estudiante: ");

    // el codigo no se puede repetir
    if (buscarEstudiante(estudiantes, totalEstudiantes, codigo) != -1) {
        cout << "[!] Ya existe un estudiante con ese código.\n";
        return;
    }

    string nombre = leerTexto("Nombre del estudiante: ");

    // guardamos al estudiante en la siguiente posicion libre
    int i = totalEstudiantes;
    estudiantes[i].codigo = codigo;
    estudiantes[i].nombre = nombre;
    for (int j = 0; j < NUM_NOTAS; j++) estudiantes[i].notas[j] = 0;
    estudiantes[i].promedio = 0;
    estudiantes[i].estado = "Sin calificar";
    estudiantes[i].notasRegistradas = false;   // todavia no tiene notas
    totalEstudiantes++;

    cout << "Estudiante registrado correctamente.\n";
}
