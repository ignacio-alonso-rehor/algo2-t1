#include "Lista.h"

template <typename T>
Lista<T>::Lista() : _first(nullptr), _last(nullptr) {
}

template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() {
    *this = l;
}

template <typename T>
Lista<T>::~Lista() {
    // Completar
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {
    // Completar
    return *this;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    struct Nodo node = new Nodo();
    node._value = elem;
    if (this->_last == nullptr) {
        this->_last = &node;
        this->_first = &node;
    } else {
        (this->_first)->_prev = &node;
        node._next = this->_first;
        node._prev = nullptr;
        this->first = &node;
    }    
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    struct Nodo node = new Nodo();
    node._value = elem;
    if (this->_first == nullptr) {
        this->_last = &node;
        this->_first = &node;
    } else {
        (this->_last)->_next = &node;
        node._next = nullptr;
        node._prev = this->_last;
        this->_last = &node;
    }
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    struct Nodo **doblePunteroASiguiente = &(this->_first);
    for (int j = 0; j < i; j++) {
        doblePunteroAsiguiente = &((*doblePunteroASiguiente)->_next);
    }
    
}

template <typename T>
int Lista<T>::longitud() const {
    struct Nodo *it = _first;
    int len = 0;
    while (it != nullptr) {len++}
    return len;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    struct Nodo *nd = this->_first;
    for(int j = 0; j < i; j++) {
        nd = nd->_next;
    }
    return &(nd->_value);
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    struct Nodo *nd = this->_first;
    for(int j = 0; j < i; j++) {
        nd = nd->_next;
    }
    return &(nd->_value);
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}
