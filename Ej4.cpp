/*
Crear un programa que solicite números enteros al usuario hasta que desee, almacenar los
números en una pila y pedir también un número entero "n". Luego crear una función que
reciba una pila y un número entero “n”, si el "n" se encuentra en una de las posiciones de la
pila, devuelve la suma de los números en cada una de las posiciones de la pila hasta llegar a
"n" (sin incluir a n), si el número "n" no se encuentra en la pila, la función devuelve la suma de
todos los elementos de la pila. Imprimir primero la pila antes de sumar sus elementos
*/

#include <iostream>
#include "Pila/Pila.h"  // Incluye la biblioteca de la pila

using namespace std;

int sumarHastaN(Pila<int>& pila, int n){
    Pila<int> pilaAux;
    int suma = 0;
    bool encontrado = false;

    //Sumo los elementos y verifico si el numero n esta en la pila
    while(!pila.esVacia()){
        int valor = pila.pop();
        if(valor == n){ //Si el numero n esta en la pila, no lo sumo y marco como encontrado el booleano y termino la funcion
            encontrado = true;
            pilaAux.push(valor);
            break; 
        } else { // Si el numero n no esta en la pila, sumo el ultimo valor de la pila
            suma += valor;
            pilaAux.push(valor);
        }
    }

    // Restauro la pila original
    while(!pilaAux.esVacia()){
        pila.push(pilaAux.pop());
    }

    // Suma si no esta n, y restauro la pila original
    if(!encontrado){
        int sumaTotal = 0;
        while(!pila.esVacia()){
            sumaTotal += pila.pop();
        }
        while(!pilaAux.esVacia()){
            pila.push(pilaAux.pop());
        }
        return sumaTotal;
    }
    return suma;   
}

void mostrar(Pila<int>& pila){
    Pila<int> pilaAux;
    while(!pila.esVacia()){
        int valor = pila.pop();
        cout << valor << " ";
        pilaAux.push(valor);
    }
    cout << endl;

    while(!pilaAux.esVacia()){
        pila.push(pilaAux.pop());
    }
}

int main(){

    Pila<int> pila;
    int numero, n;

    // Solicitar números enteros al usuario y almacenarlos en la pila
    cout << "Ingrese numeros enteros (ingrese -1 para terminar): " << endl;
    do{
        cout << "Ingrese un numero: ";
        cin >> numero;
        if(numero != -1){
            pila.push(numero);
        }
    } while(numero != -1);

    // Solicitar el número entero "n"
    cout << "Ingrese el numero entero 'n': ";
    cin >> n;

    // Mostrar la pila antes de la operación
    cout << "Pila antes de sumar: ";
    mostrar(pila);

    // Sumar los elementos según la posición de "n"
    int suma = sumarHastaN(pila, n);

    // Mostrar el resultado de la suma
    cout << "La suma de los elementos es: " << suma << endl;

    return 0;
}