#include <stdio.h>  //for puts()
#include <string.h> //for strlen()
#include <ctype.h>  //for isdigit()
#include <stdlib.h> //for malloc(), free()
#include "Stack.h"  //for stack

/* operation: the parentheses, if any, in the expression found*/
/*            in 'express' are checked for mismatches.        */
/* preconditions: array containing expression to be checked is*/
/*                passed to the function.                     */
/* postconditions: '0' is returned in the case of a mismatch. */
/*                 '1' returned if the expression is valid.   */
int parenthesesVal(const char express[]);

/* operation: the characters which make up the expression in  */
/*            'express' are checked for illegal characters.   */
/*            Legal: '+', '-', '*', '/', '.', '(', and ')'    */
/* preconditions: array containing expression to be checked is*/
/*                passed to the function.                     */
/* postconditions: First illegal character found is returned. */
/*                 Otherwise, a null character '\0' returned. */
char charactersVal(const char express[]);

int expressionVal(const char express[])
{
    /*Character used for return of function charactersVal*/
    char ch;

    /*A series of checks run*/
    /*0 returned : expression failed at least one check*/
    /*1 returned : expression passed all checks*/
    if( !parenthesesVal(express) ) //parentheses check
    {
        puts("Invalid expression; parentheses mismatch.");
        return 0;
    }
    else if( (ch=charactersVal(express)) ) //character check
    {
        printf("Invalid expression; illegal character '%c'.\n", ch);
        return 0;
    }
    else if(express[0] == '\n') //expression presence check
    {
        puts("Invalid expression; nothing was input.");
        return 0;
    }

    /*Expression still considered to be valid if expression limit*/
    /*was reached. Program might still crash if limit reached.   */
    if(strlen(express) >= EXPLEN-1) //expression length limit check
        puts("Warning: answer might be incorrect; expression length limit reached.");

    /*Expression passed all checks*/
    return 1;
}

int parenthesesVal(const char express[])
{
    /*Declaration of variables*/
    int expressLength = strlen(express)-1;  //-1 to exclude newline
    int index=0;        //array index for expression

    /*Declaring a pointer to a stack*/
    Stack *parenStack = newStack();

    /*Pushing and popping parentheses*/
    for(index=0; index < expressLength; index++)
    {
        /*Push any open parentheses and pop an open     */
        /*parenthesis when a close parenthesis is found */
        if(express[index] == '(')
            push(parenStack, '(');
        else if(express[index] == ')')
        {
            /*If stack is empty, function returns.    */
            /*Otherwise, an open parentheses is popped*/
            if(pop(parenStack) == '\0')
            {
                free(parenStack);
                return 0;
            }
        }
    }

    /*Checking if stack still has parentheses*/
    if(!is_empty(parenStack))
    {
        free(parenStack);
        return 0;
    }

    /*Expression passed parentheses check*/
    free(parenStack);
    return 1;
}

char charactersVal(const char express[])
{
    /*Declaration of variables*/
    int expressLength = strlen(express)-1;  //-1 to exclude newline
    int index=0;                            //array index for expression

    /*Loops through all characters of the expression*/
    for(index=0; index < expressLength; index++)
    {
        /*If a character is not any of these characters, */
        /*then it is considered to be forbidden.         */
        if( !isdigit(express[index])     && express[index] != '+'
                && express[index] != '-' && express[index] != '*'
                && express[index] != '/' && express[index] != '.'
                && express[index] != '(' && express[index] != ')'
                && express[index] != '\r') // ignore carriage return
        {
            /*Illegal character returned*/
            return express[index];
        }
    }
    /*No illegal characters found - expression passed character check*/
    return '\0';
}

int precedenceComp(const char a, const char b)
{
    /*If 'a' is * or /...                                  */
    /*...if 'b' is * or /, operators have equal precedence */
    /*...if 'b' is + or -, then 'a' has higher  precedence */
    /*If 'a' is + or -...                                  */
    /*...if 'b' is * or /, then 'a' has lower   precedence */
    /*...if 'b' is + or -, operators have equal precedence */
    return (a=='*' || a=='/')-(b=='*' || b=='/');
}
