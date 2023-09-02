// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

template <class T>
T mySearch(T const& ini1, T const& fin1, T const& ini2, T const& fin2) {
    auto aux1 = ini1, aux2 = ini2;
    while (aux1 != fin1 && aux2 != fin2) {
        if (*aux1 == *ini2) {
            bool iguales = true;
            auto cont = aux1;
            aux2 = ini2;
            while (iguales && cont != fin1 && aux2 != fin2) {
                if (*cont == *aux2) {
                    cont++;
                    aux2++;
                }
                else {
                    iguales = false;
                }
            }
            if (aux2 != fin2) {
                ++aux1;
            }
        }
        else {
            aux1++;
        }
    }
    return aux1;
}

bool resuelveCaso() {
    int n1, n2;
    cin >> n1 >> n2;
    if (n1 == 0 && n2 == 0)
        return false;
    list<int> lista1, lista2;
    int e;
    for (int i = 0; i < n1; i++) {
        cin >> e;
        lista1.push_back(e);
    }
    for (int i = 0; i < n2; i++) {
        cin >> e;
        lista2.push_back(e);
    }

    auto it = mySearch(lista1.begin(), lista1.end(), lista2.begin(), lista2.end());

    while (it != lista1.end()) {
        for (int i = 0; i < lista2.size(); i++) {
            it = lista1.erase(it);
        }
        it = mySearch(it, lista1.end(), lista2.begin(), lista2.end());
    }

    it = lista1.begin();

    if (it != lista1.end()) {
        cout << *it;
        it++;
    }
    while (it != lista1.end()) {
        cout << " " << *it;
        it++;
    }
    cout << "\n";
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