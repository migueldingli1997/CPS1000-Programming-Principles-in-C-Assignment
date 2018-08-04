#include <stdio.h>  //printf(), scanf(), putchar(), getchar()
#include <math.h>   //log2()

/* operation: transforms num to its base-n equivalent and outputs result*/
/* preconditions: num is a base-10 number and n is a power-of-2 integer */
/* postconditions: the base-n equivalent of num is output to the user   */
void to_base_n(int num, const int n);

/* operation: clears the input buffer                       */
/* preconditions: input buffer contains unneeded characters */
/* postconditions: input buffer is clear                    */
void emptyInputBuffer(void);

int main(void)
{
    /*Declaration and initialization of variables*/
    int inputVerif=0;   //stores return value of inputs
    double log2base=0;  //stores log2 of the base
    int number=0;       //stores the input decimal number
    int base=0;         //stores the input integer base

    /*infinitely loops until any input is negative*/
    while(1)
    {
        /*Output and input (of number and base)*/
        printf("Insert a decimal number and a power-of-2 integer ");
        printf("base (or insert a negative number or base to quit): \n");
        inputVerif = scanf("%d %d", &number, &base);

        /*negative number or base taken as a 'quit'*/
        if(number<0 || base<0)
            break;

        /*log2 of base is calculated*/
        log2base = log2(base);

        /*if input was accepted and if baseVerif is an integer*/
        if(inputVerif==2 && (log2base) == (int)log2base)
        {
            printf("The base-%d representation is: ", base);

            /*If number is zero, it remains zero  */
            /*Otherwise, it is converted to base-n*/
            if(number == 0)
                putchar('0');               //result is zero
            else
                to_base_n(number, base);    //conversion to base_n
        }
        else //else if the input was rejected
        {
            printf("Invalid input; One/both of the inputs were invalid.");
            emptyInputBuffer(); //clears input buffer
        }
        printf("\n\n");
    }

    return 0;
}

void to_base_n(int num, const int base)
{
    /*If base is 1, print a stream of 1's*/
    if(base == 1)
    {
        while(num-- != 0)
            printf("%d", 1);
        return;
    }
    else if(num == 0) //If no value left, return
        return;

    int remainder = num%base;  //remainder calculated
    to_base_n(num/base, base); //recursive call

    /*If remainder is larger than 10, letters are used instead of digits*/
    printf("%c", remainder < 10 ? remainder+48 : remainder+55);
}

/*This function clears the input buffer*/
void emptyInputBuffer(void)
{
    while(getchar() != '\n');
}
