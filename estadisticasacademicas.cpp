#include "datos.h"

// opcion 7: estadisticas academicas
void estadisticasAcademicas(const Estudiante estudiantes[], int totalEstudiantes) {
    if (totalEstudiantes == 0) {
        cout << "\n[!] No hay estudiantes registrados.\n";
        return;
    }

    int aprobados = 0;
    int reprobados = 0;
    int evaluados = 0;
    double sumaPromedios = 0.0;

    for (int i = 0; i < totalEstudiantes; i++) {
        if (estudiantes[i].notasRegistradas) {
            evaluados++;
            sumaPromedios += estudiantes[i].promedio;
            if (estudiantes[i].promedio >= NOTA_APROBACION) {
                aprobados++;
            } else {
                reprobados++;
            }
        }
    }

    // si evaluados es 0 no se puede dividir (da error)
    if (evaluados == 0) {
        cout << "\n[!] No hay datos suficientes para calcular estadísticas (sin notas registradas).\n";
        return;
    }

    double promedioGeneral = sumaPromedios / evaluados;
    double porcAprobados = (static_cast<double>(aprobados) / evaluados) * 100.0;
    double porcReprobados = (static_cast<double>(reprobados) / evaluados) * 100.0;

    cout << "\n--- ESTADÍSTICAS ACADÉMICAS GENERALES ---\n";
    cout << "Total de estudiantes registrados: " << totalEstudiantes << endl;
    cout << "Total de estudiantes evaluados:   " << evaluados << endl;
    cout << fixed << setprecision(2);
    cout << "Promedio general del grupo:       " << promedioGeneral << endl;
    cout << "Estudiantes aprobados (>= 6):     " << aprobados << " (" << porcAprobados << "%)\n";
    cout << "Estudiantes reprobados (< 6):     " << reprobados << " (" << porcReprobados << "%)\n";
}
