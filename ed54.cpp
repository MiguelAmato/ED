// Alumno: Miguel Antonio Amato Hermo
// Usuario del juez: A01

#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <list>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class CarnetPuntos {
private:

	static const int MAX_PUNTOS = 15;

	unordered_map<string, pair<int, list<string>::iterator>> conductores;
	list<string> puntos[MAX_PUNTOS + 1];

public:

	void nuevo(const string& dni) {
		if (conductores.count(dni) == 1) 
			throw domain_error("Conductor duplicado");
		puntos[MAX_PUNTOS].push_front(dni);
		conductores.insert({ dni, { MAX_PUNTOS, puntos[MAX_PUNTOS].begin() } });
	}

	void quitar(const string& dni, const int& punto) {
		if (conductores.count(dni) == 0)
			throw domain_error("Conductor inexistente");
		int quita = max(0, conductores[dni].first - punto);
		if (conductores[dni].first != 0) {
			puntos[conductores[dni].first].erase(conductores[dni].second);
			puntos[quita].push_front(dni);
			conductores[dni] = { quita, puntos[quita].begin() };
		}
	}

	void recuperar(const string& dni, const int& punto) {
		if (conductores.count(dni) == 0)
			throw domain_error("Conductor inexistente");
		int agregar = min(MAX_PUNTOS, conductores[dni].first + punto);
		if (conductores[dni].first != MAX_PUNTOS) {
			puntos[conductores[dni].first].erase(conductores[dni].second);
			puntos[agregar].push_front(dni);
			conductores[dni] = { agregar, puntos[agregar].begin() };
		}
	}

	int consultar(const string& dni) {
		if (conductores.count(dni) == 0)
			throw domain_error("Conductor inexistente");
		return conductores[dni].first;
	}

	int cuantos_con_puntos(const int& punto) {
		if (punto < 0 || punto > MAX_PUNTOS) 
			throw domain_error("Puntos no validos");
		return puntos[punto].size();
	}

	list<string> lista_por_puntos(const int& punto) {
		if (punto < 0 || punto > MAX_PUNTOS)
			throw domain_error("Puntos no validos");
		return puntos[punto];
	}

};

bool resuelveCaso() {
	string orden;
	cin >> orden;
	if (cin.eof())
		return false;
	CarnetPuntos cp;
	while (orden != "FIN") {
		try {
			if (orden == "nuevo") {
				string dni;
				cin >> dni;
				cp.nuevo(dni);
			}
			else if (orden == "quitar") {
				string dni;
				int puntos;
				cin >> dni >> puntos;
				cp.quitar(dni, puntos);
			}
			else if (orden == "recuperar") {
				string dni;
				int puntos;
				cin >> dni >> puntos;
				cp.recuperar(dni, puntos);
			}
			else if (orden == "consultar") {
				string dni;
				cin >> dni;
				int consulta = cp.consultar(dni);
				cout << "Puntos de " << dni << ": " << consulta << "\n";
			}
			else if (orden == "cuantos_con_puntos") {
				int puntos;
				cin >> puntos;
				int cuantosConPuntos = cp.cuantos_con_puntos(puntos);
				cout << "Con " << puntos << " puntos hay " << cuantosConPuntos << "\n";
			}
			else if (orden == "lista_por_puntos") {
				int puntos;
				cin >> puntos;
				list<string> lista = cp.lista_por_puntos(puntos);
				cout << "Tienen " << puntos << " puntos:";
				for (const string& s: lista) {
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