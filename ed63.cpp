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


class gestor_futbolistas {
private:

	using jugador = string;
	using equipo = string;

	struct infoJugador {
		equipo equipoActual;
		list<jugador>::iterator it;
		unordered_set<equipo> equipos;
	};

	unordered_map<jugador, infoJugador> jugadores;
	unordered_map<equipo, list<jugador>> equipos;

public:

	void fichar(jugador j, equipo e) {
		if (jugadores.count(j) == 1) {
			if (jugadores[j].equipoActual != e) {
				equipos[jugadores[j].equipoActual].erase(jugadores[j].it);
				equipos[e].push_front(j);
				jugadores[j].equipoActual = e;
				jugadores[j].it = equipos[e].begin();
				jugadores[j].equipos.insert(e);
			}
		}
		else {
			equipos[e].push_front(j);
			jugadores[j] = { e, equipos[e].begin(), { e } };
		}
	}

	equipo equipo_actual(jugador j) {
		if (jugadores.count(j) == 0) {
			throw domain_error("Jugador inexistente");
		}
		return jugadores[j].equipoActual;
	}

	int fichados(equipo e) {
		if (equipos.count(e) == 0) {
			throw domain_error("Equipo inexistente");
		}
		return equipos[e].size();
	}

	vector<jugador> ultimos_fichajes(equipo e, int n) {
		if (equipos.count(e) == 0) {
			throw domain_error("Equipo inexistente");
		}
		vector<jugador> ret;
		auto it = equipos[e].begin();
		int i = 0;
		while (i < n && it != equipos[e].end()) {
			ret.push_back(*it);
			++it;
			++i;
		}
		return ret;
	}

	int cuantos_equipos(jugador j) {
		if (jugadores.count(j) == 0) {
			return 0;
		}
		else {
			return jugadores[j].equipos.size();
		}
	}
	// a
};


bool resuelveCaso() {
	string orden;
	cin >> orden;
	if (cin.eof())
		return false;
	gestor_futbolistas gf;
	while (orden != "FIN") {
		try {
			if (orden == "fichar") {
				string jugador, equipo;
				cin >> jugador >> equipo;
				gf.fichar(jugador, equipo);
			}
			else if (orden == "equipo_actual") {
				string jugador;
				cin >> jugador;
				string equipo = gf.equipo_actual(jugador);
				cout << "El equipo de " << jugador << " es " << equipo << "\n";
			}
			else if (orden == "fichados") {
				string equipo;
				cin >> equipo;
				int fichados = gf.fichados(equipo);
				cout << "Jugadores fichados por " << equipo << ": " << fichados << "\n";
			}
			else if (orden == "cuantos_equipos") {
				string jugador;
				cin >> jugador;
				int cuantosEquipos = gf.cuantos_equipos(jugador);
				cout << "Equipos que han fichado a " << jugador << ": " << cuantosEquipos << "\n";
			}
			else if (orden == "ultimos_fichajes") {
				string equipo;
				int n;
				cin >> equipo >> n;
				vector<string> v = gf.ultimos_fichajes(equipo, n);
				cout << "Ultimos fichajes de " << equipo << ":";
				for (const string& s : v) {
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