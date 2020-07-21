/**
  @file ed-5.cpp
  @author Lucas Vidor Migotto
  @version 0.0.1 21/07/2020
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int info;
	Node *next;
};

Node *createNode (int i) {
	Node * aux;
	aux = (Node *) malloc(sizeof (Node));
	if (aux != NULL) {
		aux->info = i;
		aux->next = NULL;
	}
	return aux;
}

typedef struct {
	Node * first;
} List;

void initList (List *list) {
	list->first = NULL;
}

int emptyList (List *list) {
  return list->first == NULL
    ? 1
    : 0;
}

int insertOnStart (List *list, int i) {
	Node * newNode = createNode(i);
	if (newNode != NULL) {
		if (!emptyList(list)) {
			newNode->next = list->first;
		}
		list->first = newNode;
		return 1;
	}
	return 0;
}

int removeFromStart (List *list) {
	Node * aux;
	int i;
	aux = list->first;
	i = aux->info;
	list->first = list->first->next;
	free(aux);
	return i;
}

void showList (List *list) {
	Node *aux;
	if (emptyList(list)) {
		printf ("Empty List");
	}
	else {
		aux = list->first;
		while (aux != NULL) {
			printf ("%d ", aux->info);
			aux = aux->next;
		}
	}
	printf ("\n");
}

void testList() {
	List list;
	int i;

  initList(&list);

  if (emptyList(&list)) {
		printf ("List successfully created!\n");
  } else {
		printf ("An error occurred during list creation\n");
  }

  for (i = 0; i < 5; i++) {
		insertOnStart(&list, i);
		showList(&list);
	}
	while (!emptyList(&list)) {
		printf ("%d was removed from the List\n", removeFromStart(&list));
		showList(&list);
	}
}

int main () {
  testList();
  return 0;
}