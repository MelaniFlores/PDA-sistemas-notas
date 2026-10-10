#include "datos.h"

// menu
void mostrarMenu() {
    cout << "========================================\n";
    cout << " SISTEMA DE GESTIÓN DE CALIFICACIONES\n";
    cout << "========================================\n\n";
    cout << "1. Registrar estudiantes\n";
    cout << "2. Registrar calificaciones\n";
    cout << "3. Consultar promedio individual\n";
    cout << "4. Consultar estado académico\n";
    cout << "5. Reporte general de estudiantes\n";
    cout << "6. Mejor y peor estudiante\n";
    cout << "7. Estadísticas académicas\n";
    cout << "8. Salir\n\n";
    cout << "========================================\n";
}

int main() {
#ifdef _WIN32
    system("chcp 65001 > nul");   // para que se vean las tildes en windows
#endif

    Estudiante estudiantes[MAX_ESTUDIANTES];   // aqui se guardan todos los estudiantes
    int totalEstudiantes = 0;                  // cuantos llevamos registrados
    int opcion;

    do {
        limpiarPantalla();
        mostrarMenu();
        opcion = leerEntero("Seleccione una opción: ", 1, 8);

        switch (opcion) {
            case 1: registrarEstudiantes(estudiantes, totalEstudiantes);       break;
            case 2: registrarCalificaciones(estudiantes, totalEstudiantes);    break;
            case 3: consultarPromedio(estudiantes, totalEstudiantes);          break;
            case 4: consultarEstadoAcademico(estudiantes, totalEstudiantes);   break;
            case 5: reporteGeneralEstudiantes(estudiantes, totalEstudiantes);  break;
            case 6: mejorYPeorEstudiante(estudiantes, totalEstudiantes);       break;
            case 7: estadisticasAcademicas(estudiantes, totalEstudiantes);     break;
            case 8: cout << "\nSaliendo del sistema...\n"; break;
        }

        if (opcion != 8) pausar();   // para que alcance a leer lo que salio
    } while (opcion != 8);

    return 0;
}
