// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"
using namespace std;

struct tSol {
    int multiplo;
    int altura;
};

bool esPrimo(int n) {
    if (n == 0 || n == 1 || n == 4) { return false; }
    for (int i = 2; i < n / 2; i++) {
        if (n % i == 0) { return false; }
    }
    return true;
}

tSol accesible(const bintree<int>& arbol, int h) {
    if (arbol.empty()) {
        return { 0, h };
    }
    else {
        tSol izq = accesible(arbol.left(), h + 1);
        tSol dch = accesible(arbol.right(), h + 1);
        if (!esPrimo(arbol.root())) {
            if (arbol.root() % 7 == 0) {
                return { arbol.root(), h };
            }
        }
    }
}

void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);
    tSol acc = accesible(arbol, 1);
    cout << acc.multiplo << " " << acc.altura << "\n";
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