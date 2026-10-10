#include "datos.h"

// opcion 5: reporte general de estudiantes
void reporteGeneralEstudiantes(const Estudiante estudiantes[], int totalEstudiantes) {
    if (totalEstudiantes == 0) {
        cout << "\n[!] No hay estudiantes registrados para mostrar el reporte.\n";
        return;
    }

    cout << "\n================== REPORTE GENERAL DE ESTUDIANTES ==================\n";
    // encabezados de la tabla
    cout << left << setw(12) << "Código"
         << setw(22) << "Nombre"
         << setw(8) << "Nota 1"
         << setw(8) << "Nota 2"
         << setw(8) << "Nota 3"
         << setw(10) << "Promedio"
         << "Estado" << endl;
    cout << "--------------------------------------------------------------------------\n";

    for (int i = 0; i < totalEstudiantes; i++) {
        cout << left << setw(12) << estudiantes[i].codigo
             << setw(22) << estudiantes[i].nombre;

        if (estudiantes[i].notasRegistradas) {
            cout << fixed << setprecision(2)
                 << setw(8) << estudiantes[i].notas[0]
                 << setw(8) << estudiantes[i].notas[1]
                 << setw(8) << estudiantes[i].notas[2]
                 << setw(10) << estudiantes[i].promedio
                 << estudiantes[i].estado << endl;
        } else {
            // si no tiene notas ponemos N/A en vez de ceros
            cout << setw(8) << "N/A"
                 << setw(8) << "N/A"
                 << setw(8) << "N/A"
                 << setw(10) << "N/A"
                 << "Sin calificar" << endl;
        }
    }
    cout << "==========================================================================\n";
    cout << "Total de estudiantes: " << totalEstudiantes << endl;
}
