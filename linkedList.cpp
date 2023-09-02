// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include "linked_list_ed_plus.h"
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

void resuelveCaso() {
    linked_list_ed_plus<int> l1, l2;
    int n;
    cin >> n;
    while (n != 0) {
        l1.push_back(n);
        cin >> n;
    }
    cin >> n;
    while (n != 0) {
        l2.push_back(n);
        cin >> n;
    }
    l1.mezclar(l2);
    l1.mostrar();
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