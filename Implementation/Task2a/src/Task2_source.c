#include <stdio.h>      //for puts() and fgets()
#include <stdlib.h>     //for exit()
#include "Validation.h" //for parentheses validation
#include "Stack.h"      //for EXPLEN

int main(void)
{
    /*Declaration of array to hold input infix expression*/
    char express[EXPLEN];

    /*Loops until expression is valid or user quits*/
    do
    {
        /*Input of expression*/
        puts("Insert an arithmetic expression (q to quit): ");
        fgets(express, EXPLEN, stdin); //input of infix expression

        /*Check if user inserted a 'q'*/
        if(express[0] == 'q')
            exit(0);                   //user inserted a 'q' so quit

    } while(!parenthesesVal(express)); //repeat until expression is valid
    puts("Expression parentheses validated.");

    return 0;
}
