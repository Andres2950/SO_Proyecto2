#ifndef INSTRUCTION_H
#define INSTRUCTION_H 


#define TYPE_NEW 0
#define TYPE_USE 1 
#define TYPE_DELETE 2
#define TYPE_KILL 3
typedef int Instruction_Type;

/*
 *  NEW:
 *      param1: pid (int)
 *      param2: size (int)
 *  USE:
 *      param1: ptr (int)
 *  DELETE:
 *      param1: ptr (int)
 *  KILL:
 *      param1: pid(int)
 * */

typedef struct {
    Instruction_Type type;
    int param1;
    int param2; 
} Instruction;

#endif //INSTRUCTION_H
