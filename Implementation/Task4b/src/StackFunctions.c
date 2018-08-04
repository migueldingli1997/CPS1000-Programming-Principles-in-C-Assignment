#include <stdlib.h>  //for malloc(), free(), and NULL
#include <stdbool.h> //for bool, true, false
#include "Stack.h"

Stack *newStack(void)
{
    /*Pointer to a stack declared and memory allocated*/
    Stack *theStack = malloc(sizeof(Stack));

    /*List head and tail initialized to NULL -- since no items yet*/
    (*theStack).listHead = NULL;
    (*theStack).listTail = NULL;

    /*Pointer to the stack is returned*/
    return theStack;
}

void push(Stack *theStack, const float item)
{
    /*Pointer to a new node declared*/
    Node *newNode = malloc(sizeof(Node));

    /*If the list is empty*/
    if(is_empty(theStack))
    {
        /*New node set as head since the only item*/
        (*theStack).listHead = newNode;
    }
    else //if the list is not empty
    {
        /*Current tail node's next node set to the new node.*/
        (*((*theStack).listTail)).nextNode = newNode;
    }
    /*New node set as the list tail*/
    (*theStack).listTail = newNode;

    /*New node given an item and its next node set to NULL*/
    (*newNode).item = item;
    (*newNode).nextNode = NULL;
}

float pop(Stack *theStack)
{
    /*Declaration of variable*/
    float item; //stores popped item

    /*If list is empty, return null character*/
    if(is_empty(theStack))
        return '\0';
    else
    {
        /*Obtain last node's item*/
        item = (*((*theStack).listTail)).item;

        /*If head is tail, stack only has one item*/
        if((*theStack).listHead == (*theStack).listTail)
        {
            /*Free last node and make nodes NULL since no more nodes*/
            free((*theStack).listTail); //head implicitly freed
            (*theStack).listHead = (*theStack).listTail = NULL;
        }
        else //stack does not only have one item
        {
            /*Declaration of pointers to nodes*/
            Node *tailNode = (*theStack).listTail; //makes code simpler
            Node *tempNode = (*theStack).listHead;

            /*Starting from the list head, and setting tempNode  */
            /*to next node until the next node is the tail node. */
            while((*tempNode).nextNode != tailNode)
                tempNode = (*tempNode).nextNode;

            /*Tail node set to node before it*/
            (*theStack).listTail = tailNode = tempNode;

            /*free last node and make it NULL*/
            free((*tailNode).nextNode);
            (*tailNode).nextNode = NULL;
        }
    }
    /*Return item if stack was not empty*/
    return item;
}

float top(Stack *theStack)
{
    /*If list is empty, return null character*/
    if(is_empty(theStack))
        return '\0';
    else //otherwise, return last node's item
        return (*((*theStack).listTail)).item;
}

bool is_empty(Stack *theStack)
{
    /*If list head is NULL, list is empty. */
    /*Otherwise, the list is not empty.    */
    return ((*theStack).listHead == NULL);
}
