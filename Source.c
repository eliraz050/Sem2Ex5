#include <stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"
#include <crtdbg.h>

void main() {
	BST bst;
	
	initBST(&bst);

	printTreeInorder(&bst);
	print_ascii_tree((bst.root));
	printf("Nth largest number: %d\n", findIndexNFromLast(&bst, -1));
	(sameHeightLeaves(&bst))? printf("leaves are same height") : printf("leaves are not same height");

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
	

	printTreeInorder(&bst);
	print_ascii_tree((bst.root));
	printf("%d", findIndexNFromLast(&bst, -1));
	printf("%d", sameHeightLeaves(&bst));
	destroyBST(&bst);
	_CrtDumpMemoryLeaks();


}