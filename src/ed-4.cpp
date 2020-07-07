/**
  @file ed-4.cpp
  @author Lucas Vidor Migotto
  @version 0.0.1 07/07/2020
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char* elements;
  int length;
} Line;

void createLine (Line *line) {
  line->elements = (char *) malloc(sizeof(char));
  line->length = 0;
}

bool emptyLine (Line *line) {
  return !line->elements;
}

void appendToStart (char element, Line *line) {
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

void enterInLine (char element, Line *line) {
  if (emptyLine(line)) {
    createLine(line);
  }
  if (!line->elements[line->length]) {
    line->elements[line->length++] = element;
  } else {
    appendToStart(element, line);
  }
}

void printLine (Line *line) {
  int i;
  for (i = 0; i < line->length; i++) {
    printf(" %d", line->elements[i]);
  }
}

int main () {
  Line line;

  printf("Created line:\n");
  createLine(&line);

  enterInLine(2, &line);

  enterInLine(4, &line);

  printLine(&line);

  return 0;
}