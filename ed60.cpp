  // URL del video: https://youtu.be/auLxjV9fU4c
// Nombre del alumno: Miguel Antonio Amato Hermo
// Usuario del Juez: A01

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <list>
using namespace std;

// Version hecha con array como estructura de datos para guardar los grupos de alumnos de la academia.

class AcademiaChino {
private:

    using alumno = string;
    using grupo = int;

    static const int MAX_GRUPOS = 6;
    static const int GRADUADO = 7;

    unordered_map<alumno, pair<grupo, list<alumno>::iterator>> alumnos;
    list<alumno> grupos[MAX_GRUPOS + 1];

public:

    // Insertar tanto en listas como en unordered_map es constante
    void nuevo_estudiante(const alumno& dni, const grupo& grupo) { // O(1)
        if (alumnos.count(dni) == 1) // O(1)
            throw domain_error("Estudiante existente"); // O(1)
        if (grupo < 1 || grupo > 6) // O(1)
            throw domain_error("Grupo incorrecto"); // O(1)
        grupos[grupo - 1].push_back(dni); // O(1)
        alumnos.insert({ dni, {grupo, --grupos[grupo - 1].end()} }); // O(1)
    }

    // Todas las operaciones son constantes ya que estamos trabajando con unordered_map y array 
    void promocionar(const alumno& dni) { // O(1)
        if (alumnos.count(dni) == 0) // O(1)
            throw domain_error("Estudiante no existente"); // O(1)
        if (alumnos.at(dni).first == GRADUADO) // O(1)
            throw domain_error("Estudiante ya graduado"); // O(1)
        grupos[alumnos.at(dni).first - 1].erase(alumnos.at(dni).second); // O(1)
        grupos[alumnos.at(dni).first].push_back(dni); // O(1)
        alumnos.at(dni).first++; // O(1)
        alumnos.at(dni).second = --grupos[alumnos.at(dni).first - 1].end(); // O(1)
    }

    // Es constante ya que accedes a una variable desde un unordered_map
    grupo grupo_estudiante(const alumno& dni) { // O(1)
        if (alumnos.count(dni) == 0) // O(1)
            throw domain_error("Estudiante no existente"); // O(1)
        if (alumnos.at(dni).first == GRADUADO) // O(1)
            throw domain_error("Estudiante ya graduado"); // O(1)
        return alumnos.at(dni).first; // O(1)
    }

    // En el caso peor al recorrer una lista y luego ordenar un vector el coste de esta operacion es nlog(n)
    vector<alumno> graduados() { // O(nlog(n))
        vector<string> ret; // O(1)
        list<string> graduados = grupos[6]; // O(1)
        for (const alumno& s : graduados) { // O(n)
            ret.push_back(s);
        }
        sort(ret.begin(), ret.end()); // O(nlog(n))
        return ret;
    }

    // El coste de esta operacion es constante ya que accedes a una lista dentro de un array
    alumno novato(const grupo& grupo) { // O(1)
        if (grupo < 1 || grupo > 6) // O(1) 
            throw domain_error("Grupo incorrecto"); // O(1)
        if (grupos[grupo - 1].empty()) // O(1)
            throw domain_error("Grupo vacio"); // O(1)
        return grupos[grupo - 1].back(); // O(1)
    }
};

bool resuelveCaso() {
    string orden;
    cin >> orden;
    if (!cin)
        return false;
    AcademiaChino ac;
    while (orden != "FIN") {
        try {
            if (orden == "nuevo_estudiante") {
                string dni;
                int grupo;
                cin >> dni >> grupo;
                ac.nuevo_estudiante(dni, grupo);
            }
            else if (orden == "promocionar") {
                string dni;
                cin >> dni;
                ac.promocionar(dni);
            }
            else if (orden == "grupo_estudiante") {
                string dni;
                cin >> dni;
                int grupo = ac.grupo_estudiante(dni);
                cout << dni << " esta en el grupo " << grupo << "\n";
            }
            else if (orden == "graduados") {
                cout << "Lista de graduados:";
                for (const string& s : ac.graduados()) {
                    cout << " " << s;
                }
                cout << "\n";
            }
            else if (orden == "novato") {
                int grupo;
                cin >> grupo;
                string dni = ac.novato(grupo);
                cout << "Novato de " << grupo << ": " << dni << "\n";
            }
        }
        catch (domain_error& d_e) {
            string error = "ERROR: ";
            cout << error << d_e.what() << "\n";
        }
        cin >> orden;
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
 
