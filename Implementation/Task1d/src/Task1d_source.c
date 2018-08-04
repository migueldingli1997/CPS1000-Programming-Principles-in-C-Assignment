#include <stdio.h>  //printf(), fgets()
#include <string.h> //strlen()

#define MAXLEN 100  //maximum input size

/* operation: reverses the string passed to the function      */
/* preconditions: a character array is passed to the function */
/* postconditions: the character array is modified in a way   */
/*                 that the characters inside it are reversed */
void str_reverse(char[MAXLEN]);

int main(void){
    /*Declaration of variables*/
    char input[MAXLEN]; //stores input string

    /*User inputs a string*/
    printf("Insert a string: ");
    fgets(input, MAXLEN, stdin);
    input[strlen(input)-1]='\0'; //removing the extra newline due to fgets
    printf("Input:    \"%s\"\n", input);

    /*Reversing the string*/
    str_reverse(input);
    printf("Reversed: \"%s\"", input);

    return 0;
}

void str_reverse(char string[MAXLEN])
{
    /*Declaration of variables*/
    int size = strlen(string);  //stores the string length
    int index;                  //stores loop counter/index
    char temp;                  //stores a char while swapping

    /*String is reversed*/
    for(index = 0; index < size/2; index++){
        temp = string[index];
        string[index] = string[size-1-index];
        string[size-1-index] = temp;
    }
}
