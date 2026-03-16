#include "apc.h"   // Includes all structure definitions and macros like BASE, SUCCESS

// Function to add two big numbers stored in doubly linked lists
int addition(Dlist **head1, Dlist **tail1,     // First number list (head & tail)
             Dlist **head2, Dlist **tail2,     // Second number list (head & tail)
             Dlist **headR, Dlist **tailR)     // Result list (head & tail)
{
    // Pointer to traverse first number from last node (LSB side)
    Dlist *t1 = *tail1;

    // Pointer to traverse second number from last node (LSB side)
    Dlist *t2 = *tail2;

    // Variable to store carry during addition
    int carry = 0;

    // Initialize result list as empty
    *headR = NULL;
    *tailR = NULL;

    // Loop continues while any digit or carry is left
    while (t1 || t2 || carry)
    {
        // Start sum with carry value
        int sum = carry;

        // If first list still has digits, add it
        if (t1)
        {
            sum += t1->data;     // Add current digit of first number
            t1 = t1->prev;      // Move to previous digit (towards MSB)
        }

        // If second list still has digits, add it
        if (t2)
        {
            sum += t2->data;    // Add current digit of second number
            t2 = t2->prev;     // Move to previous digit
        }

        // Calculate carry for next iteration
        carry = sum / BASE;     // BASE = 10000 (4-digit chunk)

        // Extract digit to store in result
        int digit = sum % BASE;

        // Insert the calculated digit at the front of result list
        insert_at_first(headR, tailR, digit);
    }

    // Return success after completing addition
    return SUCCESS;
}
