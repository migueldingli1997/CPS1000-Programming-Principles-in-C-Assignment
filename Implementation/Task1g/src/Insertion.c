#include "Insertion.h"

void naive_sort(const int size, int nums[size])
{
    /*Declaration of variables*/
    int index1;     //outer loop index
    int index2;     //inner loop index
    int tempInt;    //stores value of index1'th element

    /*Main sort loop*/
    for(index1=1; index1 < size; index1++)
    {
        tempInt = nums[index1]; //current element stored
        index2 = index1;

        /*Inner sort loop*/
        while(index2 > 0 && nums[index2-1] > tempInt)
        {
            nums[index2] = nums[index2-1]; //element shifted to the right
            index2--;
        }
        nums[index2]=tempInt; //vacated element taken up by tempInt
    }
}
