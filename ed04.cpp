// Nombre del alumno 
// Usuario del Juez 

#include "Peliculas.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool resuelveCaso() {
    int nPeliculas;
    cin >> nPeliculas;
    if (nPeliculas == 0)
        return false;
    vector<Peliculas> v;
    Horas inicio, fin, suma;
    string titulo;
    for (int i = 0; i < nPeliculas; i++) {
        cin >> inicio >> fin;
        cin.get();
        getline(cin, titulo);
        suma = inicio + fin;
        v.push_back(Peliculas(suma, titulo));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < nPeliculas; i++) {
        cout << v[i] << "\n";
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