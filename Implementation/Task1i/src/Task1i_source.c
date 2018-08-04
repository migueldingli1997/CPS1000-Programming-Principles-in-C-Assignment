#include <stdio.h> //printf()
#define STOPS 10   //maximum stops

/* operation: comes up with a total stray cats values from the*/
/*            cat counts in the array passed in.              */
/* preconditions: array of stray cats along with the stop to  */
/*                start counting back from are passed in.     */
/* postconditions: the return value is the total amount of    */
/*                 stray cats up to the stop indicated by the */
/*                 value of 'stops' passed in the first call. */
int catCount(const int strayCats[STOPS], const int stops);

int main(void)
{
    /*Declaration and initialization*/
    int strayCats[STOPS] = {12, 5, 3, 20, 15, 6, 7, 1, 19, 30};
    /*Final Output*/
    printf("Hence, a total of %d stray cats were observed.\n", catCount(strayCats, STOPS));

    return 0;
}

int catCount(const int strayCats[STOPS], const int stop)
{
    /*Declaration of variables*/
    int count; //holds the total up to a stop

    /*Base case - If this is the first stop, value is first element*/
    if(stop == 1)
    {
        printf("\nThe total up to stop 1 is: %d; ", strayCats[0]);
        printf("Sending this data to stop 2...\n");
        return strayCats[0];
    }
    else /*else, request value of previous stop*/
    {
        /*If this is not the final stop*/
        if(stop != STOPS)
        {
            printf("For the total up to stop %d, the ", stop);
            printf("total up to stop %d is required.\n", stop-1);
        }
        else
        {
            printf("For the total up to the final stop, ");
            printf("the total up to stop %d is required.\n", stop-1);
        }

        /*Add current value with count up to previous stop*/
        count = strayCats[stop-1] + catCount(strayCats, stop-1);

        /*If this is not the final stop*/
        if(stop != STOPS)
        {
            printf("The total up to stop %d is: %d; ", stop, count);
            printf("Sending this data to stop %d...\n", stop+1);
        }
        else
        {
            printf("The total up to the final stop ");
            printf("at the terminus is: %d.\n", count);
        }

        /*The total up to this stop is returned*/
        return count;
    }
}
