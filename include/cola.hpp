#ifndef COLA_HPP
#define COLA_HPP

#include <exception>
#include "Nodo.hpp"

class Cola_exception : public std::exception {
    // Excepcion especifica y exclusivamente para errores dentro de la cola.
    // Usar de la forma "throw Cola_exception();" cuando una precondicion no se cumpla.

    // Ejemplo:
    //     if (condicion_de_error()){
    //         throw cola_exception();
    //     }
};

template<typename T>
class Cola {
private:
    Nodo<T>* primer_nodo;
    Nodo<T>* ultimo_nodo;
    size_t cantidad_datos;
public:
    // Constructor.
    Cola(){
        cantidad_datos = 0;
        primer_nodo = nullptr;
        ultimo_nodo = nullptr;
    };

    // Pre: -
    // Post: Agrega el dato al final de la cola.
    void alta(T dato){
        if(cantidad_datos == 0){
            Nodo<T>* nuevo_nodo = new Nodo(dato);
            primer_nodo = nuevo_nodo;
            ultimo_nodo = nuevo_nodo;
        } else {
        Nodo<T>* nuevo_nodo = new Nodo(dato);
        ultimo_nodo->siguiente = nuevo_nodo;
        ultimo_nodo = nuevo_nodo;
        cantidad_datos++;
        }
    };

    // Pre: La cola no puede estar vacía.
    // Post: Elimina el primer dato.
    T baja(){
        bool cola_esta_vacia = vacio();
        if (cola_esta_vacia){
            throw Cola_exception();
        }
        T dato_a_devolver = primer_nodo->dato;
        cantidad_datos--;
        Nodo<T>* aux = primer_nodo->siguiente;
        delete primer_nodo;
        primer_nodo = aux;
        return dato_a_devolver;
    };

    // Pre: La cola no puede estar vacía.
    // Post: Devuelve el primer dato en la cola.
    T primero(){
        bool cola_esta_vacia = vacio();
        if (cola_esta_vacia){
            throw Cola_exception();
        }
        return primer_nodo->dato;
    };

    // Pre: La cola no puede estar vacía.
    // Post: Devuelve el último dato en la cola.
    T ultimo(){
        bool cola_esta_vacia = vacio();
        if (cola_esta_vacia){
            throw Cola_exception();
        }
        return ultimo_nodo->dato;
    };

    // Pre: -
    // Post: Devuelve la cantidad de datos de la cola.
    size_t tamanio(){
        return cantidad_datos
    };

    // Pre: -
    // Post: Devuelve true si la cola esta vacía (es decir, si no hay datos).
    bool vacio(){
        return (cantidad_datos == 0);
    };

    // El constructor de copia está deshabilitado.
    Cola(const Cola& l) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Cola& l) = delete;

    // Destructor.
    ~Cola(){
        Nodo<T>* actual = primer_nodo;
        Nodo<T>* aux;
        for(int i = 0; i < cantidad_datos; i++){
            aux = actual->siguiente;
            delete actual;
            actual = aux;
        }
        actual = nullptr;
        aux = nullptr;
     };
};

#endif
