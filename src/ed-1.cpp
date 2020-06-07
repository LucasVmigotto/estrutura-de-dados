#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct {
  int matricula;
  char nome;
  char curso;
} Aluno;

void printAluno (Aluno aluno, int i) {
  printf("##\t %do Aluno\t ##\n", i + 1);
  printf("Matrícula:\t%d\n", aluno.matricula);
  printf("Nome:\t%c\n", aluno.nome);
  printf("Curso:\t%c\n", aluno.curso);
}

int main () {
  const int total = 2;
  int i;

  Aluno alunos[total];

  for (i = 0; i < total; i++) {
    printf("Matrícula do %do aluno: ", i + 1);
    scanf("%d", &alunos[i].matricula);
    printf("Nome do %do aluno: ", i + 1);
    scanf("%s", &alunos[i].nome);
    printf("Curso do %do aluno: ", i + 1);
    scanf("%s", &alunos[i].curso);
    system("clear");
  }

  for (i = 0; i < total; i++) {
    printAluno(alunos[i], i);
    if (i < total - 1) {
      printf("\n-------------------------\n");
    }
  }
  return 0;
}