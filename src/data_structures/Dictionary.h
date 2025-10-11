#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "List.h"

template <typename K, typename V>
//Clase abstracta de diccionario
class Dictionary {
private:
    Dictionary(const Dictionary<K, V> &other) {}
    /* No se puede asignar ni copiar */
    void operator =(const Dictionary<K, V> &other) {}

public:
    Dictionary() {}
    virtual ~Dictionary() {}
    virtual void insert(K key, V value) =0; //Puede insertar
    virtual V remove(K key) =0; //Puede remover
    virtual V getValue(K key) =0; //Puede conseguir el valor segun la llave dada
    virtual void setValue(K key, V value) =0; //Puede cambiar el valor de una llave
    virtual bool contains(K key) =0; //puede ver si contiene un elemento
    virtual void clear() =0; //Puede limpiarse
    virtual List<K>* getKeys() =0; //Puede tirar una lista con las llaves
    virtual List<V>* getValues() =0; //Puede tirar una lista con los valores
    virtual int getSize() =0; //Puede retornar su tamaño
    virtual void print() =0; //Puede imprimirse
};

#endif // DICTIONARY_H
