#pragma once
#include <functional>
using namespace std;
using namespace System;
typedef unsigned int uint;

template <typename T, T NADA = 0>
class Lista2 {
private:
	struct Nodo;

	Nodo* ini;
	uint lon; //numero de elementos

	vector<float>myvector;
public:
	Lista2() : ini(nullptr), lon(0) {}
	~Lista2() {}

	void agregar(T elem);
	void agregarElementoVector(int);
	void PromedioDeIngresos(int);
	void PorcentajeDeIngresosGastado(float, float);
	void ingresoMayor(float, int);
	float ingresoMenor(float, float);
	void OrdMayorMenor();
	void OrdMenorMayor();
	void swap(float*,float*);
	void randomize();
	uint longitud();
	string vectorCat[3] = { "Cocina", "Entretenimiento","Transporte" };
};

template <typename T, T NADA>
struct Lista2<T, NADA>::Nodo {
	T       elem;
	Nodo* sig; // puntero apunta al siguiente nodo

	Nodo(T elem = NADA, Nodo* sig = nullptr) : elem(elem), sig(sig) {}
};

template<typename T, T NADA>
void Lista2<T, NADA>::agregarElementoVector(int n) {
	myvector.push_back(n);
}

template <typename T, T NADA>
void Lista2<T, NADA>::ingresoMayor(float n, int cont) {

	if (n == myvector[cont]) {
		cout << "El mayor monto ingresado fue: " << myvector[cont] << endl;
	}
	else {
		ingresoMayor(n, cont + 1);
	}
}

template <typename T, T NADA>
void Lista2<T, NADA>::agregar(T elem) {
	Nodo* nuevo = new Nodo(elem, ini);
	if (nuevo != nullptr) {
		ini = nuevo;
		lon++;
	}
}

template <typename T, T NADA>
void Lista2<T, NADA>::PromedioDeIngresos(int ingresos) {
	int prom = [](int x, int y) {return x/ y; }(ingresos, lon);
	cout << "El promedio de ingresos por cada vez que se recibió dinero es: " << prom << endl;
}

template <typename T, T NADA>
void Lista2<T, NADA>::PorcentajeDeIngresosGastado(float totalgastos, float totalingresos){
	auto porcen = [](float x, float y) {return x / y; };
	cout << "El porcentaje de ingresos gastados es: " << porcen(totalgastos,totalingresos) * 100 << "%" << endl;
}

template <typename T, T NADA>
float Lista2<T, NADA>::ingresoMenor(float menor, float aux) {
	if (menor < aux) {
		return menor;
	}
	else {
		return aux;
	}
}

template <typename T, T NADA>
uint Lista2<T, NADA>::longitud() {
	return lon;
}

template <typename T, T NADA>
void Lista2<T, NADA>::OrdMayorMenor() {
	for (int i = 0; i < myvector.size()-1; i++)
	{
		for (int k = i+1; k < myvector.size(); k++)
		{
			if (myvector[i] < myvector[k]) {
				int aux = myvector[i];
				myvector[i] = myvector[k];
				myvector[k] = aux;
			}
		}
	}
	for (int i = 0; i < myvector.size(); i++)
	{
		cout << "[" << myvector[i] << "] ";
	}

}
template <typename T, T NADA>
void Lista2<T, NADA>::OrdMenorMayor() {
	for (int i = 0; i < myvector.size() - 1; i++)
	{
		for (int k = i + 1; k < myvector.size(); k++)
		{
			if (myvector[i] > myvector[k]) {
				int aux = myvector[i];
				myvector[i] = myvector[k];
				myvector[k] = aux;
			}
		}
	}
	for (int i = 0; i < myvector.size(); i++)
	{
		cout << "[" << myvector[i] << "] ";
	}

}

template <typename T, T NADA>
void Lista2<T, NADA>::swap(float* a, float* b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <typename T, T NADA>
void Lista2<T, NADA>:: randomize() {
	for (int i = myvector.size() - 1; i >= 0; i--) {
		int j = rand() % (i + 1);
		swap(&myvector[i], &myvector[j]);
		cout << "[" << myvector[i] << "]" << " ";
	}
}
