// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include "Complejo.h"
#include <iomanip>
#include <fstream>
using namespace std;

void resuelveCaso() {
    float real, imag;
    int n;
    cin >> real >> imag >> n;
    Complejo<float, float> c(real, imag), z;

    int i = 0;
    bool end = false;
    while (!end && i < n) {
        z = (z * z) + c;
        if (z.modulo() > 2) {
            end = true;
        }
        i++;
    }

    if (!end) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}