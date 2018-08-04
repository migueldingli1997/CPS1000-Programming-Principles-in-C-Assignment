#include "Stack.h"

void push(struct stack *theStack, const float item)
{
    /*Stack pointer incremented and item stored at new location*/
    (*theStack).stackPointer++;
    (*theStack).items[(*theStack).stackPointer] = item;
}

float pop(struct stack *theStack)
{
    /*If stack not empty, return item at location indicated*/
    /*by stack pointer. Stack pointer is then decremented  */
    if((*theStack).stackPointer != -1)
        return (*theStack).items[(*theStack).stackPointer--];
    else
        return '\0'; //stack is empty
}
