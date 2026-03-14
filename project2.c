#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int randomNumber, guessed, attempts = 0;
    int maxAttempts;
    int difficulty;
    char playAgain;

    srand(time(0));

    do
    {
        printf("\n===== NUMBER GUESSING GAME =====\n");
        printf("Choose Difficulty Level\n");
        printf("1. Easy (10 attempts)\n");
        printf("2. Medium (7 attempts)\n");
        printf("3. Hard (5 attempts)\n");
        printf("Enter choice: ");
        scanf("%d", &difficulty);

        if (difficulty == 1)
            maxAttempts = 10;
        else if (difficulty == 2)
            maxAttempts = 7;
        else
            maxAttempts = 5;

        randomNumber = rand() % 100 + 1;
        attempts = 0;

        printf("\nI have chosen a number between 1 and 100.\n");

        while (attempts < maxAttempts)
        {
            printf("Enter your guess number: ");
            scanf("%d", &guessed);

            attempts++;

            if (guessed > randomNumber)
            {
                printf("Too high! Try a smaller number.\n");
            }
            else if (guessed < randomNumber)
            {
                printf("Too low! Try a bigger number.\n");
            }
            else
            {
                printf("🎉 Congratulations! You guessed it in %d attempts.\n", attempts);
                break;
            }
        }

        if (guessed != randomNumber)
        {
            printf("❌ You lost! The correct number was %d\n", randomNumber);
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing! 👋\n");

    return 0;
}