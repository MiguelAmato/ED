// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void resuelveCaso() {
    int n;
    cin >> n;
    map<int, int> mapa;
    int cont = 0, e;
    for (int i = 0; i < n; i++) {
        cin >> e;
        if (mapa.count(e) == 0) {
            cont++;
            mapa[e] = 0;
        }
        else {
            mapa[e] = cont;
            cont = 0;
        }
    }
    int max = 0;

    for (auto elem : mapa) {
        if (max < elem.second) {
            max = elem.second;
        }
    }

    cout << max << "\n";
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