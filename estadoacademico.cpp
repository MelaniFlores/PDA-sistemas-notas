#include "datos.h"

// opcion 4: consultar estado academico
void consultarEstadoAcademico(const Estudiante estudiantes[], int totalEstudiantes) {
    if (totalEstudiantes == 0) {
        cout << "\n[!] No hay estudiantes registrados en el sistema.\n";
        return;
    }

    cout << "\n--- CONSULTAR ESTADO ACADÉMICO ---\n";
    string codigoBuscar = leerTexto("Ingrese el código del estudiante: ");

    // recorremos el arreglo buscando el codigo
    bool encontrado = false;
    for (int i = 0; i < totalEstudiantes; i++) {
        if (estudiantes[i].codigo == codigoBuscar) {
            encontrado = true;
            cout << "\nEstudiante: " << estudiantes[i].nombre << endl;

            if (!estudiantes[i].notasRegistradas) {
                cout << "Estado: Pendiente (aún no se han registrado sus calificaciones).\n";
            } else {
                cout << "Promedio Final: " << fixed << setprecision(2) << estudiantes[i].promedio << endl;
                cout << "Estado Académico: " << estudiantes[i].estado << endl;
            }
            break;   // ya lo encontramos, no hace falta seguir
        }
    }

    if (!encontrado) {
        cout << "[!] No se encontró ningún estudiante con el código ingresado.\n";
    }
}
