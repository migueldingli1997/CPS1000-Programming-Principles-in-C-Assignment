#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdbool.h>

/*node structure definition with typedef*/
typedef struct node
{
    float item;            //this node's item
    struct node *nextNode; //pointer to next node
} Node;

/*stack structure definition with typedef*/
typedef struct stack
{
    Node *listHead; //pointer to list start
    Node *listTail; //pointer to list end
} Stack;

/* operation: declares a pointer to a stack and allocates     */
/*            memory for the head and tail pointers to nodes. */
/* preconditions: the function takes no arguments.            */
/* postconditions: the pointer to the stack is returned.      */
Stack *newStack(void);

/* operation: pushes the float passed in onto the specified   */
/*            stack. The list will have a new tail node.      */
/* preconditions: a pointer to a predeclared stack and a float*/
/*                are passed to the function.                 */
/* postconditions: stack will contain the float 'item' and the*/
/*                 stackPointer within the stack holds the new*/
/*                 float item's index in the 'items' array.   */
void push(Stack *theStack, const float item);

/* operation: pops and returns a float from the specified     */
/*            stack. List's tail node is removed from the list*/
/* preconditions: a pointer to a predeclared stack from which */
/*                a float will be obtained is passed in.      */
/* postconditions: float obtained is returned and stack       */
/*                 pointer will point to next item, if any.   */
/*                 If stack was empty when 'pop' is called,   */
/*                 a null character '\0' is returned instead. */
float pop(Stack *theStack);

/* operation: similar to the operation of the pop function    */
/*            but does not remove items from the stack.       */
/* preconditions: a pointer to a predeclared stack whose top  */
/*                item will be returned is passed in.         */
/* postconditions: float at the tail of the list (the last    */
/*                 item pushed) is returned. If stack is      */
/*                 empty, a null character '\0' is returned.  */
float top(Stack *theStack);

/* operation: checks the specified stack's head node to see   */
/*            see if the stack is empty and returns a value   */
/*            indicating the state of the stack.              */
/* preconditions: a pointer to a predeclared stack that needs */
/*                to be checked is passed in.                 */
/* postconditions: 1 is returned if the stack is empty.       */
/*                 0 is returned if the stack is not empty.   */
bool is_empty(Stack *theStack);

#endif // STACK_H_INCLUDED
