#include <ctype.h>  //for isdigit()
#include <stdlib.h> //for atof()
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

int pushNumber(struct stack *theStack, char express[], int index)
{
    /*Declaration of variables*/
    int tempIndex;    //stores array index
    int numCount=0;   //stores amount of number characters

    /*Push all characters in 'express' starting from 'index'  */
    /*until a character which is not a digit, a decimal point,*/
    /*or a negative sign is found.*/
    tempIndex = index;
    while(isdigit(express[tempIndex])
          || express[tempIndex]=='.'
          || express[tempIndex]=='-')
    {
        numCount++;
        tempIndex++;
    }

    /*Declaring array for number*/
    char number[numCount+1];

    /*Sub-array for operand created*/
    for(tempIndex=0; tempIndex < numCount; tempIndex++)
        number[tempIndex] = express[index++];
    number[tempIndex] = '\0';

    /*Push number onto stack*/
    push(theStack, atof(number));
    /*Index of first character found after the number is returned*/
    return index;
}
