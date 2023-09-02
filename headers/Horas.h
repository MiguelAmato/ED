#pragma once

#include <stdexcept>
#include <iostream>
#include <iomanip>
using namespace std;

class Horas {

public:

	Horas() : hora(0), min(0), seg(0) {}

	Horas(int h, int m, int s) : hora(h), min(m), seg(s) {
		if (0 > hora || hora >= 24 || 0 > min || min >= 60 || 0 > seg || seg >= 60) {
			throw invalid_argument("ERROR\n");
		}
	}

	int getHora() const { return hora; }
	int getMin() const { return min; }
	int getSeg() const { return seg; }

	bool operator== (const Horas& aux) const {
		return (hora == aux.hora && min == aux.min && seg == aux.seg);
	}

	bool operator< (const Horas& aux) const {
		if (hora < aux.hora) return true;
		else if (hora > aux.hora) return false;
		else if (min < aux.min) return true;
		else if (min > aux.min) return false;
		else if (seg < aux.seg) return true;
		else return false;

	}

	Horas operator+ (Horas& aux) const {
		int sumSeg, sumMin, sumH;
		int ac = 0;
		sumSeg = seg + aux.seg;
		if (sumSeg > 59) {
			ac = (sumSeg / 60);
			sumSeg = sumSeg % 60;
		}
		sumMin = min + aux.min + ac;
		ac = 0;
		if (sumMin > 59) {
			ac = (sumMin / 60);
			sumMin = sumMin % 60;
		}
		sumH = hora + aux.hora + ac;
		if (sumH > 23) {
			throw overflow_error("hoy no\n");
		}
		return Horas(sumH, sumMin, sumSeg);
	}

private:

	int hora, min, seg;

};

inline istream& operator>> (istream& in, Horas& hora) {
	int h, m, s;
	char p;
	in >> h >> p >> m >> p >> s;
	hora = Horas(h, m, s);
	return in;
}

inline ostream& operator<< (ostream& out, const Horas& hora) {
	cout.fill('0');
	cout.width(2);
	out << right << hora.getHora() << ":";
	cout.fill('0');
	cout.width(2);
	out << right << hora.getMin() << ":";
	cout.fill('0');
	cout.width(2);
	out << right << hora.getSeg();
	return out;
}
