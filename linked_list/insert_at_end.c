//Linked List: Inserting a node at end
#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node node;
node *head; //global variable, can be accesses anywhere


//Insert the element at the end of the linked list
void Insert(int data){
    node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) head = temp;
    else{
        node* temp1 = head;
        while(temp1->next!= NULL) temp1 = temp1->next;
        temp1->next = temp;
    }
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
}