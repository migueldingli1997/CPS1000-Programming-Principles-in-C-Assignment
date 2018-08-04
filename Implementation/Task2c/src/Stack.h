#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define EXPLEN 100

/*stack structure definition*/
struct stack
{
    int stackPointer;
    float items[2*EXPLEN];
};

/* operation: pushes the float passed in onto the specified     */
/*            stack. The stack pointer is incremented.          */
/* preconditions: a pointer to a predeclared stack and a float  */
/*                are passed to the function.                   */
/* postconditions: stack will contain the float 'item' and the  */
/*                 stackPointer within the stack holds the new  */
/*                 float item's index in the 'items' array.     */
void push(struct stack *theStack, const float item);

/* operation: pops and returns a float from the specified       */
/*            stack. The stack pointer is decremented.          */
/* preconditions: a pointer to a predeclared stack from which   */
/*                a float will be obtained is passed in.        */
/* postconditions: float obtained is returned and stack         */
/*                 pointer will point to next item, if any.     */
/*                 If stack was empty when 'pop' was called,    */
/*                 a null character '\0' is returned instead.   */
float pop(struct stack *theStack);

/* operation: pushes a number found in the postfixExp array     */
/*            starting from the location indicated by 'index'.  */
/*            Characters from this location onwards are pushed  */
/*            onto the specified stack until a character which  */
/*            is not a digit, decimal point, or negative sign   */
/*            is reached in the array.                          */
/* preconditions: a stack to push the number onto, the array    */
/*                containing the number, and the index at       */
/*                which the number starts are all passed in.    */
/* postconditions: the stack now contains the number. The index */
/*                 of the array location containing the first   */
/*                 character found after the number is returned.*/
int pushNumber(struct stack *theStack, char postfixExp[], int index);

#endif // STACK_H_INCLUDED
