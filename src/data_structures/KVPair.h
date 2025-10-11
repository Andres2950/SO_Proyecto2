#ifndef KVPAIR_H
#define KVPAIR_H

#include <iostream>
using std::ostream;

/* Clase para pares llave-valor utilizada por todos
los diccionarios. Posee reescritura de los operadores
de comparación para realizar ordenamiento en los
diccionarios que implementan esta clase*/

template <typename K, typename V>
class KVPair{
public:
    K key;
    V value;

    KVPair(K key, V value) {
        this->key = key;
        this->value = value;
    }
    KVPair(K key) {
        this->key = key;
    }
    KVPair() {}

    // Constructor de copia
    KVPair(const KVPair<K, V> &other) {
        key = other.key;
        value = other.value;
    }
    // Operador de asignación
    void operator =(const KVPair<K, V> &other) {
        key = other.key;
        value = other.value;
    }
    // Definir como se comparan los elementos
    bool operator ==(const KVPair<K, V> &other){
        return this->key == other.key;
    }

    bool operator <(const KVPair<K, V> &other){
        return this->key < other.key;
    }
    bool operator <=(const KVPair<K, V> &other){
        return this->key <= other.key;
    }
    bool operator >(const KVPair<K, V> &other){
        return this->key > other.key;
    }
    bool operator >=(const KVPair<K, V> &other){
        return this->key >= other.key;
    }
    bool operator !=(const KVPair<K, V> &other){
        return this->key != other.key;
    }

};

template <typename K, typename V>
ostream& operator <<(ostream &os, const KVPair<K, V> &pair){
    os << "(" << pair.key << ", " << pair.value << ")";
    return os;
}

#endif // KVPAIR_H
