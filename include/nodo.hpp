#ifndef NODO_HPP
#define NODO_HPP

template<typename T>
class Nodo {
private:
    T dato{};
    Nodo<T>* siguiente;
public:
    // Constructor.
    Nodo(T dato){
        dato{} = dato;
        siguiente = nullptr;
    };

    // Pre: -
    // Post: Devuelve un puntero al nodo siguiente.
    Nodo<T>* obtener_siguiente(){
        return siguiente;
    };

    // Pre: -
    // Post: Cambia el puntero al nodo siguiente.
    void cambiar_siguiente(Nodo<T>* nuevo){
        siguiente = nuevo;
    };

    // Pre: -
    // Post: Devuelve el dato almacenado.
    T obtener_dato(){
        return dato{};
    };

    // Destructor.
    ~Nodo(){
        delete siguiente;
        siguiente = nullptr;
    };
};

#endif

#endif
