/*
Contexto: Un edificio cuenta con un sistema de control de accesos a través de tarjetas
magnéticas. Cada vez que una persona entra o sale del edificio, su tarjeta se registra en el
sistema. Queremos implementar un programa que, utilizando una pila, simule el movimiento
de una persona dentro del edificio.
Enunciado:
Implementa un programa en C++ que utilice una pila para simular el movimiento de una
persona en un edificio. Cada vez que la persona entra en un área del edificio (por ejemplo,
"Recepción", "Sala de Reuniones", "Oficina"), se debe apilar el nombre del área. Cuando la
persona sale del área, se debe desapilar el nombre. Al final del día, el programa debe mostrar
el recorrido de la persona en orden inverso al que lo hizo (último lugar visitado al primero).
Entrada:
Serie de operaciones de entrada ("in") o salida ("out") de áreas específicas del edificio.
Salida:
El recorrido completo de la persona en orden inverso, mostrando los lugares que visitó.
Ejemplo: Si la persona visitó las áreas en el siguiente orden:
Entra a "Recepción"
Entra a "Oficina"
Entra a "Sala de Reuniones"
Sale de "Sala de Reuniones"
Entra a "GYM"
El programa debería mostrar:
"GYM"
"Oficina"
"Recepción"
*/

#include<iostream>
#include "Pila/Pila.h"
using namespace std;

int main(){
    Pila<string> pila;
    string accion;
    string lugar;
    cout << "Ingrese recorrido de la persona(Ingrese n para salir)" << endl;
do {
    cout << "Accion(in/out): "; 
    getline(cin, accion);
    
    cout << "Lugar: "; 
    getline(cin, lugar);
    
    if (accion == "in") {
        pila.push(lugar);
    } else if (accion == "out") {
        pila.pop();
        } 
}while(accion=="in" || accion=="out");

while(!pila.esVacia()){
    cout << pila.pop() << "->\n"; 
}

}