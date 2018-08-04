#include <stdio.h>   //printf(), puts(), scanf(), getchar()
#define COINS 8      //amount of unique coins
#define CACHESIZE 50 //maximum cached results

/* operation: calculates the the minimum number of coins that */
/*            make up the 'change' passed in.                 */
/* preconditions: the set of different types of coins and the */
/*                change to be given are passed in.           */
/* postconditions: minimum amount of coins that make up the   */
/*                 change is returned.                        */
int computeChange(const int coins[COINS], const int change);

int main(void)
{
    /*Declaration and initialization*/
    const int coins[COINS] = {1,2,5,10,20,50,100,200};
    int index=0;        //stores array index in loop
    int changeInput=0;  //stores the user input
    int coinsResult=0;  //stores result for a specific change
    int cacheUsed=0;    //indicates whether cache was used
    int cacheCounter=0; //location of next cache space to use
    int cache[CACHESIZE][2]; //storage of past results

    /*Clearing the cache*/
    for(index=0; index < CACHESIZE; index++)
        cache[index][0] = -1;

    /*Loops until change input is negative*/
    do
    {
        /*Input of change*/
        puts("What is the required change in cents? (-ve to quit)");
        while(!scanf("%d", &changeInput))
        {
            printf("Invalid value; insert an integer change...\n");
            while(getchar()!='\n'); //clear the input buffer
        }

        /*If changeInput is negative, this is taken as a 'quit'*/
        if(changeInput < 0)
            break;

        /*Check cache for past results*/
        cacheUsed = 0;
        for(index=0; index < CACHESIZE; index++)
        {
            if(cache[index][0]==changeInput)
            {
                coinsResult = cache[index][1];
                cacheUsed = 1;
                break;
            }
        }

        /*Compute the amount of coins for 'changeInput'*/
        if(!cacheUsed)
        {
            /*Change is calculated*/
            coinsResult = computeChange(coins, changeInput);

            /*Storing in cache*/
            cache[cacheCounter][0] = changeInput;
            cache[cacheCounter][1] = coinsResult;

            /*Cache counter incremented and reset */
            /*if the cache limit was reached.     */
            cacheCounter++;
            if(cacheCounter == CACHESIZE)
                cacheCounter=0;
        }

        /*Final output*/
        printf("For %d cents change, a minimum of %d coin/s is needed.\n\n",
               changeInput, coinsResult);
    }
    while(1);

    return 0;
}

int computeChange(const int coins[COINS], const int change)
{
    /*Declaration of variables*/
    int index;      //used as a loop index/counter
    int subChange;  //stores change from 0 to `change'
    int coinCount;  //stores the amount of coins
    int pastValues[change+1]; //used as a cache

    /*Main loop*/
    for(subChange=0; subChange <= change; subChange++)
    {
        /*Maximum amount of coins is 'subChange' 1-cent coins*/
        coinCount = subChange;

        /*Calculating the minimum coin count*/
        for(index=0; index<COINS; index++)
        {
            /*If the change is equal to a coin only one coin is required*/
            if(subChange==coins[index])
            {
                coinCount = 1;
                break;
            }
            else if(subChange>coins[index]
                    && 1+pastValues[subChange-coins[index]] < coinCount)
            {
                coinCount = 1+pastValues[subChange-coins[index]];
            }
        }
        /*Storing the count in the cache*/
        pastValues[subChange] = coinCount;
    }
    /*Return result of minimum amount of coins*/
    return pastValues[change];
}
