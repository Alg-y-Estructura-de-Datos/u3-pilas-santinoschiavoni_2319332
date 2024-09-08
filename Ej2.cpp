/*
Escribir  una  función  Reemplazar  que  tenga  como  argumentos  una  pila  con  tipo  de 
elemento int y dos valores int: nuevo y viejo de forma que, si el segundo valor aparece en algún 
lugar de la pila, sea reemplazado por el segundo.
*/

#include <iostream>
#include "Pila/Pila.h"
#include <limits>
using namespace std;

void reemplazar(Pila<int> &pila, int nuevo, int viejo){
    Pila<int> pilaAux;

    while(!pila.esVacia()){
        int valor = pila.pop();
        if(valor == viejo){
            pilaAux.push(nuevo);
        } else {
            pilaAux.push(valor);
        }
    }
    while(!pilaAux.esVacia()){
        pila.push(pilaAux.pop());
    }
}

void mostrarPila(Pila<int>& pila) {
    Pila<int> pilaAux;

    // Desapilar elementos para mostrar sin perderlos
    while (!pila.esVacia()) {
        int valor = pila.pop();
        cout << valor << " ";
        pilaAux.push(valor);
    }
    cout << endl;

    // Restaurar la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}


int main() {
    int num,nuevo,viejo;
    Pila<int> pila;

    while (true) {
        cout << "Ingrese los numeros de la pila(ingrese q para finalizar)" << endl;
        cout << "Numero: ";
        if (cin >> num) {
            pila.push(num);
        } else {
            cin.clear(); // Limpiar el estado de error del stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar entrada incorrecta
            break; // Salir del bucle cuando se ingresa algo que no es un número
        }
    }

    cout << "Mostrar antes reemplazo" << endl;
    mostrarPila(pila);
    cout << "" <<endl;
    cout << "Ingrese el nuevo numero: "; cin >> nuevo;
    cout << "Ingrese el viejo numero: "; cin >> viejo;
    cout << "Cambiado Correctamente********" << endl;
    cout << "Nueva pila: " << endl;
    reemplazar(pila,nuevo,viejo);
    mostrarPila(pila);
    return 0;
}
