//string reversal using stack

#include<iostream>
#include<stack>  // stack from standard template library (STL)
using namespace std;

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

//Reverse the linked list using stack
void Reverse(){
	if(head == NULL) return;
	stack<node*> S;
	node* temp = head;
	while(temp != NULL){
		S.push(temp);
		temp = temp->next;
	}
	temp = S.top(); 
	head = temp;
	S.pop();
	while(!S.empty()){
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
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
    Reverse();
    Print();
}