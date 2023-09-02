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

class iPud {
private:

	using cancion = string;
	using artista = string;
	using duracion = int;

	struct infoCancion {
		artista a;
		duracion d;
		list<cancion>::iterator actIt;
		list<cancion>::iterator repIt;
	};

	int duracionTotal;
	unordered_map<cancion, infoCancion> canciones;
	list<cancion> actual;
	list<cancion> reproducidas;

	// a

public:

	void addSong(const cancion& s, const artista& a, const duracion& d) {
		if (canciones.count(s) == 1)
			throw domain_error("addSong");
		canciones[s] = { a, d, actual.end(), reproducidas.end() };
	}

	void addToPlaylist(const cancion& s) {
		if (canciones.count(s) == 0)
			throw domain_error("addToPlaylist");
		if (canciones[s].actIt == actual.end()) {
			actual.push_back(s);
			duracionTotal += canciones[s].d;
			canciones[s].actIt = --actual.end();
		}
	}

	cancion current() {
		if (actual.empty())
			throw domain_error("current");
		return *actual.begin();
	}

	cancion play() {
		if (!actual.empty()) {
			cancion primera = *actual.begin();
			actual.pop_front();
			duracionTotal -= canciones[primera].d;
			canciones[primera].actIt = actual.end();
			if (canciones[primera].repIt != reproducidas.end()) {
				reproducidas.erase(canciones[primera].repIt);
			}
			reproducidas.push_front(primera);
			canciones[primera].repIt = reproducidas.begin();
		}
	}

	cancion getRecentSong() {
		if (reproducidas.empty()) {
			return 
		}
	}

	duracion totalTime() const {
		return duracionTotal;
	}

	list<cancion> recent(const int& n) {
		list<cancion> ret;
		if (!reproducidas.empty()) {
			auto it = reproducidas.begin();
			int i = 0;
			while (i < n && it != reproducidas.end()) {
				ret.push_back(*it);
				++it;
				++i;
			}
		}
		return ret;
	}

	void deleteSong(const cancion& s) {
		if (canciones.count(s) != 0) {
			if (canciones[s].actIt != actual.end()) {
				actual.erase(canciones[s].actIt);
				duracionTotal -= canciones[s].d;
			}
			if (canciones[s].repIt != reproducidas.end())
				reproducidas.erase(canciones[s].repIt);
			canciones.erase(s);
		}
	}
};

bool resuelveCaso() {
	string orden;
	cin >> orden;
	if (cin.eof())
		return false;
	iPud i;
	while (orden != "FIN") {
		try {
			if (orden == "addSong") {
				string s, a;
				int d;
				cin >> s >> a >> d;
				i.addSong(s, a, d);
			}
			else if (orden == "addToPlaylist") {
				string s;
				cin >> s;
				i.addToPlaylist(s);
			}
			else if (orden == "current") {
				string current = i.current();
			}
			else if (orden == "play") {
				string c = i.play();
				cout << "Sonando " << c << '\n';
			}
			else if (orden == "totalTime") {
				int total = i.totalTime();
				cout << "Tiempo total " << total << "\n";
			}
			else if (orden == "recent") {
				int n;
				cin >> n;
				list<string> r = i.recent(n);
				if (r.empty()) {
					cout << "No hay canciones recientes en su lugar\n";
				}
				else {
					cout << "Las " << (int)r.size() << " mas recientes\n";
					for (const string& s : r) {
						cout << "    " << s << "\n";
					}
				}
			}
			else if (orden == "deleteSong") {
				string s;
				cin >> s;
				i.deleteSong(s);
			}
		}
		catch (std::domain_error& e) {
			cout << "ERROR " << e.what() << "\n";
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