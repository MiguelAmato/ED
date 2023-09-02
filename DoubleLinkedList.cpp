// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include "double_linked_list_ed_plus.h"
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
    int pivote;
    cin >> pivote;
    double_linked_list_ed_plus<int> l;
    int e;
    for (int i = 0; i < n; i++) {
        cin >> e;
        l.push_back(e);
    }
    l.particion(pivote);
    l.mostrar();
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