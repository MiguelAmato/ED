// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0)
        return false;
    map < string, vector<int>> mapa;
    string linea;
    cin.get();
    for (int i = 1; i <= n; i++) {
        getline(cin, linea);
        stringstream lin(linea);
        string palabra;
        while (lin >> palabra) {
            if (palabra.length() > 2) {
                for (char& c : palabra) { c = tolower(c); }
                if (mapa[palabra].empty() || mapa[palabra].back() != i) {
                    mapa[palabra].push_back(i);
                }
            }
        }
    }

    for (auto e : mapa) {
        cout << e.first;
        for (int num : e.second) {
            cout << " " << num;
        }
        cout << "\n";
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

/*
bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0)
        return false;
    map<string, int> mapa;
    cin.get();
    for (int i = 0; i < n; i++) {
        string nombre, correccion;
        getline(cin, nombre);
        getline(cin, correccion);
        if (correccion == "CORRECTO") {
            mapa[nombre] += 1;
        }
        else if (correccion == "INCORRECTO") {
            mapa[nombre] -= 1;
        }
    }

    for (auto e : mapa) {
        if (e.second != 0) {
            cout << e.first << ", " << e.second << "\n";
        }
    }
    cout << "---\n";

    return true;
}

*/