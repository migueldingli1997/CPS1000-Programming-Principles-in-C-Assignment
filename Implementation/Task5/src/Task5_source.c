#include <stdio.h>
#include "Stack.h"
int main(void)
{
	/*Declaring a pointer to a stack*/
    Stack *testStack = newStack();

    /*Pushing the character 'C' onto the stack*/
    puts("Pushing into stack...");
    push(testStack, 'C');

    /*Popping the character 'C' from the stack*/
    puts("Popping from stack...");
    printf("Character popped: \'%c\'", (char) pop(testStack));

    return 0;
}
