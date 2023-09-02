// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;


const int MAX = 2147483647;
const int MIN = -2147483647;

struct tSol {
    bool es;
    int min;
    int max;
};

tSol esBusqueda(const bintree<int> & arbol) {
    if (arbol.empty()) {
        return {true, MAX, MIN };
    }
    else {
        auto iz = esBusqueda(arbol.left());
        auto dc = esBusqueda(arbol.right());
        if (iz.es & dc.es && arbol.root() > iz.max && arbol.root() < dc.min) {
            return {true, min(arbol.root(), iz.min), max(arbol.root(), dc.max)};
        }
        else {
            return { false, min(arbol.root(), iz.min), max(arbol.root(), dc.max) };
        }
    }
}

void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);
    auto sol = esBusqueda(arbol);
    if (sol.es) {
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
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}


