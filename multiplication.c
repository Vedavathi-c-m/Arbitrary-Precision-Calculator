#include "apc.h"

// Function to multiply two big numbers using addition() for partial sums
int multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **headR, Dlist **tailR)
{
    // If any input number is zero, result is zero
    if (is_zero(*head1) || is_zero(*head2))
    {
        *headR = *tailR = NULL;
        insert_at_first(headR, tailR, 0);
        return SUCCESS;
    }

    *headR = *tailR = NULL;        // Initialize final result list

    Dlist *t2 = *tail2;            // Traverse second number from LSB
    int shift = 0;                 // Track digit position for shifting

    while (t2)                     // Loop for each digit of second number
    {
        Dlist *tempH = NULL;       // Head of partial product
        Dlist *tempT = NULL;       // Tail of partial product
        long long carry = 0;

        Dlist *t1 = *tail1;        // Traverse first number from LSB

        while (t1)                 // Digit × digit multiplication
        {
            long long mul = (long long)t1->data * t2->data + carry;
            insert_at_first(&tempH, &tempT, mul % BASE);
            carry = mul / BASE;
            t1 = t1->prev;
        }

        if (carry)                 // Insert remaining carry
            insert_at_first(&tempH, &tempT, carry);

        // Add zero shifting based on digit position
        for (int i = 0; i < shift; i++)
            insert_at_first(&tempH, &tempT, 0);

        // First partial result directly becomes final result
        if (*headR == NULL)
        {
            *headR = tempH;
            *tailR = tempT;
        }
        else  
        {
            Dlist *sumH = NULL;
            Dlist *sumT = NULL;

            addition(headR, tailR, &tempH, &tempT, &sumH, &sumT);

            free_list(headR, tailR); //free old result list 
            free_list(&tempH, &tempT);   //free temp partial product list

            *headR = sumH;
            *tailR = sumT;
        }

        shift++;                  // Increase shift for next digit
        t2 = t2->prev;            // Move to next digit of second number
    }

    return SUCCESS;
}
