// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#ifndef linked_list_ed_plus_h
#define linked_list_ed_plus_h

#include "linked_list_ed.h"
#include <iostream>
using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
	using Nodo = typename linked_list_ed <T>::Nodo;
public:

	void mezclar(linked_list_ed_plus& l) {
		if (l.prim != nullptr) {
			if (this->prim == nullptr) {
				this->prim = l.prim;
				this->ult = l.ult; 
			}
			else {
				Nodo* ant = this->prim;
				Nodo* act = this->prim->sig;
				if (this->prim->elem >= l.prim->elem) {
					this->prim = l.prim;
					l.prim = l.prim->sig;
					this->prim->sig = ant;
				}
				ant = this->prim;
				act = ant->sig;
				while (l.prim != nullptr) {
					if (act == nullptr) {
						ant->sig = l.prim;
						l.prim = l.prim->sig;
						ant->sig->sig = nullptr;
						ant = ant->sig;
					}
					else if (act->elem < l.prim->elem) {
						act = act->sig;
						ant = ant->sig;
					}
					else if (act->elem >= l.prim->elem) {
						ant->sig = l.prim;
						l.prim = l.prim->sig;
						ant->sig->sig = act;
						ant = ant->sig;
					}
				}
				if (act == nullptr) {
					this->ult = ant;
				}
			}
			l.ult = nullptr;
			l.prim = nullptr;
		}
	}

	// Metodos usados en otro ejercicio

	void eliminarRepetidos() {
		Nodo* act = this->prim->sig;
		Nodo* ant = this->prim;
		while (act != nullptr) {
			if (act->elem == ant->elem) {
				ant->sig = act->sig;
				delete act;
				act = ant->sig;
			}
			else {
				act = act->sig;
				ant = ant->sig;
			}
		}
		this->ult = ant;
	}

	void eliminaPares() {
		if (this->prim->sig != nullptr) { 
			Nodo* aux = this->prim->sig;
			this->prim->sig = aux->sig;
			Nodo* act = aux->sig;
			delete aux;
			while (act != nullptr && act->sig != nullptr) {
				aux = act->sig;
				act->sig = aux->sig;
				act = aux->sig;
				delete aux;
			}
		}
	}


	void mostrar(ostream & out = cout) const {
		Nodo* aux = this->prim;
		if (aux != nullptr) {
			out << aux->elem;
			aux = aux->sig;
		}
		while (aux != nullptr) {
			out << " " << aux->elem;
			aux = aux->sig;
		}
		out << "\n";
	}

	void duplicar() {
		Nodo* aux = this->prim;
		if (aux != nullptr) {
			while (aux->sig != nullptr) {
				Nodo* cop = new Nodo(aux->elem, aux->sig);
				aux->sig = cop;
				aux = cop->sig;
			}
			Nodo* cop = new Nodo(aux->elem, aux->sig);
			aux->sig = cop;
			aux = cop->sig;
		}
	}
};



#endif 


/*
*/