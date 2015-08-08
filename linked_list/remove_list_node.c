//Linked List: Delete node containing n value in the node
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node node;
node *head; //global variable, can be accesses anywhere

//Insert at the beginning of the linked list
void Insert(int x){
    node *temp = (node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

//Print the linked list
void Print()
{
    node *temp = head;
    printf("List is: ");
    while(temp != NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//Delete the node containing value n
void Delete(int n)
{
    if (head == NULL) return; // if the list is empty after (1) above, we're done

    //remove leading nodes containing search value
    while(head != NULL && head->data == n){
            node *temp = head;
            head = head->next;
            free(temp);
    }

    /*
     * 3. walk through the list and delete any remaining nodes containing the
     *    search value. Note that, at this point, head points to a node that
     *    does NOT contain the search value. We have to only check if
     *    head->next (if it exists) contains the search value.
    */
    node *current = head;
    while (current->next != NULL){
        if (current->next->data == n){
            node *temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else{
            current = current->next;
        }
    }

}



//Main functon
int main(){
    head = NULL; //empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); //List: 2,4,6,5
    Print();
    int n;
    printf("Enter the data to be deleted\n");
    scanf("%d",&n);
    Delete(n);
    Print();
}