#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <stdexcept>
#include <iostream>
#include "List.h"
#include "DNode.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
//Lista con nodos que se apuntan entre ellos
class DLinkedList : public List<E> {
private:
    DNode<E> *head;
    DNode<E> *tail;
    DNode<E> *current;
    int size;

public:
    DLinkedList() {
        current = head = new DNode<E>(nullptr, nullptr);
        tail = head->next = new DNode<E>(nullptr, head);
        size = 0;
    }

    ~DLinkedList() {
        clear();
        delete head;
        delete tail;
    }

    //Insertar crea el nodo y lo pone en la posicion debida
    void insert(E element){
        current->next = current->next->previous = new DNode<E>(element, current->next, current);
        size++;
    }

    //Appendo crea un nodo al final
    void append(E element) {
        tail->previous = tail->previous->next = new DNode<E>(element, tail, tail->previous);
        size++;
    }

    //remove quita el elemento actual en la lista y la veulve a enlazar
    E remove() {
        if (size == 0)
            throw runtime_error("List is empty.");
        if (current->next == tail)
            throw runtime_error("No current element.");
        E result = current->next->element;
        current->next = current->next->next;
        delete current->next->previous;
        current->next->previous = current;
        size--;
        return result;
    }

    //Limpia toda la lista
    void clear(){
        while (head->next != tail){
            head->next = head->next->next;
            delete head->next->previous;
        }

        tail->previous = head;
        size = 0;
    }

    //Tira el elemento actual
    E getElement(){
        if (size == 0)
            throw runtime_error("List is empty.");
        if (current->next == tail)
            throw runtime_error("No current element.");
        return current->next->element;
    }
    //Tira el puntero al elemento actual
    E* getElementPointer() {
        if (size == 0)
            throw runtime_error("List is empty.");
        if (current->next == tail)
            throw runtime_error("No current element.");
        return &(current->next->element);
    }

    //Va al principio de la lista
    void goToStart(){
        current = head;
    }

    void goToEnd(){
        current = tail->previous;
    }

    //Va a la posiscion dada
    void goToPos(int pos){// Se necesita un ciclo para ir a una posición
        if (pos < 0 || pos > size)
            throw runtime_error("Index out of bounds.");
        current = head;
        for (int i = 0; i < pos; i++)
            current = current->next;
    }

    //Avanza una posicion adelante
    void next() {
        if (current->next != tail) {
            current = current->next;
        }
    }

    //Avanza una posicion atras
    void previous() {
        if (current != head) {
            current = current->previous;
        }
    }

    //Pregunta si esta al principio
    bool atStart(){
        return current == head;
    }

    bool atEnd(){
        return current->next == tail;
    }

    //Tira la posicion actual
    int getPos() {
        int pos = 0;
        DNode<E> *temp = head;
        while (temp != current){
            temp = temp->next;
            pos++;
        }
        return pos;
    }

    int getSize() {
        return size;
    }

    //imprime
    void print(){

        DNode<E>* temp = head->next; //El temporal empieza en el primer nodo
        int index = 0;

        cout<<"[ ";
        while (index != size){
            if (temp == current->next) //Se imprime entre parentesis el actual
                cout<<"*";
            cout<<temp->element;
            cout<<" ";
            temp = temp->next;
            index++;
        }
        cout<<"]";
    }

    int indexOf(E element){
        DNode<E>* temp = head->next; //Empieza en el primer elemento

        for (int i = 0; i < size; i++){ //Itera por la lista y si es el elemento retorna el indice
            if (temp->element == element)
                return i;
            temp = temp->next;
        }
        return -1; //Si no se encuentra en elemento retorna -1
    }

    bool contains(E element){
        goToStart();

        while (!atEnd()){

            if (element == getElement())
                return true;

            next();
        }

        return false;

    }
};

#endif // DLINKEDLIST_H
