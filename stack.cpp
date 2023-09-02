// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include <stack>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelveCaso() {
    string frase;
    getline(cin, frase);
    if (!cin)
        return false;

    stack<char> pila;
    bool end = false;
    int i = 0, parentesis = 0, corchete = 0, llave = 0;
    
    while (!end && i < (int)(frase.size())) {
        if (frase[i] == '(') {
            pila.push(frase[i]);
            parentesis++;
        } 
        else if (frase[i] == '[') {
            pila.push(frase[i]);
            corchete++;
        }
        else if (frase[i] == '{') {
            pila.push(frase[i]);
            llave++;
        }
        // Tuve que invertir la logica porque nunca llegaba a leer el caso base de un solo caracter de cerrado
        else if (frase[i] == ')') {
            if (pila.empty() || pila.top() != '(') {
                end = true;
            }
            else {
                pila.pop();
                parentesis--;
            }
        }
        else if (frase[i] == ']') {
            if (pila.empty() || pila.top() != '[') {
                end = true;
            }
            else {
                pila.pop();
                corchete--;
            }
        }
        else if (frase[i] == '}') {
            if (pila.empty() || pila.top() != '{') {
                end = true;
            }
            else {
                pila.pop();
                llave--;
            }
        }
        i++;
    }

    if (!end && parentesis == 0 && corchete == 0 && llave == 0) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
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