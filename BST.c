#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "TreePrintLibrary.h"

//check if pointer is null using macro
#define CHECK_NULL(ptr) do { if(!ptr) {printf ("pointer is null\n"); exit(1); }} while(0)

void initBST(BST* bst) {
	//initiate empty binary search tree
	bst->root = NULL;
}

void insertBST(BST* bst, int value) {
	//dynamically allocate new node, automatically sets left and right pointers to null
	TreeNode* newNode = (TreeNode*)calloc(1, sizeof(TreeNode));

	//checks that the allocation succeeded
	CHECK_NULL(newNode);
	
	//set sent value to new node's element
	newNode->element = value;

	// case empty tree
	if (bst->root == NULL) { 
		//set root to new node
		bst->root = newNode;
		return;
	}

	//call to recursive function to add new node
	insertRec(bst->root, newNode);		
}

void insertRec(TreeNode* root, TreeNode* newNode) {

	if (newNode->element <= root->element) { // left subtree
		if (root->left == NULL) // end of tree
			root->left = newNode; //insert node
		else
			insertRec(root->left, newNode); //continue to call recursively
	}
	if (newNode->element > root->element) { // right subtree
		if (root->right == NULL) // end of tree
			root->right = newNode; //insert node
		else
			insertRec(root->right, newNode); //continue to call recursively
	}
}

void printTreeInorder(BST* bst) {
	
	if (bst->root == NULL) { // case empty tree
		printf("Tree is empty\n");
		return;
	}

	//recursive in order print function
	inOrder(bst->root);

}

void inOrder(TreeNode* root) {

	if (root != NULL) {	
		inOrder(root->left);
		printf("%d ", root->element);
		inOrder(root->right);
	}
}

void destroyBST(BST* bst) {
	//calls recursive function to release all notes
	destroyREC(bst->root);
	//sets root to empty
	bst->root = NULL;
}

void destroyREC(TreeNode* root) {
	if (root == NULL) return;

	destroyREC(root->left);
	destroyREC(root->right);

	//free root on way back up from recursive function after reaching bottom leaf
	free(root);
}

int findIndexNFromLast(BST* bst, int N) {
	int res, size;
	size = howManyInTree(bst->root);
	if (N > size || N <= 0) {
		printf("not a viable number");
		exit(1);
	}
	if (bst->root == NULL) {
		printf("Empty tree");
		exit(1);
	}
	findIndexNFromLastREC(bst->root, &N, &res);
	return res;
}

int findIndexNFromLastREC(TreeNode* root, int* num, int* res) {
	if (root == NULL) return;
	findIndexNFromLastREC(root->right ,num, res);
	if (*num == 1) {
		*res = root->element;
		(*num)--;
	}
	findIndexNFromLastREC(root->left, num, res);
	(*num)--;
	if (*num == 1) *res = root->element;

}

int howManyInTree(TreeNode* root) {
	if (root == NULL) return 0;
	return 1 + howManyInTree(root->left) +  howManyInTree(root->right);
}

int sameHeightLeaves(BST* bst) {
	int temp = 0;
	int* num;
	num = &temp;

	if (bst->root == NULL) {
		printf("Empty tree");
		exit(1);
	}

	sameHeightLeavesREC(bst->root, num, 0);
	if (*num == -1) return 0;
	else return 1;


}

void sameHeightLeavesREC(TreeNode* root, int* num, int steps) {
	if (root->left == NULL && root->right == NULL) {
		if (*num == 0) {
			*num = steps;
		}
		else {
			if (steps != *num)
				*num = -1;
		}
		return;
	}
	if (root->left != NULL) {
		sameHeightLeavesREC(root->left, num, steps+1);
	}
	if (root->right != NULL) {
		sameHeightLeavesREC(root->right, num, steps+1);
	}
}

