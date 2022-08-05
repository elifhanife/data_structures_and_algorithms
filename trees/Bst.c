#include <stdio.h>
#include <stdlib.h>//for random function
#include <time.h>//for time() function

struct treeNode {//create a struct to represent a tree node which has a data and two children.
	int data;
	struct treeNode* leftPtr, * rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode* TreeNodePtr;

//prototypes
void insertNode(TreeNodePtr* treePtr, int value);
void preorder(TreeNodePtr treePtr);
void inorder(TreeNodePtr treePtr);
void postorder(TreeNodePtr treePtr);

TreeNodePtr root = NULL;//pointer to root node and setting tree as empty.
int randNum;//an integer variable to hold the randomly generated number.


int main() {


	srand(time(NULL));//to have the random function generate different numbers.

	printf("The numbers being placed in the tree are:\n");

	for (int i = 0; i < 10; i++) {
		randNum = (rand() % 25) + 1;
		insertNode(&root, randNum);
		printf("%d ", randNum);
	}

	printf("\n");
	printf("The preorder traversal is:\n"); preorder(root);
	printf("\n");
	printf("The inorder traversal is:\n"); inorder(root);
	printf("\n");
	printf("The postorder traversal is:\n"); postorder(root);
	printf("\n");

	return 0;
}

void insertNode(TreeNodePtr* treePtr, int value) {

		if (*treePtr == NULL) {
			(*treePtr) = malloc(sizeof(TreeNode));
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		else if (value == (*treePtr)->data) {
			randNum = (rand() % 25) + 1;
			insertNode(&root, randNum);
		}
		else if (value < (*treePtr)->data) {
			insertNode(&((*treePtr)->leftPtr), value);
		}
		else if (value > (*treePtr)->data) {
			insertNode(&((*treePtr)->rightPtr), value);
		}
}

void preorder(TreeNodePtr treePtr) {//root-left-right

	if (treePtr != NULL) {
		printf("%d ", treePtr->data);
		preorder(treePtr->leftPtr);
		preorder(treePtr->rightPtr);
	}
}


void inorder(TreeNodePtr treePtr) { //left-root-right

	if (treePtr != NULL) {
		inorder(treePtr->leftPtr);
		printf("%d ", treePtr->data);
		inorder(treePtr->rightPtr);
	}
}

void postorder(TreeNodePtr treePtr) {//left-right-root

	if (treePtr != NULL) {
		postorder(treePtr->leftPtr);
		postorder(treePtr->rightPtr);
		printf("%d ", treePtr->data);
	}
}