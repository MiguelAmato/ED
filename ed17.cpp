// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <queue>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// No era con doble linked list 

bool resuelveCaso() {
    int n, saltos;
    cin >> n >> saltos;
    if (n == 0 && saltos == 0)
        return false;
    queue<int> clase;
    for (int i = 1; i <= n; ++i) {
        clase.push(i);
    }
    int cont = 0;
    while (clase.size() > 1) {
        if (cont < saltos) {
            clase.push(clase.front());
            clase.pop();
            cont++;
        }
        else {
            clase.pop();
            cont = 0;
        }
    }
    cout << clase.front() << "\n";
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