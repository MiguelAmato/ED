// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#include "Horas.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
using namespace std;

class Peliculas {
public: 
	Peliculas() : final(Horas()), titulo("") {}
	Peliculas(Horas& fin, string tit) : final(fin), titulo(tit) {}

	bool operator< (Peliculas& p) const {
		if (final < p.final) { return true; }
		else if (final < p.final) { return false; }
		else if (final == p.final) {
			if (titulo < p.titulo) { return true; }
			else if (titulo > p.titulo) { return false; }
			else { return false; }
		}
		else { return false; }
	}

	Horas getHoras() const { return final; }
	string getTitulo() const { return titulo; }

private:
	Horas final;
	string titulo;
};

inline ostream& operator<< (ostream& out, const Peliculas& p) {
	out << p.getHoras() << " " << p.getTitulo();
	return out;
}
 


