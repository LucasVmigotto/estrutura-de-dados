/**
  @file ed-5.cpp
  @author Lucas Vidor Migotto
  @version 0.0.1 21/07/2020
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * List
 *
 * Properties:
 * - int info: The value of the info
 * - Node *next: The pointer of the next
 * item in the List
*/
struct Node{
	int info;
	Node *next;
};

/*
 * Create the Node
 *
 * Create the Node in the list
 *
 * @param The value of the Node's info
 * @return The value of the Node
*/
Node *createNode (int i) {
	Node * aux;
	aux = (Node *) malloc(sizeof (Node));
	if (aux != NULL) {
		aux->info = i;
		aux->next = NULL;
	}
	return aux;
}

/*
 * List
 *
 * Properties:
 * - Node *first: The first value of the
 * list
*/
typedef struct {
	Node *first;
} List;

/*
 * Init the List's value
 *
 * Initiate the List with the first
 * value as Null
 *
 * @param The List pointer that will be
 * initialize
*/
void initList (List *list) {
	list->first = NULL;
}

/*
 * Empty List
 *
 * Return if the List is empty
 *
 * @param The List that will be checked
 *
 * @return Return True if empty
 * or False if isn't
*/
bool emptyList (List *list) {
  return list->first == NULL;
}

/*
 * Insert On Start
 *
 * Insert the given element on the Start
 * of the List
 *
 * @param The List that will be used
 * @param The element that will be added
 * @return Return True if the element was
 * successfully added
*/
bool insertStart (List *list, int i) {
	Node *newNode = createNode(i);
	if (newNode != NULL) {
		if (!emptyList(list)) {
			newNode->next = list->first;
		}
		list->first = newNode;
		return true;
	}
	return false;
}

/*
 * Remove from the Start
 *
 * Remove an element from the start
 * of the list
 *
 * @param The List that will be used to
 * remove the element
 * @return The element that has been removed
*/
int removeFromStart (List *list) {
	Node * aux;
	int i;
	aux = list->first;
	i = aux->info;
	list->first = list->first->next;
	free(aux);
	return i;
}

/*
 * Show List
 *
 * Show the elements that exists in
 * the List
 *
 * @param The List that will be printed
*/
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

/*
 * Nodes count
 *
 * Return the node count that exists
 * in the List
 *
 * @param The List that will be used to
 * count the Nodes
 * @return The number of nodes
*/
int nodeCount (List *list) {
	if (emptyList(list)) {
		return 0;
	}
	int count = 0;
	Node *aux = list->first;
	while (aux != NULL) {
		count++;
    aux = aux->next;
	}
	return count;
}

/*
 * Insert in the Middle
 *
 * Insert the given element in the
 * informed position, if the position is
 * greater than the List node count
 * the element will be inserted in the end
 * of the List
 *
 * @param The List that will be used to
 * insert the element
 * @param The position to insert the element
 * @param The info value to be replaced/inserted
*/
void insertMiddle (List *list, int position, int info) {
  if (position > nodeCount(list)) {
    insertStart(list, info);
  }
  int i;
  List *start;
  initList(start);
  for (i = 0; i < nodeCount(list); i++) {
    if (i < position ) {
      insertStart(start, removeFromStart(list));
    }
  }
  insertStart(list, info);
  removeFromStart(start);
  insertStart(list, removeFromStart(start));
}

/*
 * Values Average
 *
 * Return the values average that
 * exists in the List
 *
 * @param The List that will be used to
 * calculate the average
 * @return The values average
*/
double valuesAverage (List *list) {
  int values = 0, i = 0;
  int total = nodeCount(list);
  Node *node = list->first;

  while (i < total) {
    values += node->info;
    node = node->next;
    i++;
  }

  return values / nodeCount(list);
}

/*
 * Test List
 *
 * Test the logic of the List algorithm
*/
void testList () {
	List list;
	int i;

  initList(&list);

  if (emptyList(&list)) {
	  printf ("List successfully created!\n");
  } else {
  	printf ("An error occurred during list creation\n");
  }

  for (i = 0; i < 5; i++) {
		insertStart(&list, i);
		showList(&list);
	}

	printf("Nodes count on the list: %d\n", nodeCount(&list));

  printf("Average of the values of the List: %2.2f\n", valuesAverage(&list));

  printf("Changing the 2nd element for '8'\n");

  insertMiddle(&list, 2, 8);

  showList(&list);

	while (!emptyList(&list)) {
		printf ("%d was removed from the List\n", removeFromStart(&list));
		showList(&list);
	}
}

int main () {
  testList();
  return 0;
}