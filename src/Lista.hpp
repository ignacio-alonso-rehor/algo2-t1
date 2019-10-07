#include "Lista.h"

template <typename T>
Lista<T>::Lista() : _first(nullptr), _last(nullptr), _len(0) {
}

template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() : _first(nullptr), _last(nullptr), _len(0) {
    struct Nodo *nodo = aCopiar._first;
    while (nodo != nullptr) {
        agregarAdelante(nodo->_elem);
        nodo = nodo->_next;
    }
    return *this;    
}

template <typename T>
Lista<T>::~Lista() {
    struct Nodo *actual = _first;
    struct Nodo *siguiente = nullptr;
    while (actual != nullptr) {
       siguiente = actual->_next;
       delete actual;
       actual = siguiente;
    }
    _first = nullptr;
    _last = nullptr;
    _len = 0;
}
template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {
    struct Nodo *nodo = aCopiar._first;
    while (nodo != nullptr) {
       agregarAdelante(nodo->_elem);
      nodo = nodo->_next; 
    }
    return *this;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    struct Nodo node = new Nodo();
    node._elem = elem;
    if (_last == nullptr) {
        _last = &node;
        _first = &node;
    } else {
        _first->_prev = &node;
        node._next = _first;
        node._prev = nullptr;
        _first = &node;
    }
    _len++;
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    struct Nodo node = new Nodo();
    node._elem = elem;
    if (_first == nullptr) {
        _last = &node;
        _first = &node;
    } else {
        _last->_next = &node;
        node._next = nullptr;
        node._prev = _last;
        _last = &node;
    }
    _len++;
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    if (i == 0) eliminarPrimero();
    else if (i == (_len -1)) eliminarUltimo();
    else {
        struct Nodo **ptrDirNodo = &(_first);
        for (int j = 0; j < i; j++) {
            ptrDirNodo = &((*ptrDirNodo)->_next);
        }
        struct Nodo *ptrNodoEliminar = *ptrDirNodo;
        *ptrDirNodo = (*ptrDirNodo)->_next;
        ptrDirNodo = &((*ptrDirNodo)->_prev)
        *ptrDirNodo = ptrNodoEliminar->_prev;
        delete ptrNodoEliminar;
        _len--;
    }
}

template <typename T>
void Lista<T>::eliminarPrimero() {
    struct Nodo **ptrDirPrimero = &(_first);
    if (*ptrDirPrimero != nullptr) {
        struct Nodo *ptrNodoElminar = *ptrDirPrimero;
        *ptrDirPrimero =  (*ptrDirPrimero)->_next;
        if (_last == ptrNodoEliminar) _last = *ptrDirPrimero;
        delete ptrNodoEliminar;
        _len--;
    }
}

template <typename T>
void Lista<T>::eliminarUltimo() {
    struct Nodo *ptrLast = _last;
    if (ptrLast != nullptr) {
        _last = _last->_prev;
        if (_first = ptrLast) _first = _last;
        delete ptrLast;
        _len--;
    }
}

template <typename T>
int Lista<T>::longitud() const {
    return _len;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    struct Nodo *nodo = _first;
    for(int j = 0; j < i; j++) {
        nodo = nodo->_next;
    }
    return &(nodo->_elem);
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
     struct Nodo *nodo = _first;
    for(int j = 0; j < i; j++) {
        nodo = nodo->_next;
    }
    return &(nodo->_elem);
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    
}
