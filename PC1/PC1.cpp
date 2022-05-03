#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

#include "Archivo.h"
#include "RegistroGasto.h"
#include "RegistroIngreso.h"

using namespace std;
using namespace System;

//GESTION DE CONTROL DE GASTOS - Monefy
//GRUPO 8

int SumIngreso(int a, int b) { //Tiempo asintótico O(1)
    int x; // 1
    x = a + b; // 2
    return x;//1
}//Tiempo detallado = 2 + 1 +1 = 4

void menu(Lista<int>*gastito, Lista2<int>* ingresito) {
    int op = 0;
    Archivo* archivo = new Archivo();
    int saldo = archivo->getSaldo();
    float nsaldo = saldo;    

    int SumGastos = 0;
    int SumIngresos = 0;
    int gasto = 0;
    int ingreso = 0;
    int gastoc = 0;
    int gastot = 0;
    int gastoe = 0;
    int base = 0;
    int n = 0;
    float mayoringreso = 0;
    float menoringreso = 0;
    int mayorcatgasto = 0;
    int menorCatGasto = 0;
    char cat;

    do {
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t\t   GASTODITO" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t\t SALDO: " << saldo << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t1. Registrar gasto" << endl;
        cout << "\t\t\t\t\t2. Registrar ingreso" << endl;
        cout << "\t\t\t\t\t3. Mostrar el número de ingresos y el total ingresado" << endl;
        cout << "\t\t\t\t\t4. Mostrar el número de gastos y el total gastado" << endl;
        cout << "\t\t\t\t\t5. Mostrar el promedio de Gastos" << endl;
        cout << "\t\t\t\t\t6. Mostrar el promedio de Ingresos" << endl;
        cout << "\t\t\t\t\t7. Mostrar el porcentaje de ingresos gastados" << endl;
        cout << "\t\t\t\t\t8. Mostrar el mayor y menor monto ingresado: " << endl;
        cout << "\t\t\t\t\t9. Mostrar el área en el que se gastó más" << endl;
        cout << "\t\t\t\t\t10. Mostrar el área en el que se gastó menos" << endl;
        cout << "\t\t\t\t\t11. Crear historial de gastos" << endl;
        cout << "\t\t\t\t\t12. Mostrar ordenamiento de Ingresos de Mayor a menor" << endl;
        cout << "\t\t\t\t\t13. Mostrar ordenamiento de Gastos de mayor a menor" << endl;
        cout << "\t\t\t\t\t14. Mostrar ordenamiento de Ingresos de menor a mayor" << endl;
        cout << "\t\t\t\t\t15. Mostrar ordenamiento de gastos de menor a mayor" << endl;
        cout << "\t\t\t\t\t16. Mostrar ordenamiento aleatorio de gastos" << endl;
        cout << "\t\t\t\t\t17. Mostrar ordenamiento aleatorio de ingresos" << endl;
        cout << "\t\t\t\t\t18. Salir" << endl;
        cout << "\t\t\t\t\tIngresa una opción: "; cin >> op;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        switch (op) {
        case 1: 
            cout << "\tIngrese el monto gastado: "; cin >> gasto;
            SumGastos += gasto;
            gastito->agregarElementoVector(gasto);
            gastito->agregar(gasto);
            do {
                cout << "\tCategorías: C - Comida, T - Transportes o E - Entretenimiento" << endl;
                cout << "\tIngrese la categoría del gasto : "; cin >> cat;
                saldo = saldo - gasto;
                cout << "-------------------------------" << endl;
            } while (cat != 'C' && cat != 'T' && cat != 'E');
            if (cat == 'C') {
                gastoc += gasto;
            }
            else if (cat == 'T') {
                gastot += gasto;
            }
            else {
                gastoe += gasto;
            }
            cout << "\tGasto registrado exitosamente!!" << endl;
            break;
        case 2:
            cout << "\tIngrese el monto de ingreso: "; cin >> ingreso;
            saldo = SumIngreso(saldo, ingreso);
            nsaldo += ingreso; //tener primer ingreso 
            SumIngresos += ingreso; 
            ingresito->agregarElementoVector(ingreso);
            ingresito->agregar(ingreso);
            if (n == 0) { //para tener el primer ingreso como el menor 
                menoringreso = ingreso;
                n++;
            }
            else {
                menoringreso = ingresito->ingresoMenor(menoringreso, ingreso);
            }
            if (mayoringreso < ingreso) {
                mayoringreso = ingreso;
            }
            cout << "\tIngreso registrado exitósamente!!" << endl;
            break;
        case 3:
            cout << "-------------------------------" << endl;
            cout << "\tCantidad de ingresos: " << ingresito->longitud() << endl;
            cout << "\tMonto total ingresado: " << SumIngresos << endl;
            break;
        case 4:
            cout << "-------------------------------" << endl;
            cout << "\tCantidad de gastos: " << gastito->longitud() << endl;
            cout << "\tMonto total gastado: " << SumGastos << endl;
            break;
        case 5:
            cout << "-------------------------------" << endl;
            gastito->PromedioDeGastos(SumGastos);
            break;
        case 6:
            cout << "-------------------------------" << endl;
            ingresito->PromedioDeIngresos(SumIngresos);
            break;
        case 7:
            cout << "-------------------------------" << endl;
            ingresito->PorcentajeDeIngresosGastado(SumGastos, nsaldo);
            break;
        case 8:
            cout << "-------------------------------" << endl;
            ingresito->ingresoMayor(mayoringreso, 0);
            cout << "El menor monto ingresado fue: " << menoringreso << endl;
            break;
        case 9:
            if (gastoc > gastoe && gastoc > gastot) {mayorcatgasto = 0; }
            else if(gastoe > gastoc && gastoe > gastot) {mayorcatgasto = 1;}
            else if (gastot > gastoe && gastot > gastoc) {mayorcatgasto = 2;}

            gastito->CatMayorGasto(mayorcatgasto,base);

            break;

        case 10:
            if (gastoc < gastoe && gastoc < gastot) { menorCatGasto = 0; }
            else if (gastoe < gastoc && gastoe < gastot) { menorCatGasto = 1;}
            else if (gastot < gastoe && gastot < gastoc) { menorCatGasto = 2; }

            gastito->CatMenorGasto(menorCatGasto, base);

            break;

        case 11: 
            archivo->escribir(gasto, ingreso, cat, saldo, op);
            cout << "-------------------------------" << endl;
            cout << "\tHistorial creado correctamente en archivo de texto!!!" << endl; 
            break;
        case 12:
            ingresito->OrdMayorMenor();
            break;
        case 13:
            gastito->OrdMayorMenor(); break;
        case 14:
            ingresito->OrdMenorMayor(); break;
        case 15:
            gastito->OrdMenorMayor(); break;
        case 16:
            gastito->randomize(); break;
        case 17:
            ingresito->randomize(); break;
        case 18:
            exit(19); break;
        }
        cout << "\n\t\t........Presione una tecla para elegir otra opción" << endl;
        getch();
        system("cls");
    } while (op != 19);
}


int main() {
    setlocale(LC_ALL, "spa");

    Lista<int>* lista = new Lista<int>();
    Lista2<int>* lista2 = new Lista2<int>();
 
    menu(lista, lista2);

    getch();
    return 0;
}
