/**
  @file Stack.cpp
  @author Lucas Vidor Migotto
  @version 0.0.1 06/07/2020
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Stack
 *
 * Properties:
 * - int *data: An array of int values
 * - int top: The current amount of values
 * in the data array
 * - int length: Indicate the stack length
*/
typedef struct {
	int *data;
	int top;
	int length;
} Stack;

/*
 * This method initialize the Stack
 *
 * Define the top as 0 and the length with the
 * value in the parameter.
 *
 * @param stack The stack that will be crated
 * @param length The length of the future stack
*/
void createStack (Stack *stack, int length) {
	stack->data = (int *) malloc (length * sizeof(int));
	stack->top = 0;
	stack->length = length;
}

/*
 * Empty Stack
 *
 * This method checks if the Stack
 * informed is empty
 *
 * @param stack The stack that will be checked
 * @return True if there isn't any values
 * in the array, otherwise False
*/
bool isEmpty (Stack *stack) {
	return !stack->top;
}

/*
 * Filled Stack
 *
 * This method check if the Stack
 * is already full filled with values
 *
 * @param stack The stack that will be checked
 * @return True if the stack have all
 * positions with values, otherwise False
*/
bool isFill(Stack *stack) {
  return stack->top==stack->length;
}

/*
 * Push Element
 *
 * This method pushes a element into
 * the top of the informed Stack
 *
 * @param element The element that will be pushed
 * @param stack The stack that will receive the value
*/
void pushElement (int element, Stack *stack) {
	stack->data[stack->top++] = element;
}

/*
 * Remove Element
 *
 * This method remove the element in the
 * top of the informed stack
 *
 * @param stack The stack that will have the
 * first element removed
 * @return The elemente that have been
 * remove from the stack
*/
int popElement (Stack *stack) {
	return stack->data[--stack->top];
}

/*
 * Query the first element
 *
 * This methid inform witch element
 * is current in the stack's top
 *
 * @param stack The stack that will be checked
 * @return The value on the top of the
 * given stack
*/
int querytopElement (Stack *stack) {
  return stack->data[stack->top-1];
}

/*
 * Same stacks
 *
 * This method check if two stacks have
 * the exactly same lengths and elements
 *
 * @param one The first stack
 * @param two The second stack
 * @return True only if is the same
 * length and values, otherwise False
*/
bool isSame (Stack *one, Stack *two) {
  if (one->length != two->length) {
    return false;
  }

  int i, equals = 0;

  for (i = 0; i < one->length; i++) {
    equals = one->data[i] == two->data[i]
      ? equals + 1
      : equals;
  }

  return equals == one->length;
}

/*
 * Send elements to other
 *
 * Send the elements of one stack to
 * other.
 *
 * @param original The first stack
 * @param clone The second stack with the
 * same size from the first one
*/
void sendElements (Stack *original, Stack *clone) {
  int i, length = original->length;

  createStack(clone, length);

  for (i = 0; i < length; i++) {
    pushElement(popElement(original), clone);
  }
}

/*
 * Parse decimal to binary
 *
 * Receive a decimal value to
 * a binary value
 *
 * @param decimal The decimal value
 * @param stack The stack to be used
*/
void toBinary (int decimal, Stack *stack) {
  if (decimal > 0) {
    pushElement(decimal % 2, stack);
    toBinary(decimal / 2, stack);
  }
}

/*
 * Print the stack
 *
 * Print the received stack
 * into the console
 *
 * @param stack The decimal value
*/
void printStack (Stack *stack) {
  if (isEmpty(stack)) {
    printf("This stack is empty");
    return;
  }
  int i;
  for(i = stack->top - 1; i >= 0; i--) {
    printf("%d", stack->data[i]);
  }
}

int main() {

  Stack stack;
  int element;

  createStack(&stack, 8);

  printf("Insert the value to be parsed: ");
  scanf("%d", &element);

  if (element < 0 || element > 255) {
    printf("This version only supports numbers up to 255");
    return 1;
  }

  toBinary(element, &stack);

  printStack(&stack);

  return 0;
}