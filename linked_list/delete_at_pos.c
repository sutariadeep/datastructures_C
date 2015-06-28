//Linked List: Delete node at nth position
#include<stdlib.h>
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

//Delete the node at nth position
void Delete(int n)
{
    node *temp1 = head;
    if(n==1){
        head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for(i = 0;i<n-2;i++)
        temp1 = temp1->next;
    //temp1 points to (n-1)th node
    node *temp2 = temp1->next; //nth Node
    temp1->next = temp2->next;  // (n+1)th Node
    free(temp2); //delete temp2
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
    printf("Enter a position\n");
    scanf("%d",&n);
    Delete(n);
    Print();
}

