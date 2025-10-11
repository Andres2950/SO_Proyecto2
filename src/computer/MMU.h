#ifndef MMU_H
#define MMU_H

#include "Page.h"
#include "Process.h"
#include "Instruction.h"
#include "../data_structures/List.h"
#include "../data_structures/ArrayList.h"
#include "../data_structures/Dictionary.h"
#include "../data_structures/HashTable.h"

#define PAGE_SIZE 4000 // 4KB de tamano


class MMU {
    private:
        void execute_new(Instruction instr) {
            // paginacion si es necesario
        }
        void execute_use(Instruction instr) {
            // paginacion si es necesario
        }
        void execute_delete(Instruction instr) {}
        void execute_kill(Instruction instr) {}
    public: 
        static inline int ptr_count = 0;
        List<Page>* memory;
        List<Page>* disc;
        //no lista de enteros algo diferente
        //Table debe contener todos los punteros
        // es una Dictionary <ptr_id, ptr_pages>
        // Estoy usando un arraylist pq List necesita ser un puntero 
        // El problema de eso es que HashTable no sabe si K y V son punteros entonces no los libera
        // Entonces x eso uso el tipo concreto
        Dictionary<int, ArrayList<Page>>* ptr_table;
        List<Process>* processes;

        MMU(){
            //Memoria real de 100 paginas
           memory = new ArrayList<Page>(100); 
           // disco es 'infinito'
           // Por defecto el array se crea de 1024
           // Pero tiene la funcion expand incluida y se usa automaticamente
           // Entonces sirve perfectamente como infinito
           disc = new ArrayList<Page>();
           ptr_table = new HashTable<int, ArrayList<Page>>;
           processes = new ArrayList<Process>;
        }
        ~MMU() {
            delete memory;
            delete disc;
            delete ptr_table;
            delete processes;
        }

        void execute_instruction(Instruction instr) {
            switch (instr.type) {
                case TYPE_NEW:
                    execute_new(instr);
                    break;
                case TYPE_USE:
                    execute_use(instr);
                    break;
                case TYPE_DELETE:
                    execute_delete(instr);
                    break;
                case TYPE_KILL:
                    execute_kill(instr);
                    break;
            }
        }


};


#endif
