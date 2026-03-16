#include "apc.h"

int power(Dlist **head1, Dlist **tail1,
          Dlist **head2, Dlist **tail2,
          Dlist **headR, Dlist **tailR)
{
    int exponent = (*head2)->data;

    Dlist *tempH = NULL;
    Dlist *tempT = NULL;

    insert_at_first(&tempH, &tempT, 1);

    for(int i = 0; i < exponent; i++)
    {
        Dlist *resH = NULL;
        Dlist *resT = NULL;

        multiplication(&tempH,&tempT,head1,tail1,&resH,&resT);

        free_list(&tempH,&tempT);

        tempH = resH;
        tempT = resT;
    }

    *headR = tempH;
    *tailR = tempT;

    return SUCCESS;
}