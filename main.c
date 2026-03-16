#include "apc.h"

int main(int argc, char *argv[])
{
    /* -------- MENU DISPLAY -------- */

    if (argc == 1)
    {
        printf("\n=====================================\n");
        printf("        Arbitrary Precision Calculator\n");
        printf("=====================================\n");

        printf("Operations Available:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");

        printf("\nUsage: %s <num1> <op> <num2>\n\n", argv[0]);

        return SUCCESS;
    }

    /* -------- VALIDATION -------- */

    if (read_and_validation(argc, argv) == FAILURE)
    {
        printf("INFO: Read and validation unsuccessfully\n");
        return FAILURE;
    }

    char operator = argv[2][0];

    int sign1 = 1, sign2 = 1, result_sign = 1;

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    /* -------- STORE NUMBERS -------- */

    if (argv[1][0] == '-')
    {
        sign1 = -1;
        insert_data(argv[1] + 1, &head1, &tail1);
    }
    else
    {
        insert_data(argv[1], &head1, &tail1);
    }

    if (argv[3][0] == '-')
    {
        sign2 = -1;
        insert_data(argv[3] + 1, &head2, &tail2);
    }
    else
    {
        insert_data(argv[3], &head2, &tail2);
    }

    /* -------- PRINT INPUTS -------- */

    printf("\n👉 Input 1  : %s\n\n", argv[1]);

    /* -------- OPERATOR DISPLAY -------- */

    switch(operator)
    {
        case '+':
            printf("👉 Operator : + (Addition)\n\n");
            break;

        case '-':
            printf("👉 Operator : - (Subtraction)\n\n");
            break;

        case 'x':
            printf("👉 Operator : x (Multiplication)\n\n");
            break;

        case '/':
            printf("👉 Operator : / (Division)\n\n");
            break;

        case '%':
            printf("👉 Operator : %% (Modulus)\n\n");
            break;

        case '^':
            printf("👉 Operator : ^ (Power)\n\n");
            break;

        default:
            printf("Invalid operator\n");
            return FAILURE;
    }

    printf("👉 Input 2  : %s\n\n", argv[3]);

    /* -------- CALCULATION -------- */

    switch(operator)
    {
        case '+':
            if (sign1 == sign2)
            {
                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                result_sign = sign1;
            }
            else
            {
                if(compare_list(head1,head2))
                {
                    subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                    result_sign = sign1;
                }
                else
                {
                    subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
                    result_sign = sign2;
                }
            }
            break;

        case '-':
            if(compare_list(head1,head2))
            {
                subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                result_sign = sign1;
            }
            else
            {
                subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
                result_sign = -1;
            }
            break;

        case 'x':
            multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            result_sign = sign1 * sign2;
            break;

        case '/':
            if(is_zero(head2))
            {
                printf("ERROR: Division by zero\n");
                return FAILURE;
            }

            division(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            result_sign = sign1 * sign2;
            break;

        case '%':
            modulus(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            break;

        case '^':
            power(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            break;
    }

    /* -------- RESULT DISPLAY -------- */

    printf("👉 RESULT   : ");

    if(result_sign == -1)
        printf("-");

    display_list(headR);

    /* -------- FREE MEMORY -------- */

    free_list(&head1,&tail1);
    free_list(&head2,&tail2);
    free_list(&headR,&tailR);

    return SUCCESS;
}