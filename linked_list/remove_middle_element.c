//Delete middle element in the Linked list
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* Function to delete the middle of the linked list*/
void DeleteMiddle(struct node *head)
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;


    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        slow_ptr->data = slow_ptr->next->data;
        struct node *temp = slow_ptr->next->next;
        free(slow_ptr->next);
        slow_ptr->next = temp;
     //   printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}


void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

// A utility function to print a given linked list
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    int i;

    for (i=5; i>0; i--)
    {
        push(&head, i);
    }
    printList(head);
    DeleteMiddle(head);
    printList(head);
    return 0;
}

