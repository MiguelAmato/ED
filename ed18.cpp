// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelveCaso() {
    int n;
    cin >> n;
    if (!cin)
        return false;
    string fecha;
    for (int i = 0; i < n; ++i) {
        cin >> fecha;
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
