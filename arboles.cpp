// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"
using namespace std;

class primo {
    public:
        bool operator() (int n) {
            if (n == 0 || n == 1 || n == 4) { return false; }
            for (int i = 2; i < n / 2; i++) {
                if (n % i == 0) { return false; }
            }
            return true;
        }
};

void resuelveCaso() {
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