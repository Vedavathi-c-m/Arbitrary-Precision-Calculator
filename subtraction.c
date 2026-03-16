#include "apc.h"    // Include APC header file with structures, macros and function prototypes

// Function to subtract second big number from first big number
int subtraction(Dlist **head1, Dlist **tail1,
                Dlist **head2, Dlist **tail2,
                Dlist **headR, Dlist **tailR)
{
    /* Assumption: First number is always greater than or equal to second number */

    Dlist *t1 = *tail1;        // Pointer to traverse first number from LSB
    Dlist *t2 = *tail2;        // Pointer to traverse second number from LSB
    int borrow = 0;            // Variable to store borrow during subtraction

    *headR = NULL;             // Initialize result head as NULL
    *tailR = NULL;             // Initialize result tail as NULL

    while (t1 || t2)           // Loop until all digits of both numbers are processed
    {
        int v1;                // Variable to store current digit of first number
        int v2;                // Variable to store current digit of second number

        if (t1)                // If first list still has digits
            v1 = t1->data;    // Take digit from first number
        else                   // If no digit left in first number
            v1 = 0;           // Treat missing digit as 0

        if (t2)                // If second list still has digits
            v2 = t2->data;    // Take digit from second number
        else                   // If no digit left in second number
            v2 = 0;           // Treat missing digit as 0

        v1 -= borrow;         // Subtract previous borrow from current digit

        if (v1 < v2)          // If current digit is smaller than the digit to subtract
        {
            v1 += BASE;      // Add BASE to handle borrowing
            borrow = 1;      // Set borrow for next higher digit
        }
        else                  // If current digit is greater or equal
        {
            borrow = 0;      // No borrow required
        }

        int diff = v1 - v2;  // Calculate difference of current digits
        insert_at_first(headR, tailR, diff);  // Store result digit in result list

        if (t1) t1 = t1->prev;   // Move to previous digit of first number
        if (t2) t2 = t2->prev;   // Move to previous digit of second number
    }

    return SUCCESS;           // Return success after completing subtraction
}
