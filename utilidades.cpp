#include <limits>
#include "datos.h"

// pide un entero y repite hasta que este dentro del rango
int leerEntero(const string& mensaje, int minimo, int maximo) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor && valor >= minimo && valor <= maximo) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');   // limpiamos el enter que queda
            return valor;
        }
        // si escribio letras hay que limpiar el cin o se cicla
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Debe ser un entero entre " << minimo << " y " << maximo << ".\n";
    }
}

// igual que el de arriba pero para decimales (las notas)
double leerDecimal(const string& mensaje, double minimo, double maximo) {
    double valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor && valor >= minimo && valor <= maximo) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Debe ser un numero entre " << minimo << " y " << maximo << ".\n";
    }
}

// pide un texto y no deja que quede vacio (campos requeridos)
string leerTexto(const string& mensaje) {
    string texto;
    while (true) {
        cout << mensaje;
        getline(cin, texto);
        if (!texto.empty()) return texto;
        cout << "Este campo es requerido, no puede quedar vacio.\n";
    }
}

// busca el codigo en el arreglo, devuelve la posicion o -1 si no esta
int buscarEstudiante(const Estudiante estudiantes[], int total, const string& codigo) {
    for (int i = 0; i < total; i++) {
        if (estudiantes[i].codigo == codigo) return i;
    }
    return -1;
}

// suma las 3 notas y las divide entre 3
double calcularPromedio(const Estudiante& e) {
    double suma = 0;
    for (int j = 0; j < NUM_NOTAS; j++) suma += e.notas[j];
    return suma / NUM_NOTAS;
}

// aprobado si el promedio es >= 6
string determinarEstado(double promedio) {
    return (promedio >= NOTA_APROBACION) ? "Aprobado" : "Reprobado";
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.get();
}

// cls en windows, clear en linux/mac
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
