#include "apc.h"   // Include APC header file with macros and function prototypes

// Function to validate command-line input arguments
int read_and_validation(int argc, char *argv[])
{
    if (argc != 4)   // Check if correct number of arguments is provided
    {
        printf("Usage: %s <num1> <op> <num2>\n", argv[0]);
        printf("Operators: +  -  x  /  %%  ^\n");
        return FAILURE;
    }

    char op = argv[2][0];   // Extract operator

    /* Allow all supported operators */
    if (!(op == '+' || op == '-' || op == 'x' || op == '/' || op == '%' || op == '^'))
    {
        printf("ERROR: Invalid operator\n");
        return FAILURE;
    }

    /* Validate num1 and num2: optional leading '-', then digits */
    for (int arg = 1; arg <= 3; arg += 2)
    {
        char *s = argv[arg];
        int i = 0;

        if (s[0] == '-')
            i++;

        if (s[i] == '\0')
        {
            printf("ERROR: Empty number\n");
            return FAILURE;
        }

        for (; s[i] != '\0'; i++)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                printf("ERROR: Invalid digit in %s\n", s);
                return FAILURE;
            }
        }
    }

    /* Division by zero check */
    if (op == '/')
    {
        char *s = argv[3];
        int i = 0;

        if (s[0] == '-')
            i++;

        int all_zero = 1;

        for (; s[i] != '\0'; i++)
        {
            if (s[i] != '0')
            {
                all_zero = 0;
                break;
            }
        }

        if (all_zero)
        {
            printf("ERROR: Division by zero\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}