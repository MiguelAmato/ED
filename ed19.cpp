// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool esVocal(char letra) {
    char l = tolower(letra);
    return (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u');
}

bool resuelveCaso() {
    char c;
    cin.get(c);
    if (!cin)
        return false;
    stack<char> finFrase;
    queue<char> iniFrase;
    iniFrase.push(c);
    cin.get(c);
    bool colaPush = true;
    while (c != '\n' && !cin.eof()) {
        if (colaPush)
            finFrase.push(c);
        else
            iniFrase.push(c);
        colaPush = !colaPush;
        cin.get(c);
    }
    bool antBool = false;
    char ant;
    string frase = "";
    while (!iniFrase.empty()) {
        frase = frase + iniFrase.front();
        iniFrase.pop();
    }
    cout << frase;
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