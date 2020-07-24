/**
  @file Tree.cpp
  @author Lucas Vidor Migotto
  @version 0.0.1 21/07/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int info;
	struct Node *left;
	struct Node *right;
} NodeBin;

typedef struct {
	NodeBin *root;
} Tree;

NodeBin * createNode (int i) {
	NodeBin *aux = (NodeBin *) malloc(sizeof(NodeBin));
	if (aux != NULL) {
		aux->info = i;
		aux->left = NULL;
		aux->right = NULL;
	}
	return aux;
}

void initTree (Tree *tree) {
	tree->root = NULL;
}

bool emptyTree (Tree *tree) {
	return tree->root == NULL;
}

bool insertNode (NodeBin *newNode, NodeBin *current) {
	if (newNode->info > current->info) {
		if (current->right == NULL) {
			current->right = newNode;
			return true;
		}
		return insertNode(newNode, current->left);
	}
	else {
		if (current->left == NULL) {
			current->left = newNode;
			return true;
		}
		return insertNode(newNode, current->left);
	}
}

bool insert (int i, Tree *tree) {
	NodeBin *newNode = createNode(i);
	if (newNode != NULL) {
		if (emptyTree(tree)) {
			tree->root = newNode;
			return true;
		}
		return insertNode(newNode, tree->root);
	}
	return false;
}

void showNodeInOrder (NodeBin *current) {
	if (current != NULL) {
		showNodeInOrder(current->left);
		printf ("%d ", current->info);
		showNodeInOrder(current->right);
	}
}

void showTreeInOrder (Tree *tree) {
	if (emptyTree(tree)) {
		printf ("\nEmpty tree\n");
  } else {
		showNodeInOrder(tree->root);
  }
}

void showNodeBeforeOrder (NodeBin *current) {
  if(current != NULL) {
    printf("%d ", current->info);
    showNodeBeforeOrder(current->left);
    showNodeBeforeOrder(current->right);
  }
}

void showTreeBeforeOrder (Tree *tree) {
  if(emptyTree(tree)) {
    printf("\nEmpty tree");
  } else {
    showNodeBeforeOrder(tree->root);
  }
}

int greaterTree (NodeBin *current) {
  return current->right == NULL
    ? current->info
    : greaterTree(current->right);
}

int greater (Tree *tree) {
	return greaterTree(tree->root);
}

int countNodes (NodeBin *current) {
  return current != NULL
    ? 1 + countNodes(current->left) + countNodes(current->right)
	  : 0;
}

int numberOfNodes (Tree *tree) {
  return !emptyTree(tree)
    ? countNodes(tree->root)
    : 0;
}

int main () {
	int i, j;
	Tree tree;

  initTree(&tree);
	srand(time(0));

  for (i=1; i<=12; i++) {
		j = rand() % 20;
		printf ("%d ", j);
		insert(j, &tree);
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