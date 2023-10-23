#ifndef LISTA_DE_HPP
#define LISTA_DE_HPP

#include <exception>
#include <cstdlib>
#include "Nodo_de.hpp"

class Lista_exception : public std::exception {
    // Excepcion especifica y exclusivamente para errores dentro de la lista.
    // Usar de la forma "throw lista_exception();" cuando una precondicion no se cumpla.

    // Ejemplo:
    //     if (condicion_de_error()){
    //         throw Lista_exception();
    //     }
};

template<typename T>
class Lista_de {
private:
    Nodo_de<T>* primer_nodo;
    Nodo_de<T>* ultimo_nodo;
    Nodo_de<T>* cursor;
    // Nota: pueden no utilizar el índice. Estado inicial / no válido = -1.
    // La lista es 0-indexed.
    int indice_cursor;
    size_t cantidad_datos;

    // Pre: El índice debe ser menor que la cantidad de datos.
    // Post: Devuelve un puntero al nodo asociado al índice deseado.
    Nodo_de<T>* obtener_nodo(size_t indice){
        if(indice >= cantidad_datos){
            throw Lista_exception();
        }
        if (indice_cursor < indice){
            while (indice_cursor < indice)
            {
                bool siguiente = true;
                avanzar(siguiente);
            }
            return cursor;
        } else if (indice_cursor > indice){
            while (indice_cursor > indice)
            {
                bool siguiente = false;
                avanzar(siguiente);
            }
            return cursor;
        } else {
            return cursor;
        }
    };

public:
    // Constructor.
    Lista_de(){
        primer_nodo = nullptr;
        ultimo_nodo = nullptr;
        indice_cursor = -1;
        cursor = nullptr;
        cantidad_datos = 0;
    };

    // Pre: -
    // Post: Agrega el dato al final de la lista.
    void alta(T dato){
        if (cantidad_datos == 0)
        {
            Nodo_de<T>* nuevo_nodo = new Nodo_de(dato);
            primer_nodo = nuevo_nodo;
            ultimo_nodo = nuevo_nodo;
        } else {
            Nodo_de<T>* nuevo_nodo = new Nodo_de(dato, ultimo_nodo, nullptr);
            ultimo_nodo->siguiente = nuevo_nodo;
            ultimo_nodo = nuevo_nodo;
        }
        cantidad_datos++;
    };

    // Pre: La lista no puede estar vacía.
    // Post: Elimina el último dato.
    // NOTA: Considerar que se puede dar de baja el nodo cursor.
    T baja(){
        bool lista_esta_vacia = vacio();
        if(lista_esta_vacia){
            throw Lista_exception();
        }
        if (cursor = ultimo_nodo){
            T dato_a_devolver = ultimo_nodo->dato;
            cursor = ultimo_nodo->anterior;
            indice_cursor--;
            delete ultimo_nodo;
            ultimo_nodo = cursor;
            ultimo_nodo->siguiente = nullptr;
            cantidad_datos--;
            return dato_a_devolver;
        }
        T dato_a_devolver = ultimo_nodo->dato;
        Nodo_de<T>* aux = ultimo_nodo->anterior;
        delete ultimo_nodo;
        ultimo_nodo = aux;
        ultimo_nodo->siguiente = nullptr;
        cantidad_datos--;
        return dato_a_devolver;
    };

    // Pre: El índice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posición indicada.
    // Si el índice es igual a la cantidad de datos, simplemente agrega al final.
    void alta(T dato, size_t indice){
        if(indice > cantidad_datos){
            throw Lista_exception();
        }
        if(indice == cantidad_datos){
            alta(dato);
        }
        Nodo_de<T>* nuevo_nodo = new Nodo_de(dato);
        nuevo_nodo->anterior = obtener_nodo(indice-1);
        nuevo_nodo->siguiente = obtener_nodo(indice);
        Nodo_de<T>* aux = cursor->anterior;
        cursor->anterior = nuevo_nodo;
        aux->siguiente = nuevo_nodo;
        cantidad_datos++;
    };

