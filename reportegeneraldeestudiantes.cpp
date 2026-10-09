// ==========================================
// punto 5: Reporte general de estudiantes
// ==========================================
void reporteGeneralEstudiantes(const Estudiante estudiantes[], int totalEstudiantes) {
    if (totalEstudiantes == 0) {
        cout << "\n[!] No hay estudiantes registrados para mostrar el reporte.\n";
        return;
    }

    cout << "\n=================================== REPORTE GENERAL DE ESTUDIANTES ===================================\n";
    cout << left << setw(12) << "Código" 
         << setw(25) << "Nombre" 
         << setw(8) << "Nota 1" 
         << setw(8) << "Nota 2" 
         << setw(8) << "Nota 3" 
         << setw(12) << "Promedio" 
         << setw(12) << "Estado" << endl;
    cout << "------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < totalEstudiantes; i++) {
        cout << left << setw(12) << estudiantes[i].codigo
             << setw(25) << estudiantes[i].nombre;

        if (estudiantes[i].notasRegistradas) {
            cout << setw(8) << fixed << setprecision(2) << estudiantes[i].notas[0]
                 << setw(8) << fixed << setprecision(2) << estudiantes[i].notas[1]
                 << setw(8) << fixed << setprecision(2) << estudiantes[i].notas[2]
                 << setw(12) << fixed << setprecision(2) << estudiantes[i].promedio
                 << setw(12) << estudiantes[i].estado << endl;
        } else {
            cout << setw(8) << "N/A"
                 << setw(8) << "N/A"
                 << setw(8) << "N/A"
                 << setw(12) << "N/A"
                 << setw(12) << "Sin Calificar" << endl;
        }
    }
    cout << "================================================================================----------------------\n";
}