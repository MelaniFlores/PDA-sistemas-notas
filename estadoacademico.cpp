// ==========================================
// punto 4: Consultar estado académico
// ==========================================
void consultarEstadoAcademico(const Estudiante estudiantes[], int totalEstudiantes) {
    if (totalEstudiantes == 0) {
        cout << "\n[!] No hay estudiantes registrados en el sistema.\n";
        return;
    }

    string codigoBuscar;
    cout << "\n--- CONSULTAR ESTADO ACADÉMICO ---\n";
    cout << "Ingrese el código del estudiante: ";
    cin >> codigoBuscar;

    bool encontrado = false;
    for (int i = 0; i < totalEstudiantes; i++) {
        if (estudiantes[i].codigo == codigoBuscar) {
            encontrado = true;
            cout << "\nEstudiante: " << estudiantes[i].nombre << endl;
            
            if (!estudiantes[i].notasRegistradas) {
                cout << "Estado: Pendiente (Aún no se han registrado sus calificaciones).\n";
            } else {
                cout << "Promedio Final: " << fixed << setprecision(2) << estudiantes[i].promedio << endl;
                cout << "Estado Académico: " << estudiantes[i].estado << endl;
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "[!] No se encontró ningún estudiante con el código ingresado.\n";
    }
}