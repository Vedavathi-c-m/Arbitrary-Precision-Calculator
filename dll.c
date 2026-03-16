#include "apc.h"   // Include APC header file with structure definitions and macros

// Function to insert a node at the beginning of the doubly linked list
int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = (Dlist *)malloc(sizeof(Dlist));   // Allocate memory for new node
    if (!new)                                      // Check memory allocation failure
        return FAILURE;

    new->data = data;                             // Store data in new node
    new->prev = NULL;                             // Set previous pointer as NULL
    new->next = *head;                            // Link new node to current head

    if (*head)                                    // If list is not empty
        (*head)->prev = new;                     // Update previous pointer of old head
    else                                          // If list is empty
        *tail = new;                             // New node becomes tail also

    *head = new;                                  // Update head to new node
    return SUCCESS;                               // Return success
}

// Function to split input string into 4-digit chunks and store in linked list
void insert_data(const char *argv, Dlist **head, Dlist **tail)
{
    char temp[5];                                 // Temporary buffer for 4-digit chunk
    int len = strlen(argv);                       // Get length of input string

    for (int i = len; i > 0; i -= 4)              // Loop from end, taking 4 digits at a time
    {
        int start = i - 4;                        // Calculate starting index
        if (start < 0)                            // If index becomes negative
            start = 0;                            // Set start to 0

        int num_digits = i - start;               // Number of digits in this chunk

        for (int j = 0; j < num_digits; j++)      // Copy digits into temp buffer
            temp[j] = argv[start + j];

        temp[num_digits] = '\0';                  // Add string terminator

        insert_at_first(head, tail, atoi(temp)); // Convert chunk to integer and insert
    }
}

// Function to display the linked list number properly
void display_list(Dlist *head)
{
    if (!head)                                    // If list is empty
    {
        printf("0\n");                           // Print 0
        return;
    }

    printf("%d", head->data);                    // Print first block normally
    head = head->next;                           // Move to next node

    while (head)                                 // Loop through remaining nodes
    {
        printf("%04d", head->data);              // Print with leading zeros
        head = head->next;                       // Move to next node
    }
    printf("\n");                                // Print newline
}

// Function to free the entire linked list
void free_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;                                 // Temporary pointer for deletion
    while (*head)                                // Loop until list becomes empty
    {
        temp = *head;                            // Store current head
        *head = (*head)->next;                   // Move head to next node
        free(temp);                              // Free current node
    }
    *tail = NULL;                                // Set tail to NULL
}

// Function to calculate length of the linked list
int get_length(Dlist *head)
{
    int len = 0;                                 // Initialize length counter
    while (head)                                 // Traverse through list
    {
        len++;                                   // Increment count
        head = head->next;                       // Move to next node
    }
    return len;                                  // Return final length
}

// Function to compare two linked list numbers
int compare_list(Dlist *head1, Dlist *head2)
{
    int len1 = get_length(head1);                // Get length of first number
    int len2 = get_length(head2);                // Get length of second number

    if (len1 > len2)                             // If first number has more digits
        return 1;                                // First number is greater
    if (len1 < len2)                             // If second number has more digits
        return 0;                                // First number is smaller

    while (head1 && head2)                       // If lengths are equal, compare blockwise
    {
        if (head1->data > head2->data)           // If block of first number is bigger
            return 1;                            // First number is greater
        if (head1->data < head2->data)           // If block of second number is bigger
            return 0;                            // First number is smaller

        head1 = head1->next;                     // Move to next block in first number
        head2 = head2->next;                     // Move to next block in second number
    }

    return 1;   /* Treat equal numbers as first >= second */
}

// Function to check if the number stored in linked list is zero
int is_zero(Dlist *head)
{
    return (head == NULL) ||                     // If list is empty
           (head->data == 0 && head->next == NULL); // Or only one node with value 0
}
