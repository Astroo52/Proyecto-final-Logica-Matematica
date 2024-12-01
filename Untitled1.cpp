#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    double promedio;
    bool aprobado;
};

int main() {
    const int MAX_ESTUDIANTES = 100;
    const int MAX_MATERIAS = 10;
    Estudiante estudiantes[MAX_ESTUDIANTES];
    double calificaciones[MAX_ESTUDIANTES][MAX_MATERIAS];
    
    int numEstudiantes, numMaterias;
    cout << "Ingrese el numero de estudiantes: ";
    cin >> numEstudiantes;

    cout << "Ingrese el numero de materias por estudiante: ";
    cin >> numMaterias;

    for (int i = 0; i < numEstudiantes; ++i) {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nombre;

        double suma = 0;
        for (int j = 0; j < numMaterias; ++j) {
            cout << "Calificacion " << j + 1 << " de " << estudiantes[i].nombre << ": ";
            cin >> calificaciones[i][j];
            suma += calificaciones[i][j];
        }
        
        estudiantes[i].promedio = suma / numMaterias;
        estudiantes[i].aprobado = estudiantes[i].promedio >= 60.0;
    }
    int indiceMejor = 0, indicePeor = 0;
    for (int i = 1; i < numEstudiantes; ++i) {
        if (estudiantes[i].promedio > estudiantes[indiceMejor].promedio) {
            indiceMejor = i;
        }
        if (estudiantes[i].promedio < estudiantes[indicePeor].promedio) {
            indicePeor = i;
        }
    }
    for (int i = 0; i < numEstudiantes - 1; ++i) {
        for (int j = i + 1; j < numEstudiantes; ++j) {
            if (estudiantes[i].promedio < estudiantes[j].promedio) {
                Estudiante temp = estudiantes[i];
                estudiantes[i] = estudiantes[j];
                estudiantes[j] = temp;
            }
        }
    }

    cout << "\nResultados:\n";
    for (int i = 0; i < numEstudiantes; ++i) {
        cout << "Estudiante: " << estudiantes[i].nombre
             << ", Promedio: " << estudiantes[i].promedio
             << ", Estado: " << (estudiantes[i].aprobado ? "Aprobado" : "Reprobado") << endl;
    }

    cout << "\nMejor estudiante: " << estudiantes[indiceMejor].nombre
         << " con promedio " << estudiantes[indiceMejor].promedio << endl;

    cout << "Peor estudiante: " << estudiantes[indicePeor].nombre
         << " con promedio " << estudiantes[indicePeor].promedio << endl;

    cout << "\nPromedios ordenados de mayor a menor:\n";
    for (int i = 0; i < numEstudiantes; ++i) {
        cout << estudiantes[i].nombre << ": " << estudiantes[i].promedio << endl;
    }

    return 0;
}

