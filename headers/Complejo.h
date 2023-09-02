#include <iostream>
#include <math.h>
using namespace std;

template <typename r, typename i>
class Complejo {
public:
	Complejo() : real(0), im(0) {}
	Complejo(r _real, i _imaginaria) : real(_real), im(_imaginaria) {}

	Complejo operator+ (Complejo const& aux) {
		return Complejo<r, i>(this->real + aux.real, this->im + aux.im);
	}

	Complejo operator* (Complejo const& aux) {
		return Complejo<r, i>((this->real * aux.real) - (this->im * aux.im) , (this->real * aux.im) + (aux.real * this->im));
	}

	float modulo() {
		return sqrt((real * real) + (im * im));
	}
	
private:
	r real;
	i im;
};
