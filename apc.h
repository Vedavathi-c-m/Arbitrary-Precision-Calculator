#ifndef APC_H
#define APC_H
/* 
   These two lines are called HEADER GUARDS.
   They prevent the header file from being included multiple times,
   which avoids redefinition errors.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUCCESS 0
/* Macro representing successful function execution */
#define FAILURE 1
/* Macro representing failed function execution */
#define BASE 10000
/* 
   Each node will store 4 digits at a time.
   Example: 12345678 is stored as [1234] -> [5678]
   This makes large number operations efficient.
*/

typedef int data_t;
/* 
   data_t is a new name for int.
   It is used to store each 4-digit number chunk.
*/

typedef struct node
{
    struct node *prev;
    /* Pointer to the previous node in the doubly linked list */

    data_t data;
    /* Stores one 4-digit part of the big number */

    struct node *next;
    /* Pointer to the next node in the doubly linked list */

} Dlist;
/* 
   Dlist is the name of the doubly linked list node structure.
*/

 /* ========== VALIDATION FUNCTION ========== */

int read_and_validation(int argc, char *argv[]);
/*
  This function checks:
  1. Correct number of command-line arguments
  2. Valid operator (+, -, x, /)
  3. Valid digits in both numbers
  4. Prevents division by zero
*/

 /* ========== LINKED LIST HELPER FUNCTIONS ========== */

int insert_at_first(Dlist **head, Dlist **tail, int data);
/*
  Inserts a new node at the **beginning** of the doubly linked list.
*/

void insert_data(const char *argv, Dlist **head, Dlist **tail);
/*
  Converts a number string into a linked list.
  Breaks the number into 4-digit chunks and stores them as nodes.
*/

void display_list(Dlist *head);
/*
  Displays the big number stored in the linked list correctly.
*/

void free_list(Dlist **head, Dlist **tail);
/*
  Frees all nodes in the linked list to avoid memory leaks.
*/

int get_length(Dlist *head);
/*
  Returns the number of nodes present in the linked list.
*/

int compare_list(Dlist *head1, Dlist *head2);
/*
  Compares two big numbers.
  Returns 1 if head1 >= head2
  Returns 0 if head1 < head2
*/

int is_zero(Dlist *head);
/*
  Checks whether the linked list represents the number 0.
*/

 /* ========== ARITHMETIC OPERATIONS ========== */

int addition(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR);
/*
  Adds two big numbers and stores the result in headR.
*/

int subtraction(Dlist **head1, Dlist **tail1,
                Dlist **head2, Dlist **tail2,
                Dlist **headR, Dlist **tailR);
/*
  Subtracts second big number from the first one.
*/

int multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **headR, Dlist **tailR);
/*
  Multiplies two big numbers.
*/

int division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR);
/*
  Divides the first big number by the second big number.
*/
int modulus(Dlist **head1, Dlist **tail1,
            Dlist **head2, Dlist **tail2,
            Dlist **headR, Dlist **tailR);

int power(Dlist **head1, Dlist **tail1,
          Dlist **head2, Dlist **tail2,
          Dlist **headR, Dlist **tailR);

#endif
/* End of header guard */
