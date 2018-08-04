#include <stdio.h> //puts(), scanf(), printf(), getchar()
#define TAXRATE1 (float) 15/100
#define TAXRATE2 (float) 29/100
#define PAYRATE  22.50
#define OVERTIMERATE 1.5

/* operation: clears the input buffer                       */
/* preconditions: input buffer contains unneeded characters */
/* postconditions: input buffer is clear                    */
void emptyInputBuffer(void);

int main(void)
{
    /*Declarations and initialization of variables*/
    float hoursWorked=0;    //amount of hours worked
    float grossPay=0;       //calculated grossPay
    float tax=0;            //calculated tax
    float netPay=0;         //calculated net pay

    /*First output*/
    puts("Please insert the number of hours worked in a week: ");

    /*Loop until the input is accepted*/
    while(!scanf("%f", &hoursWorked))
    {
        emptyInputBuffer(); //dump the input
        puts("Invalid input; Insert the hours worked in a week: ");
    }

    /*Output indicating the input that was accepted*/
    printf("\nInput \"%.2f\" accepted\n", hoursWorked);

    /*Calculate gross pay*/
    if(hoursWorked > 40)
        grossPay = PAYRATE*(40+OVERTIMERATE*(hoursWorked-40));
    else
        grossPay = PAYRATE*hoursWorked;

    /*Calculate tax*/
    if(grossPay > 300)
    {
        if(grossPay > 480)
            tax = (TAXRATE1*180)+(TAXRATE2*(grossPay-480));
        else
            tax = TAXRATE1*(grossPay-300);
    }

    /*netPay calculated by subtracting tax from grossPay*/
    netPay = grossPay - tax;

    /*Outputs to the user rounded to two decimal places*/
    printf("-------------------------\n");
    printf("Gross pay: %10.2f Eur\n", grossPay);
    printf("Tax pay:   %10.2f Eur\n", tax);
    printf("-------------------------\n");
    printf("Net pay:   %10.2f Eur\n", netPay);
    printf("-------------------------\n");

    return 0;
}

/*This function clears the input buffer*/
void emptyInputBuffer(void)
{
    while(getchar() != '\n');
}
