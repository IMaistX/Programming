#include <stdio.h>
#include "calculator.h"

int main(){

    int cal;      // stores user’s choice
    int n = 1;    // loop controller (1 → run, 0 → exit)

    // Keep running the calculator until user chooses to exit
    while(n == 1){

        // Displaying menu to the user
        printf("\n----- SIMPLE CALCULATOR -----\n");
        printf("Choose an option (1-5):\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        printf("Your Choice: ");
        scanf("%d", &cal);
        printf("\n");

        // Switch case to handle user choice
        switch(cal){

            /* -------------------- CASE 1: ADD -------------------- */
            case 1: {
                int a, b;
                printf("ENTER YOUR FIRST NUMBER: ");
                scanf("%d", &a);
                printf("ENTER YOUR SECOND NUMBER: ");
                scanf("%d", &b);

                // Displaying result using add() function
                printf("\nTHE SUM OF %d AND %d IS %d\n", a, b, add(a, b));
                printf("---------------------------\n");
                break;
            }

            /* -------------------- CASE 2: SUBTRACT -------------------- */
            case 2: {
                int a, b;
                printf("ENTER YOUR FIRST NUMBER: ");
                scanf("%d", &a);
                printf("ENTER YOUR SECOND NUMBER: ");
                scanf("%d", &b);

                printf("\nTHE SUBTRACTION OF %d AND %d IS %d\n", a, b, subtract(a, b));
                printf("---------------------------\n");
                break;
            }

            /* -------------------- CASE 3: MULTIPLY -------------------- */
            case 3: {
                int a, b;
                printf("ENTER YOUR FIRST NUMBER: ");
                scanf("%d", &a);
                printf("ENTER YOUR SECOND NUMBER: ");
                scanf("%d", &b);

                printf("\nTHE MULTIPLICATION OF %d AND %d IS %d\n", a, b, multiply(a, b));
                printf("---------------------------\n");
                break;
            }

            /* -------------------- CASE 4: DIVIDE -------------------- */
            case 4: {
                double x, y;
                printf("ENTER YOUR FIRST NUMBER: ");
                scanf("%lf", &x);
                printf("ENTER YOUR SECOND NUMBER: ");
                scanf("%lf", &y);
                printf("\n");

                // Prevent division by zero
                if (y == 0) {
                    printf("Error! Cannot divide by 0.\n");
                    printf("---------------------------\n");
                } 
                else {
                    printf("THE DIVISION OF %.2f AND %.2f IS %.2f\n", x, y, divide(x, y));
                    printf("---------------------------\n");
                }
                break;
            }

            /* -------------------- CASE 5: EXIT -------------------- */
            case 5: {
                printf("EXITED THE PROGRAM!\n");
                printf("---------------------------\n");
                n = 0;   // stop the loop
                break;
            }

            /* -------------------- DEFAULT CASE -------------------- */
            default: {
                printf("Invalid input! Please choose between 1–5.\n");
                printf("---------------------------\n");
                break;
            }
        } // end switch
    } // end while

    return 0;
}
