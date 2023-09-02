// Alumno: Miguel Antonio Amato Hermo
// Usuario del juez: A01

#include <unordered_map>
#include <map>
#include <set>
#include <list>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class urgencias {
private:

	static const int MAX = 3;

	unordered_map<string, pair<int, list<string>::iterator>> pacientes;
	list<string> sala[MAX];
	set<string> set_recuperados;

public:

	void nuevo_paciente(string paciente, int gravedad) {
		if (pacientes.count(paciente) == 1) 
			throw domain_error("Paciente repetido");
		if (gravedad < 1 || gravedad > MAX) 
			throw domain_error("Gravedad incorrecta");
		sala[gravedad - 1].push_back(paciente);
		pacientes.insert({ paciente, {gravedad, --sala[gravedad - 1].end() } });
	}

	int gravedad_actual(string paciente) {
		if (pacientes.count(paciente) == 0)
			throw domain_error("Paciente inexistente");
		return pacientes[paciente].first;
	}

	string siguiente() {
		string sig;
		if (!sala[MAX - 1].empty()) {
			sig = sala[MAX - 1].front();
			sala[MAX - 1].pop_front();
		}
		else if (!sala[MAX - 2].empty()) {
			sig = sala[MAX - 2].front();
			sala[MAX - 2].pop_front();
		}
		else if (!sala[MAX - 3].empty()) {
			sig = sala[MAX - 3].front();
			sala[MAX - 3].pop_front();
		}
		else {
			throw domain_error("No hay pacientes");
		}
		pacientes.erase(sig);
		return sig;
	}

	void mejora(string paciente) {
		if (pacientes.count(paciente) == 0)
			throw domain_error("Paciente inexistente");
		if (pacientes[paciente].first == 1) {
			sala[0].erase(pacientes[paciente].second);
			pacientes.erase(paciente);
			set_recuperados.insert(paciente);
		}
		else {
			sala[pacientes[paciente].first - 1].erase(pacientes[paciente].second);
			sala[pacientes[paciente].first - 2].push_front(paciente);
			--pacientes[paciente].first;
			pacientes[paciente].second = sala[pacientes[paciente].first - 1].begin();
		}
	}

	vector<string> recuperados() {
		vector<string> ret;
		for (const string& s: set_recuperados) {
			ret.push_back(s);
		}
		return ret;
	}

};


bool resuelveCaso() {
	string orden;
	cin >> orden;
	if (cin.eof())
		return false;
	urgencias u;
	while (orden != "FIN") {
		try {
			if (orden == "nuevo_paciente") {
				string nombre;
				int gravedad;
				cin >> nombre >> gravedad;
				u.nuevo_paciente(nombre, gravedad);
			}
			else if (orden == "gravedad_actual") {
				string nombre;
				cin >> nombre;
				int gravedad = u.gravedad_actual(nombre);
				cout << "La gravedad de " << nombre << " es " << gravedad << "\n";
			}
			else if (orden == "siguiente") {
				string siguiente = u.siguiente();
				cout << "Siguiente paciente: " << siguiente << "\n";
			}
			else if (orden == "mejora") {
				string nombre;
				cin >> nombre;
				u.mejora(nombre);
			}
			else if (orden == "recuperados") {
				vector<string> v = u.recuperados();
				cout << "Lista de recuperados:";
				for (const string& s: v) {
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