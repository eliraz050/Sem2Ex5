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

	//checks that the allocation succeeded using macro
	CHECK_NULL(newNode);

	//set value to new node's element
	newNode->element = value;

	// case empty tree
	if (bst->root == NULL) {
		//set root to new node
		bst->root = newNode;
		return;
	}

	//otherwise call to recursive function to add new node
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
		printf("Tree is empty, cannot print\n");
		return;
	}

	//recursive in order print function
	inOrder(bst->root);

	printf("\n");

}

void inOrder(TreeNode* root) {
	//prints in order from lowest to highest
	if (root != NULL) {
		inOrder(root->left);
		printf("%d ", root->element);
		inOrder(root->right);
	}
}

void destroyBST(BST* bst) {
	//calls recursive function to release all nodes
	destroyREC(bst->root);
	//sets root to empty
	bst->root = NULL;
}

void destroyREC(TreeNode* root) {
	if (root == NULL) return;

	destroyREC(root->left);
	destroyREC(root->right);

	//free root on way back up from recursive function after reaching end of tree
	free(root);
}

int findIndexNFromLast(BST* bst, int N) {
	int size;

	//case tree is empty
	if (bst->root == NULL) {
		printf("Empty tree, cannot find index from last number\n");
		return -1;
	}

	//check how many nodes are in tree
	size = howManyInTree(bst->root);

	//if N is more than the numbers in the tree or less than or equal to zero, it's not a valid index
	if (N > size || N <= 0) {
		printf("%d is not a viable index\n", N);
		return -1;
	}

	//find index from largest number in recursive function and return
	return findIndexNFromLastREC(bst->root, N);

}

int findIndexNFromLastREC(TreeNode* root, int N) {
	// end condition
	if (root == NULL) return;
	 
	// count number of branches in right tree and add 1 for the root.
	int size = howManyInTree(root->right) + 1;

	// return Nth highest number
	if (size == N) {
		return root->element;
	}

	// if more branches down then N means N is somewhere to the right
	if (size > N) {
		return findIndexNFromLastREC(root->right, N);
	}
	// if less branches down then N means is somwhere to the left
	if (size < N) {
		return findIndexNFromLastREC(root->left, N-size);
	}

}

int howManyInTree(TreeNode* root) {

	//end condition
	if (root == NULL) return 0;

	//add one until we have traversed entire tree in recursive calls down right and left branches, return amount of nodes in tree
	return 1 + howManyInTree(root->left) + howManyInTree(root->right);
}

int sameHeightLeaves(BST* bst) {

	int num = 0;

	//empty case
	if (bst->root == NULL) {
		printf("Empty tree, height is zero\n");
		return -1;
	}

	//call recursive function to calculate same height
	sameHeightLeavesREC(bst->root, &num, 0);

	//if height isn't the same return 0
	if (num == -1) return 0;

	//if the same return 1
	else return 1;
}

void sameHeightLeavesREC(TreeNode* root, int* num, int steps) {
	//if we have reached the end of a branch
	if (root->left == NULL && root->right == NULL) {
		//if this is the first time, set number to steps
		if (*num == 0) {
			*num = steps;
		}
		else {
			//otherwise, if we have reached another bottom branch compare it to old ones, if unequal, return -1
			if (steps != *num)
				*num = -1;
		}
		return;
	}
	//go down to the left
	if (root->left != NULL) {
		sameHeightLeavesREC(root->left, num, steps + 1);
	}
	//go down to the right
	if (root->right != NULL) {
		sameHeightLeavesREC(root->right, num, steps + 1);
	}
}

