// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"
using namespace std;

template <typename T>
T elementoMinimo(const bintree<T>& arbol, T min) {
    if (arbol.empty()) {
        return min;
    }
    else {
        T minAct = arbol.root();
        T minIzq = elementoMinimo(arbol.left(), arbol.root());
        T minDrc = elementoMinimo(arbol.right(), arbol.root());
        if (minAct >= minIzq || minAct >= minDrc) 
            minIzq < minDrc ? minAct = minIzq : minAct = minDrc;
        return minAct;
    }
}

bool resuelveCaso() {
    char c;
    cin >> c;
    if (!cin)
        return false;
    if (c == 'N') {
        bintree<int> arbol = leerArbol(-1);
        cout << elementoMinimo(arbol, arbol.root()) << "\n";
    }
    else if (c == 'P') {
        string fin = "#";
        bintree<string> arbol = leerArbol(fin);
        cout << elementoMinimo(arbol, arbol.root()) << "\n";
    }
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    while (resuelveCaso());

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}