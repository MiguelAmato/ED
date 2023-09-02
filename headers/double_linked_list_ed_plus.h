// Nombre del alumno Miguel Antonio Amato Hermo
// Usuario del Juez A01

#ifndef double_linked_list_ed_plus_h
#define double_linked_list_ed_plus_h

#include "double_linked_list_ed.h"
#include <iostream>
using namespace std;

template <typename T>
class double_linked_list_ed_plus : public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed <T>::Nodo;
public:

	void particion(const int& pivote) {
		Nodo* act = this->fantasma->sig;
		Nodo* ult = this->fantasma->ant;

		while (act->elem <= pivote && act != this->fantasma) { act = act->sig; }
		while (ult->elem > pivote && ult != this->fantasma) { ult = ult->ant; }

		Nodo* ultimoAmirar = ult;

		while (act != ultimoAmirar) {
			if (act->elem > pivote) {
				Nodo* aux = act;
				act = act->sig;
				moverNodo(ult, aux);
				ult = ult->sig;
			}
			else {
				act = act->sig;
			}
		}
	}

	void moverNodo(Nodo* pos, Nodo* mover) {
		mover->sig->ant = mover->ant;
		mover->ant->sig = mover->sig;
		mover->sig = pos->sig;
		mover->ant = pos;
		pos->sig->ant = mover;
		pos->sig = mover;
	}

	// Ejercicios anteriores

	void interseccion(double_linked_list_ed_plus<T>& l) {
			Nodo* aux1 = this->fantasma->sig;
			Nodo* aux2 = l.fantasma->sig;
			while (aux1 != this->fantasma && aux2 != l.fantasma) {
				if (aux1->elem < aux2->elem) {
					Nodo* borrar = aux1;
					aux1 = aux1->sig;
					borrar->sig->ant = borrar->ant;
					borrar->ant->sig = borrar->sig;
					delete borrar;
				}
				else if (aux1->elem > aux2->elem) {
					aux2 = aux2->sig;
				}
				else if (aux1->elem == aux2->elem) {
					aux1 = aux1->sig;
					aux2 = aux2->sig;
				}
			}

			while (aux1 != this->fantasma) {
				Nodo* borrar = aux1;
				aux1 = aux1->sig;
				borrar->sig->ant = borrar->ant;
				borrar->ant->sig = borrar->sig;
				delete borrar;
			}
	}


	void mostrar(ostream& out = cout) const {
		Nodo* aux = this->fantasma->sig;
		if (aux != this->fantasma) {
			out << aux->elem;
			aux = aux->sig;
		}
		while (aux != this->fantasma) {
			out << " " << aux->elem;
			aux = aux->sig;
		}
		out << "\n";
	}

};

#endif 