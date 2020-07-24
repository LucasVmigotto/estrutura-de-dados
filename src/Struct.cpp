#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/*
 * Aluno
 *
 * Properties:
 * - int matricula: A matrícula do Aluno
 * - char nome: O nome do Aluno
 * - char curso: O curso estudado
*/
typedef struct {
  int matricula;
  char nome;
  char curso;
} Aluno;

/*
 * printAluno
 *
 * Imprime no console os dados do aluno
 *
 * @param aluno O Aluno que será impresso
*/
void printAluno (Aluno aluno) {
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
    printf("##\t %do Aluno\t ##\n", i + 1);
    printAluno(alunos[i]);
    if (i < total - 1) {
      printf("\n-------------------------\n");
    }
  }
  return 0;
}