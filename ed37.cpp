// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;


template <typename T>
inline bintree<T> efwfArbol(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un árbol vacío
        return {};
    }
    else { // leer recursivamente los hijos
        auto iz = leerArbol(vacio);
        auto dr = leerArbol(vacio);
        return { iz, raiz, dr };
    }
}

bintree<int> arbolConstruido(const vector<int>& preorder, const vector<int>& inorder, int i, const int fin) {
    if (i == fin) {
        return {};
    }
    else {
        int root = preorder[i];
        bintree<int> iz = arbolConstruido(preorder, inorder, i + 1, fin);
        bintree<int> dc = arbolConstruido(preorder, inorder, i + 1, fin);
    }
    
}


bool resuelveCaso() {
    int e;
    cin >> e;
    if (!cin)
        return false;
    vector<int> preorder, inorder;
    preorder.push_back(e);
    char aux;
    cin.get(aux);
    while (aux != '\n') {
        cin >> e;
        preorder.push_back(e);
        cin.get(aux);
    }
    cin >> e;
    inorder.push_back(e);
    cin.get(aux);
    while (aux != '\n') {
        cin >> e;
        inorder.push_back(e);
        cin.get(aux);
    }
    vector<int> postorden = arbolConstruido(preorder, inorder, 0, (int) preorder.size()).postorder();
    cout << postorden[0];
    for (int i = 0; i < postorden.size(); ++i) {
        cout << " " << postorden[i];
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