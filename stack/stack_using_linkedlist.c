//Stack implementation using linked list at the beginning
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* top = NULL;

//This function inserts the element at the beginning of the linked list
void Push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->link = top;
    top = temp;
}

//This function removes the last inserted element
void Pop(){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
    if(top == NULL) return;
    temp = top;
    top = top->link;
    free(temp);
}

//Return the top value
int Top(){
    return top->data;
}

// This function will return 1 (true) if stack is empty, 0 (false) otherwise
int IsEmpty(){
    if (top->link == NULL) return 0;
    else return 1;
}
// This function is just to test the implementation of stack.
// This will print all the elements in the stack at any stage.
void Print()
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
    temp = top;
    printf("List is: ");
    while(temp != NULL){
	printf("%d",temp->data);
	temp=temp->link;
    }
    printf("\n");
}

int main() {
  // Code to test the implementation.
  // calling Print() after each push or pop to see the state of stack.
	Push(2);Print();
	Push(5);Print();
	Push(10);Print();
	Pop();Print();
	Push(12);Print();
}

