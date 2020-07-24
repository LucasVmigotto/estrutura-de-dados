/**
  @file Tree.cpp
  @author Lucas Vidor Migotto
  @version 0.0.1 21/07/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Node
 *
 * The greater value has to be ALWAYS
 * on the RIGHT
 * The Lower value has to be ALWAYS
 * on the LEFT
 *
 * Properties:
 * - int info: The value of the Node
 * - strcut Node *left: The pointer to the
 * left Node
 * - strcut Node *right: The pointer to the
 * right Node
*/
typedef struct Node {
	int info;
	struct Node *left;
	struct Node *right;
} NodeBin;

/*
 * Tree
 *
 * Properties:
 * - NodeBin *root: The original and
 * first Node
*/
typedef struct {
	NodeBin *root;
} Tree;

/*
 * Creates the Node putting the
 * given parameter
 *
 * @param info The data that will
 * be storage into the Node
 * @return The created Node
*/
NodeBin * createNode (int info) {
	NodeBin *aux = (NodeBin *) malloc(sizeof(NodeBin));
	if (aux != NULL) {
		aux->info = info;
		aux->left = NULL;
		aux->right = NULL;
	}
	return aux;
}

/*
 * Init the given tree with Null
 * as the value of the first Node
 *
 * @param tree The Tree that will be
 * initiated
*/
void initTree (Tree *tree) {
	tree->root = NULL;
}

/*
 * Check if the given Tree is
 * without Nodes
 *
 * @return True if the Tree is empty,
 * False if isn't
*/
bool emptyTree (Tree *tree) {
	return tree->root == NULL;
}

/*
 * Insert a new Node into a existing one
 *
 * @param newNode The new Node that will
 * be addded
 * @param current The current Node that will
 * be used to added the new one
 * @return True when the insertion was
 * successed
*/
bool insertNode (NodeBin *newNode, NodeBin *current) {
	if (newNode->info > current->info) {
		if (current->right == NULL) {
			current->right = newNode;
			return true;
		}
		return insertNode(newNode, current->right);
	}
	else {
		if (current->left == NULL) {
			current->left = newNode;
			return true;
		}
		return insertNode(newNode, current->left);
	}
}

/*
 * Insert into the given Tree the info
 * into a new Node
 *
 * @param tree The Tree that will be used
 * @param info The information that will
 * be added
 * @return True if the insertion was successed or
 * false if a error occurred
*/
bool insert (Tree *tree, int info) {
	NodeBin *newNode = createNode(info);
	if (newNode != NULL) {
		if (emptyTree(tree)) {
			tree->root = newNode;
			return true;
		}
		return insertNode(newNode, tree->root);
	}
	return false;
}

/*
 * Print in the console the given Node
 * in order
 *
 * @param node The Node that will be printed
*/
void showNodeInOrder (NodeBin *node) {
	if (node != NULL) {
		showNodeInOrder(node->left);
		printf ("%d ", node->info);
		showNodeInOrder(node->right);
	}
}

/*
 * Print in the console the given Tree
 * in order
 *
 * @param tree The Tree that will be printed
*/
void showTreeInOrder (Tree *tree) {
	if (emptyTree(tree)) {
		printf ("\nEmpty tree\n");
  } else {
		showNodeInOrder(tree->root);
  }
}

/*
 * Print in the console the give Node
 *
 * @param node The Node that will be printed
*/
void showNodeBeforeOrder (NodeBin *node) {
  if(node != NULL) {
    printf("%d ", node->info);
    showNodeBeforeOrder(node->left);
    showNodeBeforeOrder(node->right);
  }
}

/*
 * Print in the console the given Tree
 *
 * @param tree The Tree that will be printed
*/
void showTreeBeforeOrder (Tree *tree) {
  if(emptyTree(tree)) {
    printf("\nEmpty tree");
  } else {
    showNodeBeforeOrder(tree->root);
  }
}

/*
 * Return the grater value of the given Node
 *
 * @param node The Node that will be checked
*/
int greaterTree (NodeBin *node) {
  return node->right == NULL
    ? node->info
    : greaterTree(node->right);
}

/*
 * Return the grater value of the given Tree
 *
 * @param tree The Tree that will be checked
*/
int greater (Tree *tree) {
	return greaterTree(tree->root);
}

/*
 * Count the number of Nodes recursively
 *
 * @param node The Node that will be used
*/
int countNodes (NodeBin *node) {
  return node != NULL
    ? 1 + countNodes(node->left) + countNodes(node->right)
	  : 0;
}

/*
 * Count the nunber of Nodes into
 * the given Tree
 *
 * @param tree The Tree that will be used
*/
int numberOfNodes (Tree *tree) {
  return !emptyTree(tree)
    ? countNodes(tree->root)
    : 0;
}

int main () {
	int i, j;
	Tree tree;

  initTree(&tree);

  for (i=0; i<12; i++) {
		j = rand() % 20;
		printf ("%d ", j);
		insert(&tree, j);
	}

	printf("\n\nTree - in order\n");
	showTreeInOrder(&tree);

	if (emptyTree(&tree)) {
		printf ("\nEmpty tree\n");
	} else {
		printf ("\nGreater element = %d\n", greater(&tree));
  }
	printf ("\nnumero de nos da arvore = %d\n", numberOfNodes(&tree));

	return 0;
}