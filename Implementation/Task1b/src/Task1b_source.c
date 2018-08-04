#include <stdio.h>   //printf(), getchar()
#include <stdbool.h> //bool, true, false
#include <ctype.h>   //isalnum(), isalpha(), isupper()

/* operation: finds and returns the Highest Common Factor of two numbers*/
/* preconditions: num1 and num2 are two integers                        */
/* postconditions: highest common factor is returned                    */
int findHCF(const int num1, const int num2);

int main(void)
{
    /*Declaration and initialization of variables*/
    char ch;                  //stores input characters
    int letters=0, words=0;   //store amount of letters and words
    int uppers=0, lowers=0;   //store amount of upper/lower-case letters
    int HCF=0;                //stores the HCF of uppers and lowers
    bool needNextWord = true; //indicates whether a word is being expected

    /*First output*/
    printf("Insert text (insert an EOF on a line by itself to stop):\n");

    /*Loop until an EOF is read*/
    while((ch = getchar()) != EOF)
    {
        /*if character is alphanumeric*/
        if(isalnum(ch))
        {
            /*if a word was being expected, it is not exp-*/
            /*ected anymore since a word's start was found*/
            if(needNextWord)
                needNextWord = false;

            /*if character is alphabetic (letter)*/
            if(isalpha(ch))
            {
                letters++;       //letter found

                /*Check case*/
                if(isupper(ch))
                    uppers++;    //upper-case letter found
                else
                    lowers++;    //lower-case letter found
            }
        }
        else if(!needNextWord)
        {
            words++;             //complete word formed
            needNextWord = true; //next word needed
        }
    }

    /*Calculate HCF*/
    HCF = findHCF(uppers, lowers);

    /*Outputs*/
    printf("Letters: %d\n", letters);
    printf("Words:   %d\n", words);
    printf("Uppers:  %d\n", uppers);
    printf("Lowers:  %d\n", lowers);
    printf("Average letters per word: %.3f\n", words>0 ? ((float)letters/words) : 0);
    printf("Ratio of upper- to lower-case letters: %d:%d\n", uppers/HCF, lowers/HCF);

    return 0;
}

int findHCF(const int num1, const int num2)
{
    int i=0; //loop counter

    /*If both numbers are zero, HCF is 1. */
    /*Otherwise, the HCF is calculated.   */
    if(num1==0 && num2==0)
        return 1;
    else
    {
        /*Loop from num1 down to 1*/
        for(i=num1; i>0; i--)
        {
            /*if 'i' is a factor of both numbers*/
            if(num1%i==0 && num2%i==0)
                return i; //return common factor
        }
    }

    /*if num1 is 0, num2 is the HCF*/
    return num2;
}
