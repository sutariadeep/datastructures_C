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
//To find the height of the tree
int FindHeight(BstNode *root){
    if (root == NULL){
        return -1;
    }
    int left_height = FindHeight(root->left);
    int right_height = FindHeight(root->right);
    return max(left_height, right_height) + 1;
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
	root = Insert(root,35);
	root = Insert(root,2);
	root = Insert(root,22);

	// Call the FindMin and FindMax functions
	int height = FindHeight(root);
	printf("The height of the BST is %d \n", height);
}

