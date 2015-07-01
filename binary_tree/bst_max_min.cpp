// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it
#include<iostream>
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree.
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree.
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
//To search a minimum element in BST, returns element if found
int FindMin(BstNode* root){
    if(root == NULL){
        cout<<"Error: Tree is empty\n";
        return -1;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}
//To search a maximum element in BST, returns element if found
int FindMax(BstNode* root){
    if(root == NULL){
        cout<<"Error: Tree is empty\n";
        return -1;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}
int main() {
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	// Call the FindMin and FindMax functions
	int min_no = FindMin(root);
	int max_no = FindMax(root);
	printf("The minimum and maximum number of the BST given are: %d and %d respectively\n", min_no, max_no);
}

