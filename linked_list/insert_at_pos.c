//Linked List: Inserting node at nth position
#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node node;
node *head; //global variable, can be accesses anywhere

#Insert the data as per the node number n
void Insert(int data,int n){
    node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;
    if(n==1){
	temp1->next = head;
	head = temp1;
	return;
    }
    node * temp2 = head;
    for(int i=0;i<n-2;i++){
	temp2 = temp2->next;	
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

#Print the linked list
void Print()
{
    node * temp = head;
    printf("List is: ");
    while(temp != NULL){
	printf("%d",temp->data);
	temp=temp->next;
    }
    printf("\n");
}
int main(){
    head = NULL; //empty list
    Insert(2,1); //List: 2
    Insert(3,2); //List: 2,3
    Insert(4,1); //List: 4,2,3
    Insert(5,2); //List: 4,5,2,3
    Print();
}
 
