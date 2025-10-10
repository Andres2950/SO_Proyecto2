#ifndef MMU_H
#define MMU_H

#include "page.h"
#include "../data_structures/List.h"

class MMU {
    public:
        static int ptr_count = 0;
        List<Page> memory;
        List<Page> disc;
        //no lista de enteros alo diferente
        List<int> table;

        MMU(){}


}


#endif
