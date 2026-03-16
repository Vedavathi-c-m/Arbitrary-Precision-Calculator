#include "apc.h"    // Include APC header file with structures and function prototypes

// Function to divide first big number by second big number using repeated subtraction
int division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    *headR = NULL;            // Initialize result head as NULL
    *tailR = NULL;            // Initialize result tail as NULL

    if (is_zero(*head2))      // Check if divisor is zero
    {
        printf("ERROR: Division by zero\n"); // Print error message
        return FAILURE;       // Return failure
    }

    if (!compare_list(*head1, *head2))  // If dividend < divisor
    {
        insert_at_first(headR, tailR, 0);    // Quotient is 0
        return SUCCESS;        // Return success
    }

    int count = 0;            // Variable to store quotient value

    while (compare_list(*head1, *head2))  // Loop while dividend >= divisor
    {
        Dlist *remH = NULL;   // Head of remainder list
        Dlist *remT = NULL;   // Tail of remainder list

        // Call subtraction sub-function to compute remainder
        subtraction(head1, tail1, head2, tail2, &remH, &remT);

        free_list(head1, tail1);   // Free old dividend list memory

        *head1 = remH;             // Update dividend head with remainder
        *tail1 = remT;             // Update dividend tail with remainder

        count++;                   // Increment quotient count
    }

    insert_at_first(headR, tailR, count);  // Store final quotient in result list

    return SUCCESS;               // Return success after completing division
}
