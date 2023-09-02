// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include "bintree_eda.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;

pair<int, int> caminoPares(const bintree<int> & a) {
    if (a.empty())
        return { 0, 0 };
    else {
        auto iz = caminoPares(a.left());
        auto dc = caminoPares(a.right());
        int caminoRaiz = iz.second + dc.second;
        if (caminoRaiz + (a.root() % 2 == 0) > iz.first && caminoRaiz + (a.root() % 2 == 0) > dc.first)
            return { caminoRaiz + (a.root() % 2 == 0), max(iz.second, dc.second) + (a.root() % 2 == 0) };
        else
            return { max(iz.first, dc.first), max(iz.second, dc.second) + (a.root() % 2 == 0) };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);
    cout << caminoPares(arbol).first << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}