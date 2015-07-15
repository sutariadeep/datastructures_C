//Linked List: Reverse a linked list using Recursive method
#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
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

//Reverse the linked list in Recursive method
void Reverse(node *p){
    if (p->next == NULL){
        head = p;
        return;
    }
    Reverse(p->next);
    node *q = p->next;
    q->next = p;
    p->next = NULL;
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

int main(){
    head=NULL;
    printf("How many numbers?\n");
    int i,n,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the number \n");
        scanf("%d",&x);
        Insert(x);
        Print();
    }
    printf("After reversing the List is: \n");
    Reverse(head);
    Print();
}

