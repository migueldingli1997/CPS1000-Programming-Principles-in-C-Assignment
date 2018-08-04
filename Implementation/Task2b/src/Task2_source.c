#include <stdio.h>      //for puts() and fgets()
#include <stdlib.h>     //for exit()
#include <ctype.h>      //for isdigit()
#include <string.h>     //for strlen()
#include "ValAndComp.h" //for parentheses validation
#include "Stack.h"      //for stack, stack functions, and EXPLEN

/* operation: Converts the infix expression passed in to a    */
/*            postfix expression.                             */
/* preconditions: The infix expression is stored in `infixExp'*/
/*                and an additional array `postfixExp' is     */
/*                passed to store the resultant postfix exp-  */
/*                ression without having to return anything.  */
/* postconditions: The `postfixExp' array will now hold the   */
/*                 postfix equivalent of the passed expression*/
void infixToPostfix(const char infixExp[], char postfixExp[]);

/* operation: Checks whether the character passed to the      */
/*            function is an operator (+, -, /, or *).        */
/* preconditions: the character to be checked is passed to    */
/*                the function.                               */
/* postconditions: 1 is returned the 'a' is an operator.      */
/*                 0 is returned the 'a' is not an operator.  */
int isOperator(const char a);

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

    /*Infix to postfix conversion*/
    char postfixExp[2*strlen(express)];      //array declared
    infixToPostfix(express, postfixExp);     //expression converted
    printf("Postfix: \"%s\"\n", postfixExp);

    return 0;
}

void infixToPostfix(const char infixExp[], char postfixExp[])
{
    /*Declaration and initialization*/
    int infxIndex=0;  //array index for infixExp and loop counter
    int pofxIndex=0;  //array index for postfixExp
    char ch;          //stores popped stack items
    int expressLength = strlen(infixExp)-1; //-1 to exclude newline

    /*Declaring a stack*/
    struct stack opStack;
    opStack.stackPointer = -1; //initializing the stackPointer

    /*Main loop - goes through expression one character at a time*/
    for(infxIndex=0; infxIndex < expressLength; infxIndex++)
    {
        /*If digit, read all further digits*/
        if(isdigit(infixExp[infxIndex]))
        {
            /*Loop while the next character is a digit or decimal point*/
            do
            {
                postfixExp[pofxIndex++] = infixExp[infxIndex++];
            }while(isdigit(infixExp[infxIndex])
                   || infixExp[infxIndex]=='.');

            /*Insert a space for a new postfix element to come after*/
            postfixExp[pofxIndex++] = ' ';
            /*Index adjusted since an extra character was read*/
            infxIndex--; //since an extra character was read
        }
        else if(infixExp[infxIndex] == '(')
        {
            /*Left parentheses simply pushed*/
            push(&opStack, '(');
        }
        else if(infixExp[infxIndex] == ')')
        {
            /*For right parentheses, append operators to */
            /*the postfix expression.                    */
            while((ch=pop(&opStack)) != '(')
            {
                /*Insert popped operator and a space*/
                postfixExp[pofxIndex++] = ch;
                postfixExp[pofxIndex++] = ' ';
            }
        }
        else if(isOperator(infixExp[infxIndex]))
        {
            /*if operator was found, add all higher-or-equal- */
            /*precedence operators to postfix expression      */
            while((ch=pop(&opStack)) != '(' && ch!='\0')
            {
                /*If not less precedence (i.e if higher or equal)*/
                if(precedenceComp(ch, infixExp[infxIndex]) != -1)
                {
                    /*Insert popped operator and a space*/
                    postfixExp[pofxIndex++] = ch;
                    postfixExp[pofxIndex++] = ' ';
                }
                else
                {
                    /*Push operator with less precedence*/
                    push(&opStack, ch);
                    /*Append no more operators to the list*/
                    break;
                }
            }

            /*Open parenthesis pushed back*/
            if(ch == '(')
                push(&opStack, '(');

            /*Original operator now pushed*/
            push(&opStack, infixExp[infxIndex]);
        }

        /*If character did not satisfy a condition, the character*/
        /*is simply skipped since it is not a useful character.  */
    }

    /*Pop remaining operators*/
    while((ch=pop(&opStack)) != '\0')
    {
        /*Insert popped operator and a space*/
        postfixExp[pofxIndex++] = ch;
        postfixExp[pofxIndex++] = ' ';
    }

    /*Last character set to a null character */
    postfixExp[pofxIndex-1] = '\0'; //exclude last space
}

int isOperator(const char a)
{
    /* 1 is returned the 'a' is an operator.      */
    /* 0 is returned the 'a' is not an operator.  */
    return (a == '+' || a == '-' || a == '*' || a == '/');
}
