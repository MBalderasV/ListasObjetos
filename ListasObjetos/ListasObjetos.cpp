// ListasObjetos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

// 1. Definimos la clase Nodo
class Nodo {
public:
    int dato;           // El valor que guarda el nodo (podría ser un objeto complejo también)
    Nodo* siguiente;    // Puntero al siguiente nodo de la lista

    // Constructor del nodo
    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr; // Por defecto, un nuevo nodo no apunta a nada
    }
};

// 2. Definimos la clase Lista
class ListaEnlazada {
private:
    Nodo* cabeza;       // Puntero al primer elemento de la lista

public:
    // Constructor: inicializa la lista vacía
    ListaEnlazada() {
        cabeza = nullptr;
    }

    // Método para agregar un nodo al final de la lista
    void insertarAlFinal(int valor) {
        Nodo* nuevoNodo = new Nodo(valor); // Creamos el nodo en memoria dinámica

        // Si la lista está vacía, el nuevo nodo es la cabeza
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            return;
        }

        // Si no está vacía, recorremos la lista hasta llegar al último nodo
        Nodo* temporal = cabeza;
        while (temporal->siguiente != nullptr) {
            temporal = temporal->siguiente;
        }

        // Enlazamos el último nodo con el nuevo
        temporal->siguiente = nuevoNodo;
    }

    // Método para imprimir la lista
    void mostrar() const {
        if (cabeza == nullptr) {
            std::cout << "La lista esta vacia.\n";
            return;
        }

        Nodo* temporal = cabeza;
        std::cout << "Lista: ";
        while (temporal != nullptr) {
            std::cout << "[" << temporal->dato << "] -> ";
            temporal = temporal->siguiente; // Avanzamos al siguiente nodo
        }
        std::cout << "nullptr\n"; // Indica el final de la lista
    }

    // Destructor: MUY IMPORTANTE en C++ para liberar la memoria dinámica
    ~ListaEnlazada() {
        Nodo* temporal = cabeza;
        while (temporal != nullptr) {
            Nodo* siguienteNodo = temporal->siguiente;
            delete temporal; // Liberamos la memoria del nodo actual
            temporal = siguienteNodo;
        }
    }
};

int main() {
    // Instanciamos nuestra lista
    ListaEnlazada miLista;

    // Agregamos elementos
    miLista.insertarAlFinal(10);
    miLista.insertarAlFinal(20);
    miLista.insertarAlFinal(30);

    // Mostramos la lista
    miLista.mostrar(); // Salida: Lista: [10] -> [20] -> [30] -> nullptr

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
