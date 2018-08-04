#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/*stack structure definition*/
struct stack
{
    int stackPointer;
    float items[];
};

/*An alias for the stack struct*/
typedef struct stack Stack; //"Stack" is an alias for the struct

/* operation: declares a pointer to a stack and allocates     */
/*            enough memory so that the array 'items' in the  */
/*            stack will have 'max_size' usable elements.     */
/* preconditions: maximum amount of items that the stack will */
/*                be able to fit is passed to the function.   */
/* postconditions: the pointer to the stack is returned.      */
Stack *newStack(int max_size);

/* operation: pushes the float passed in onto the specified   */
/*            stack. The stack pointer is incremented.        */
/* preconditions: a pointer to a predeclared stack and a float*/
/*                are passed to the function.                 */
/* postconditions: stack will contain the float 'item' and the*/
/*                 stackPointer within the stack holds the new*/
/*                 float item's index in the 'items' array.   */
void push(Stack *theStack, const float item);

/* operation: pops and returns a float from the specified     */
/*            stack. The stack pointer is decremented.        */
/* preconditions: a pointer to a predeclared stack from which */
/*                a float will be obtained is passed in.      */
/* postconditions: float obtained is returned and stack       */
/*                 pointer will point to next item, if any.   */
/*                 If stack was empty when 'pop' is called,   */
/*                 a null character '\0' is returned instead. */
float pop(Stack *theStack);

/* operation: similar to the operation of the pop function    */
/*            but does not decrement the stack pointer.       */
/* preconditions: a pointer to a predeclared stack whose top  */
/*                item will be returned is passed in.         */
/* postconditions: float at the top of the stack (the last    */
/*                 item pushed) is returned. If stack is      */
/*                 empty, a null character '\0' is returned.  */
float top(Stack *theStack);

/* operation: checks the specified stack's stack pointer to   */
/*            see if the stack is empty and returns a value   */
/*            indicating the state of the stack.              */
/* preconditions: a pointer to a predeclared stack that needs */
/*                to be checked is passed in.                 */
/* postconditions: 1 is returned if the stack is empty.       */
/*                 0 is returned if the stack is not empty.   */
bool is_empty(Stack *theStack);

#endif // STACK_H_INCLUDED
