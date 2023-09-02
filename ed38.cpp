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

template <typename T>
pair <int, int> repetido(const bintree<T>& arbol, const T & valor, int h) {
    if (arbol.empty()) {
        return { -1 , 0 };
    }
    else {
        auto iz = repetido(arbol.left(), valor, h + 1);
        auto dc = repetido(arbol.right(), valor, h + 1);
        if (iz.second == 2 && dc.second == 2) return iz.first < dc.second ? iz.first : dc.first;
        else if (iz.second == 2) return iz;
        else if (dc.second == 2) return dc;
        else if () {
            

        }
    }
}

void resuelveCaso() {
    char c;
    cin >> c;
    if (c == 'N') {
        int num;
        cin >> num;
        bintree<int> arbol = leerArbol(-1);
        pair<int, int> repe = repetido(arbol, num, 1);
        if (repe.first != -1) {
            cout << repe.first;
        }
        else {
            cout << "NO EXISTE";
        }
    }
    else if (c == 'C') {
        char car;
        cin >> car;
        bintree<char> arbol = leerArbol('.');
        pair<int, int> repe = repetido(arbol, car, 1);
        if (repe.first != -1) {
            cout << repe.first;
        }
        else {
            cout << "NO EXISTE";
        }
    }
    cout << "\n";
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