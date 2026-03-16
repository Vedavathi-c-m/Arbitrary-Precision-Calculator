#include "apc.h"

int modulus(Dlist **head1, Dlist **tail1,
            Dlist **head2, Dlist **tail2,
            Dlist **headR, Dlist **tailR)
{
    if (is_zero(*head2))
    {
        printf("ERROR: Modulus by zero\n");
        return FAILURE;
    }

    /* division leaves remainder in head1 */
    Dlist *qH = NULL;
    Dlist *qT = NULL;

    division(head1, tail1, head2, tail2, &qH, &qT);

    /* remainder is now in head1 */
    *headR = *head1;
    *tailR = *tail1;

    free_list(&qH, &qT);

    return SUCCESS;
}