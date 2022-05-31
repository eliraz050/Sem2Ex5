#include <stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"
#include <crtdbg.h>

#define N 5

void main() {

    //initiate tree
    BST bst;
    initBST(&bst);

    //test functions on empty tree
    printTreeInorder(&bst);
    print_ascii_tree((bst.root));
    int result = findIndexNFromLast(&bst, N);
    if (result != -1) printf("%dth largest number: %d\n", N, result);
    (sameHeightLeaves(&bst)) ? printf("leaves are same height\n") : printf("leaves are not same height\n");

    //print_ascii_tree((bst.root));

    //insert nodes into binary tree
    insertBST(&bst, 5);
    insertBST(&bst, 2);
    insertBST(&bst, 1);
    insertBST(&bst, 1);
    insertBST(&bst, 2);
    insertBST(&bst, 4);
    insertBST(&bst, 5);
    insertBST(&bst, 8);
    insertBST(&bst, 8);
    insertBST(&bst, 8);
    insertBST(&bst, 9);

    //print tree in order, lowest to highest
    printTreeInorder(&bst);
    print_ascii_tree((bst.root));
    //print_ascii_tree((bst.root));

    //print the nth largest number in tree
    result = findIndexNFromLast(&bst, N);

    //print index if valid
    if (result != -1) printf("%dth largest number: %d\n", N, result);

    //test non-viable index
    result = findIndexNFromLast(&bst, 12);
    if (result != -1) printf("%dth largest number: %d\n", 12, result);

    //check if all leave are the same height
    (sameHeightLeaves(&bst)) ? printf("leaves are same height\n") : printf("leaves are not same height\n");

    //free tree
    destroyBST(&bst);

    _CrtDumpMemoryLeaks();
}
