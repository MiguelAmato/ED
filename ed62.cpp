// Alumno: Miguel Antonio Amato Hermo
// Usuario del juez: A01

#include <unordered_map>
#include <map>
#include <list>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class OficinaEmpleo {
private:

	// clave: Nombre de la persona
	// valor: Par con los empleos a los que esta cualificado y un iterador 
	unordered_map<string, map<string, list<string>::iterator>> personas; 
	unordered_map<string, list<string>> empleos;

public:

	void altaOficina(const string& nombre, const string& empleo) {
		auto par = personas[nombre].insert({ empleo, list<string>::iterator() });
		if (par.second) {
			empleos[empleo].push_back(nombre);
			par.first->second = --empleos[empleo].end();
		}
	}

	string ofertaEmpleo(const string& empleo) {
		if (empleos.count(empleo) == 0) {
			throw domain_error("No existen personas apuntadas a este empleo");
		}
		string personaCualificada = *empleos[empleo].begin();
		for (auto& a : personas[personaCualificada]) {
			empleos[a.first].erase(a.second);
			if (empleos[a.first].empty()) {
				empleos.erase(a.first);
			}
		}
		personas.erase(personaCualificada);
		return personaCualificada;
	}

	vector<string> listadoEmpleos(const string& nombre) {
		if (personas.count(nombre) == 0) {
			throw domain_error("Persona inexistente");
		}
		vector<string> ret;
		for (auto& s: personas.at(nombre)) {
			ret.push_back(s.first);
		}
		return ret;
	}

};

bool resuelveCaso() {
	string orden;
	cin >> orden;
	if (cin.eof()) 
		return false;
	OficinaEmpleo o;
	while (orden != "FIN") {
		try {
			if (orden == "altaOficina") {
				string nombre, empleo;
				cin >> nombre >> empleo;
				o.altaOficina(nombre, empleo);
			}
			else if (orden == "ofertaEmpleo") {
				string empleo;
				cin >> empleo;
				string oferta = o.ofertaEmpleo(empleo);
				cout << empleo << ": " << oferta << "\n";
			}
			else if (orden == "listadoEmpleos") {
				string nombre;
				cin >> nombre;
				vector<string> empleos = o.listadoEmpleos(nombre);
				cout << nombre << ":";
				for (const string& s : empleos) {
					cout << " " << s;
				}
				cout << "\n";
			}
		}
		catch (std::domain_error& e) {
			cout << "ERROR: " << e.what() << "\n";
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