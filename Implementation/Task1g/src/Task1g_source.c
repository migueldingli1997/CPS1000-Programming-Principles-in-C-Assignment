#include <stdio.h>  //printf(), puts(), getchar()
#include <stdlib.h> //srand(), rand()
#include <time.h>   //time()

#include "Quick.h"
#include "Insertion.h"

/* operation: fills the `nums' array with random integers.    */
/* preconditions: an integer array and a variable which shows */
/*                its size are passed to the function.        */
/* postconditions: the `nums' array contains a set of random  */
/*                 integers generated by the function.        */
void randomArray(const int size, int nums[size]);

/* operation: outputs the integers found in an integer array. */
/* preconditions: an integer array and its size are passed to */
/*                the function.                               */
/* postconditions: the integers in the array are output to    */
/*                 the user in an easy to read form.          */
void printArray(const int size, const int nums[size]);

/* operation: checks that the integers in an array are sorted */
/*            in an ascending order.                          */
/* preconditions: an integer array and its size are passed to */
/*                the function.                               */
/* postconditions: an output indicates whether the sort was   */
/*                 verified or found to be incorrect.         */
void tester(const int size, const int nums[size]);

int main(void)
{
    do
    {
        /*Declaration and initialization*/
        srand(time(NULL));                   //number generator seeded
        const int ARRAYSIZE = (rand()%30)+1; //random size from 1 to 30
        int numbers[ARRAYSIZE];              //array to be sorted

        /*Insertion sort*/
        randomArray(ARRAYSIZE, numbers);    //array given random integers
        printf("Original before insertion sort:\n");
        printArray(ARRAYSIZE, numbers);     //print array
        naive_sort(ARRAYSIZE, numbers);     //sort  array
        printf("Sorted by insertion sort:\n");
        printArray(ARRAYSIZE, numbers);     //print array
        tester(ARRAYSIZE, numbers);         //verify sort

        printf("\n");

        /*Quick sort*/
        randomArray(ARRAYSIZE, numbers);        //array given random integers
        printf("Original before quick sort:\n");
        printArray(ARRAYSIZE, numbers);         //print array
        smarter_sort(numbers, 0, ARRAYSIZE-1);  //sort  array
        printf("Sorted by quick sort:\n");
        printArray(ARRAYSIZE, numbers);         //print array
        tester(ARRAYSIZE, numbers);             //verify sort

        puts("\nPress ENTER to do another pair of sorts or type 'q' to quit...");
    }
    while(getchar()!='q');

    return 0;
}

void randomArray(const int size, int nums[size])
{
    int index; //stores index/counter for the loop

    /*Each element is given a random integer value*/
    for(index=0; index < size; index++)
        nums[index] = rand() % 1000; //random integer between 0 and 999
}

void printArray(const int size, const int nums[size])
{
    /*Declaration of variable*/
    int index; //stores index for loop

    /*Output*/
    printf("{");
    for(index=0; index < size-1; index++)
        printf("%d, ", nums[index]);
    printf("%d}\n", nums[size-1]);
}

void tester(const int size, const int nums[size])
{
    /*Declaration of variable*/
    int index; //stores array counter/index

    /*Tester loop*/
    for(index=0; index < size-1; index++)
    {
        /*Check if a number is followed by a smaller one*/
        if(nums[index] > nums[index+1])
        {
            printf("Sort incorrect.\n");
            return;
        }
    }
    /*Since no number was followed by a smaller one */
    /*the array is hence sorted and was verified.   */
    printf("Sort verified.\n");
}
