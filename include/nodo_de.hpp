#ifndef NODO_DE_HPP
#define NODO_DE_HPP

template<typename T>
class Nodo_de {
private:
    T dato{};
    Nodo_de<T>* anterior;
    Nodo_de<T>* siguiente;
public:
    // Constructor.
    Nodo_de(T dato){
        dato{} = dato;
        anterior = nullptr;
        siguiente = nullptr;
    };

    // Constructor.
    Nodo_de(T dato, Nodo_de<T>* anterior, Nodo_de<T>* siguiente){
        dato{} = dato;
        anterior = anterior;
        siguiente = siguiente;
    };

    // Pre: -
    // Post: Devuelve un puntero al nodo anterior.
    Nodo_de<T>* obtener_anterior(){
        return anterior;
    };

    // Pre: -
    // Post: Devuelve un puntero al nodo siguiente.
    Nodo_de<T>* obtener_siguiente(){
        return siguiente;
    };

    // Pre: -
    // Post: Cambia el puntero al nodo anterior.
    void cambiar_anterior(Nodo_de<T>* nuevo){
        anterior = nuevo;
    };

    // Pre: -
    // Post: Cambia el puntero al nodo siguiente.
    void cambiar_siguiente(Nodo_de<T>* nuevo){
        siguiente = nuevo;
    };

    // Pre: -
    // Post: Devuelve el dato almacenado.
    T obtener_dato(){
        return dato{};
    };

    // Destructor.
    ~Nodo_de(){
        delete anterior;
        anterior = nullptr;
        delete siguiente;
        siguiente = nullptr;
    };
};

#endif
