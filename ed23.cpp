// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template <class T, class Predicate>
void remove_if(list<T>& lista, Predicate pred) {
    auto it = lista.begin();
    while (it != lista.end()) {
        if (pred(*it)) {
            it = lista.erase(it);
        }
        else {
            it++;
        }
    }
}

bool resuelveCaso() {
    int n, min, max;
    cin >> n >> min >> max;
    if (n == 0 && min == 0 && max == 0) {
        return false;
    }
    list<pair<int, string>> lista;
    int edad;
    string nombre;
    for (int i = 0; i < n; i++) {
        cin >> edad;
        cin.get();
        getline(cin, nombre);
        lista.push_back({ edad, nombre });
    }
    
    remove_if(lista, [min, max](pair<int, string> p) { return !(p.first >= min && p.first <= max); });

    auto it = lista.begin();
    
    while (it != lista.end()) {
        cout << (*it).second << "\n";
        it++;
    }
    cout << "---\n";
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