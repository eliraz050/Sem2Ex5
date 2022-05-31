#ifndef _BST_ADT_H //if _BST_ADT_H has not been previously defined in code, then do so

#define _BST_ADT_H

typedef struct TreeNode TreeNode;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int element;
};

typedef struct BST
{
    TreeNode* root;
}BST;

void initBST(BST* bst);
void insertBST(BST* bst, int value);
void printTreeInorder(BST* bst);
void insertRec(TreeNode* root, TreeNode* newNode);
void inOrder(TreeNode* root);
void destroyBST(BST* bst);
void destroyREC(TreeNode* root);
int findIndexNFromLast(BST* bst, int N);
int findIndexNFromLastREC(TreeNode* root, int N);
int howManyInTree(TreeNode* root);
int sameHeightLeaves(BST* bst);
void sameHeightLeavesREC(TreeNode* root, int* num, int steps);


#endif // !_BST_ADT_H

