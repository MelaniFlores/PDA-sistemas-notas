#include "datos.h"

// opcion 6: mejor y peor estudiante (segun el promedio)
void mejorYPeorEstudiante(const Estudiante estudiantes[], int totalEstudiantes) {
    if (totalEstudiantes == 0) {
        cout << "\n[!] No hay estudiantes registrados.\n";
        return;
    }

    int idxMejor = -1;
    int idxPeor = -1;
    double maxPromedio = NOTA_MIN - 1;   // empiezan fuera del rango para que cualquier promedio los cambie
    double minPromedio = NOTA_MAX + 1;
    int evaluados = 0;

    // solo contamos a los que ya tienen notas
    for (int i = 0; i < totalEstudiantes; i++) {
        if (estudiantes[i].notasRegistradas) {
            evaluados++;
            if (estudiantes[i].promedio > maxPromedio) {
                maxPromedio = estudiantes[i].promedio;
                idxMejor = i;
            }
            if (estudiantes[i].promedio < minPromedio) {
                minPromedio = estudiantes[i].promedio;
                idxPeor = i;
            }
        }
    }

    if (evaluados == 0) {
        cout << "\n[!] Ningún estudiante tiene calificaciones registradas aún.\n";
        return;
    }

    cout << "\n--- MEJOR Y PEOR ESTUDIANTE ---\n";
    cout << "\n[+] Estudiante con el MEJOR promedio:\n";
    cout << "    Código: " << estudiantes[idxMejor].codigo << endl;
    cout << "    Nombre: " << estudiantes[idxMejor].nombre << endl;
    cout << "    Promedio: " << fixed << setprecision(2) << estudiantes[idxMejor].promedio << endl;

    cout << "\n[-] Estudiante con el PEOR promedio:\n";
    cout << "    Código: " << estudiantes[idxPeor].codigo << endl;
    cout << "    Nombre: " << estudiantes[idxPeor].nombre << endl;
    cout << "    Promedio: " << fixed << setprecision(2) << estudiantes[idxPeor].promedio << endl;
}
