#include <stdio.h>
#include <string>
#include "algorithms/optimal.h"
#include "data_structures/List.h"
#include "data_structures/DLinkedList.h"

using std::string;

void hello_world(string s){
    printf("Hello World!\n");
}



int main(int argc, char* argv[]){
    hello_world("print");

    List<int>* l = new DLinkedList<int>();

    
    //peticiones = [3,1,4,8,5,9,3,2,5,4]
    l->append(3);
    l->append(1);
    l->append(4);
    l->append(8);
    l->append(5);
    l->append(9);
    l->append(3);
    l->append(2);
    l->append(5);
    l->append(4);
    
    optimal(2, *l);

    delete l;
    return 0;
}
