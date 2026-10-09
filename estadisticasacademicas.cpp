// ==========================================
// punto 7: Estadísticas académicas
// ==========================================
void estadisticasAcademicas(const Estudiante estudiantes[], int totalEstudiantes) {
    if (totalEstudiantes == 0) {
        cout << "\n[!] No hay estudiantes registrados.\n";
        return;
    }

    int aprobados = 0;
    int reprobados = 0;
    int evaluados = 0;
    float sumaPromedios = 0.0f;

    for (int i = 0; i < totalEstudiantes; i++) {
        if (estudiantes[i].notasRegistradas) {
            evaluados++;
            sumaPromedios += estudiantes[i].promedio;
            if (estudiantes[i].promedio >= 6.0f) {
                aprobados++;
            } else {
                reprobados++;
            }
        }
    }

    if (evaluados == 0) {
        cout << "\n[!] No hay datos suficientes para calcular estadísticas (sin notas registradas).\n";
        return;
    }

    float promedioGeneral = sumaPromedios / evaluados;
    float porcAprobados = (static_cast<float>(aprobados) / evaluados) * 100.0f;
    float porcReprobados = (static_cast<float>(reprobados) / evaluados) * 100.0f;

    cout << "\n--- ESTADÍSTICAS ACADÉMICAS GENERALES ---\n";
    cout << "Total de estudiantes evaluados: " << evaluados << endl;
    cout << "Promedio general del grupo:     " << fixed << setprecision(2) << promedioGeneral << endl;
    cout << "Estudiantes aprobados (>= 6):   " << aprobados << " (" << porcAprobados << "%)\n";
    cout << "Estudiantes reprobados (< 6):  " << reprobados << " (" << porcReprobados << "%)\n";
}