    // Pre: El índice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posición indicada.
    // Si el índice es igual a la cantidad de datos - 1, simplemente elimina el último dato.
    // NOTA: Considerar que se puede dar de baja el nodo cursor.
    T baja(size_t indice){
        if(indice >= cantidad_datos){
            throw Lista_exception();
        }
        T dato_a_devolver = elemento(indice);
        Nodo_de<T>* aux = cursor->anterior;
        avanzar(true);
        delete cursor->anterior;
        cursor->anterior = aux;
        cantidad_datos--;
        return dato_a_devolver;
    };

    // Pre: La lista no puede estar vacía.
    // Post: Devuelve el primer dato en la lista.
    T primero(){
        bool lista_esta_vacia = vacio();
        if(lista_esta_vacia){
            throw Lista_exception();
        }
        return primer_nodo->dato{};
    };

    // Pre: La lista no puede estar vacía.
    // Post: Devuelve el último dato en la lista.
    T ultimo(){
        bool lista_esta_vacia = vacio();
        if(lista_esta_vacia){
            throw Lista_exception();
        }
        return ultimo_nodo->dato{};
    };

    // Pre: El índice debe ser menor que la cantidad de datos.
    // Post: Devuelve el dato en la posición deseada.
    T elemento(size_t indice){ 
         if(indice >= cantidad_datos){
            throw Lista_exception();
        }
        if (indice_cursor < indice){
            while (indice_cursor < indice)
            {
                bool siguiente = true;
                avanzar(siguiente);
            }
            return cursor->dato{};
        } else if (indice_cursor > indice){
            while (indice_cursor > indice)
            {
                bool siguiente = false;
                avanzar(siguiente);
            }
            return cursor->dato{};
        } else {
            return cursor->dato{};
        }
        };

    // Pre: -
    // Post: Devuelve true si se puede avanzar (esto es, que el cursor no sea nullptr).
    bool puede_avanzar(){
        return (cursor != nullptr);
    };

    // Pre: Se debe poder avanzar.
    // Post: Devuelve el dato del cursor actual y luego lo mueve una posición en la dirección deseada.
    T avanzar(bool siguiente){
        bool se_puede_avanzar = puede_avanzar();
        if(!se_puede_avanzar){
            throw Lista_exception();
        }
        if(siguiente){
            T dato_a_devolver = cursor->dato{};
            cursor->cursor->siguiente;
            return dato_a_devolver;
        } else {
            T dato_a_devolver = cursor->dato{};
            cursor->cursor->anterior;
            return dato_a_devolver;
        }
    };

    // Pre: -
    // Post: Reinicia el cursor al principio o al final, según lo indicado.
    // Si la lista está vacía, se reinicia el cursor al estado inicial
    // (esto es, cursor = nullptr e indice_cursor = -1).
    void reiniciar_cursor(bool principio){
        bool lista_esta_vacia = vacio();
        if(lista_esta_vacia){
            cursor = nullptr;
            indice_cursor = -1;
        }
        if(principio){
            cursor = primer_nodo;
            indice_cursor = 0;
        } else {
            cursor = ultimo_nodo;
            indice_cursor = cantidad_datos -1;
        }
    };

    // Pre: -
    // Post: Devuelve la cantidad de datos de la lista.
    size_t tamanio(){
        return cantidad_datos;
    };

    // Pre: -
    // Post: Devuelve true si la lista esta vacía (es decir, si no hay datos).
    bool vacio(){
        return (cantidad_datos == 0);
    };

    // El constructor de copia está deshabilitado.
    Lista_de(const Lista_de& l) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Lista_de& l) = delete;

    // Destructor.
    ~Lista_de(){
          Nodo_de<T>* actual = primer_nodo;
        Nodo_de<T>* aux;
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
