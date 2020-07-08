/**
  @file ed-4.cpp
  @author Lucas Vidor Migotto
  @version 0.0.1 07/07/2020
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Line
 *
 * Properties:
 * - int *elements: An array of char values
 * - int length: Indicate the line length
*/
typedef struct {
  char* elements;
  int length;
} Line;

/*
 * This method create the Line
 *
 * Define the length as 0 and initialize
 * the line of elements
 *
 * @param The line that will be crated
*/
void createLine (Line *line) {
  line->elements = (char *) malloc(sizeof(char));
  line->length = 0;
}

/*
 * Empty Line
 *
 * This method check if the Line
 * is empty
 *
 * @param The line that will be checked
*/
bool emptyLine (Line *line) {
  return !line->elements;
}

/*
 * Append to the Start
 *
 * Append the given element to the
 * end of the line
 *
 * @param The element to be added
 * @param The line that will be used
*/
void appendToEnd (char element, Line *line) {
  int i;
  char *temp = (char *) malloc(line->length + 1 * sizeof(char));
  for (i = 0; i < line->length; i++) {
    if (line->elements[i]) {
      temp[i] = line->elements[i];
    } else {
      continue;
    }
  }
  temp[line->length + 1] = element;
  line->elements = temp;
  line->length++;
}

/*
 * Enter in line
 *
 * Insert an element to the right
 * position at the line
 *
 * @param The element to be added
 * @param The line that will be used
*/
void enterInLine (char element, Line *line) {
  if (emptyLine(line)) {
    createLine(line);
  }
  if (!line->elements[line->length]) {
    line->elements[line->length++] = element;
  } else {
    appendToEnd(element, line);
  }
}

/*
 * Print line elements
 *
 * Print all the line elements already
 * added
 *
 * @param The line that will be printed
*/
void printLine (Line *line) {
  int i;
  for (i = 0; i < line->length; i++) {
    printf(" %d", line->elements[i]);
  }
  printf("\n");
}

/*
 * Line Walk
 *
 * This method remove the first
 * element of the line and puts
 * every other element in line
 * one position ahead.
 *
 * @param The line that will be
 * manipulated
*/
void lineWalk (Line *line) {
  if (emptyLine(line) || line->length == 0) {
    printf("Empty");
    return;
  }
  char *temp = (char *) malloc(line->length - 1 * sizeof(char));
  int i;
  for (i = 1; i < line->length; i++) {
    temp[i - 1] = line->elements[i];
  }
  line->elements = temp;
  line->length--;
}

int main () {
  Line line;

  printf("Created line:\n");
  createLine(&line);

  enterInLine(2, &line);

  printLine(&line);

  enterInLine(4, &line);

  printLine(&line);

  enterInLine(6, &line);

  printLine(&line);

  printf("Line Walk\n");

  lineWalk(&line);

  printLine(&line);

  printf("Line Walk\n");

  lineWalk(&line);

  printLine(&line);

  enterInLine(8, &line);

  printLine(&line);

  lineWalk(&line);

  printLine(&line);

  return 0;
}