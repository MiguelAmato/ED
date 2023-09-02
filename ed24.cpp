// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include "Horas.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0)
        return false;
    list<Horas> lista;
    Horas h;
    for (int i = 0; i < n; i++) {
        cin >> h;
        lista.push_back(h);
    }

    auto it = lista.begin();
    bool par = false;

    while (it != lista.end()) {
        if (par) {
            it = lista.erase(it);
        }
        else { 
            it++; 
        }
        par = !par;
    }

    it = lista.begin();

    if (it != lista.end()) {
        cout << *it;
        it++;
    }
    while (it != lista.end()) {
        cout << " " << *it;
        it++;
    }
    cout << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}