#include <stdio.h>  //for puts()
#include <string.h> //for strlen()
#include "Stack.h"  //for stack

int parenthesesVal(const char express[])
{
    /*Declaration of variables*/
    int expressLength = strlen(express)-1;  //-1 to exclude newline
    int index=0;                            //array index for expression

    /*declaring a stack*/
    struct stack parenStack;
    parenStack.stackPointer = -1; //initializing the stackPointer

    /*pushing and popping parentheses*/
    for(index=0; index < expressLength; index++)
    {
        /*Push any open parentheses and pop an open     */
        /*parenthesis when a close parenthesis is found */
        if(express[index] == '(')
            push(&parenStack, '(');
        else if(express[index] == ')')
        {
            /*If stack is empty, function returns.    */
            /*Otherwise, an open parentheses is popped*/
            if(pop(&parenStack) == '\0')
            {
                puts("Invalid expression; parentheses mismatch.");
                return 0;
            }
        }
    }

    /*Checking if stack still has parentheses*/
    if(parenStack.stackPointer != -1)
    {
        puts("Invalid expression; parentheses mismatch.");
        return 0;
    }

    /*Expression passed parentheses check*/
    return 1;
}
