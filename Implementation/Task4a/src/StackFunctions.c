#include <stdlib.h>  //for malloc()
#include <stdbool.h> //for bool, true, false
#include "Stack.h"

Stack *newStack(const int max_size)
{
    /*Pointer to a stack declared, memory allocated,*/
    /*and the stack pointer is initialized to -1.   */
    Stack *theStack = malloc(sizeof(Stack) + max_size*sizeof(float));
    (*theStack).stackPointer = -1;

    /*Pointer to the stack is returned*/
    return theStack;
}

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

float top(Stack *theStack)
{
    /*If stack not empty, return item at location indicated*/
    /*by stack pointer. Stack pointer is not decremented.  */
    if((*theStack).stackPointer != -1)
        return (*theStack).items[(*theStack).stackPointer];
    else
        return '\0'; //stack is empty
}

bool is_empty(Stack *theStack)
{
    /*If stack pointer is -1, then the stack is empty, so*/
    /*'true' is returned. Otherwise, 'false' is returned.*/
    return (*theStack).stackPointer == -1 ? true : false;
}
