#include "Lista.h"

template <typename T>
Lista<T>::Lista() : _first(nullptr), _last(nullptr), _size(0){
}

template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() {
    *this = l;
}

template <typename T>
Lista<T>::~Lista() {
    deleteList();
}

template<typename T>
void Lista<T>::deleteList() {
    struct Nodo* pNodo = this->_first;
    while (pNodo != nullptr) {
        struct Nodo* tmp = pNodo;
        pNodo = pNodo->next;
        delete tmp->data;
        delete tmp;
    }
    this->_first = nullptr;
    this->_last = nullptr;
    this->_size = 0;
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {
    this->deleteList();
    struct Nodo* pNodo = aCopiar._first;
    while (pNodo != nullptr) {
        this->agregarAtras(*(pNodo->data));
        pNodo = pNodo->next;
    }
    return *this;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    struct Nodo* pNodo = new Nodo(elem);
    this->_size++;
    if (this->_last == nullptr) {
        this->_last = pNodo;
        this->_first = pNodo;
        return;
    }
    pNodo->next = this->_first;
    (this->_first)->prev = pNodo;
    this->_first = pNodo;
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    struct Nodo* pNodo = new Nodo(elem);
    this->_size++;
    if (this->_first == nullptr) {
        this->_first = pNodo;
        this->_last = pNodo;
        return;
    }
    pNodo->prev = this->_last;
    (this->_last)->next = pNodo;
    this->_last = pNodo;
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    if (i == 0) {
        deleteFirst();
        return;
    }
    if (i == this->_size -1) {
        deleteLast();
        return;
    }
    struct Nodo** pDirNodo = &(this->_first);
    while (i > 0) {
        pDirNodo = &((*pDirNodo)->next);
        i--;
    }
    struct Nodo* pNodoEliminar = *pDirNodo;
    *pDirNodo = pNodoEliminar->next;
    (*pDirNodo)->prev = pNodoEliminar->prev;
    delete pNodoEliminar->data;
    delete pNodoEliminar;
    this->_size--;

}

template <typename T>
int Lista<T>::longitud() const {
    return this->_size;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    struct Nodo* pNodo = this->_first;
    while (i > 0) {
        pNodo = pNodo->next;
        --i;
    }
    return *(pNodo->data);
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    struct Nodo* pNodo = this->_first;
    while (i > 0) {
        pNodo = pNodo->next;
        --i;
    }
    return *(pNodo->data);
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}

template<typename T>
void Lista<T>::deleteFirst() {
    if (this->_size == 1) {
        delete this->_first->data;
        delete this->_first;
        this->_first = nullptr;
        this->_last = nullptr;
        this->_size = 0;
        return;
    }
    struct Nodo** pDirNodo = &(this->_first);
    struct Nodo* tmp = *pDirNodo;
    ((*pDirNodo)->next)->prev = (*pDirNodo)->prev;
    *pDirNodo = (*pDirNodo)->next;
    delete tmp->data;
    delete tmp;
    this->_size--;
}

template<typename T>
void Lista<T>::deleteLast() {
    if (this->_size == 1) {
        delete this->_first->data;
        delete this->_first;
        this->_first = nullptr;
        this->_last = nullptr;
        this->_size = 0;
        return;
    }
    struct Nodo** pDirNodo = &(this->_last);
    struct Nodo* tmp = *pDirNodo;
    ((*pDirNodo)->prev)->next = (*pDirNodo)->next;
    *pDirNodo = (*pDirNodo)->prev;
    delete tmp->data;
    delete tmp;
    this->_size--;
}