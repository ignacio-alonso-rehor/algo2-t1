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
    // Completar
}

template <typename T>
int Lista<T>::longitud() const {
    // Completar
    return -1;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    // Completar
    assert(false);
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    assert(false);
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}
