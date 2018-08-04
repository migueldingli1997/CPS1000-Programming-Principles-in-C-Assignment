#include "Quick.h"

void smarter_sort(int nums[], const int start, const int end)
{
    /*Declaration and initialization of variables*/
    int left = start; //index of element smaller than pivot
    int right = end;  //index of element larger than pivot
    int pivot = nums[(end+start)/2]; //reference number
    int temp;         //used when swapping two elements

    /*Main loop*/
    while(left <= right)
    {
        /*Move to the right until value larger */
        /*than or equal to pivot is found.     */
        while(nums[left] < pivot)
            left++;
        /*Move to the left until value smaller */
        /*than or equal to pivot is found.     */
        while(nums[right] > pivot)
            right--;

        /*If 'left' exceeds 'right', then this */
        /*section of the array has been ordered*/
        if(left > right)
            break;

        /*Swapping numbers at 'left' and 'right'*/
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;

        /*Moving on to the next elements */
        /*in the list to be considered.  */
        left++;
        right--;
    }
    /*If more than one value to the left of 'left'*/
    if((left-1) > start)
        smarter_sort(nums, start, left-1); //sort left part
    /*If at least one value to the right of 'left'*/
    if(left < end)
        smarter_sort(nums, left, end);     //sort right part
}
