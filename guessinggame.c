#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int random , guess , noofguess=0;
    srand(time(NULL));
    printf("Welcome to the game.\n");
    random=rand()%100 +1;
    do
    {
        printf("Please enter your guess in b/w(1 to 100)");
        scanf("%d", &guess);
        noofguess++;

        if (guess < random)
        {
            printf("Guess larger number.\n");
        }
        else if (guess > random)
        {
            printf("Guess smaller number.\n");
        }
        else
        {
            printf("Finally you guessed the correct number in %d attempt, CONGRATULATIONS ! \n", noofguess);
        }
        
        
    } while (guess!=random);
    printf("\n Thanks  for playing.");
    return 0;
}