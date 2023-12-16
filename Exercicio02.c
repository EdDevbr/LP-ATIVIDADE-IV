/*
Crie uma função chamada "calcularMedia" que recebe como parâmetro uma struct "Aluno",
esta struct terá informações como: nome, data de nascimento, duas notas e média e
retorna a média das notas. Em seguida, crie um programa que declare um array de
5 alunos e utilize a função "calcularMedia" para imprimir a média de cada aluno.
Também crie uma função para verificar se um aluno está aprovado ou reprovado
sendo necessário média maior ou igual a 7,0 para aprovação.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define qtdNotas 2
#define qtdAlunos 5

struct dados_aluno
{
    char nome[300];
    char dataNascimento[100];
    float nota[qtdNotas];
    float media;
};

void calcularMedia(struct dados_aluno aluno[])
{
    float soma = 0;
    int i, j;
    for (i = 0; i < qtdAlunos; i++)
    {
        soma = 0;  
        for (j = 0; j < qtdNotas; j++)
        {
            soma += aluno[i].nota[j];
        }
        aluno[i].media = soma / qtdNotas; 
    }
}

void resultado(struct dados_aluno aluno[])
{
    int i;
    for (i = 0; i < qtdAlunos; i++)
    {
        if (aluno[i].media >= 7)
        {
            printf(" %s está -> APROVADO!\n", aluno[i].nome);
        }
        else
        {
            printf("Aluno %s está -> REPROVADO!\n", aluno[i].nome);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int i, j;

    struct dados_aluno aluno[qtdAlunos];
    for (i = 0; i < qtdAlunos; i++)
    {
        printf("\nDigite o nome do %dº aluno:", i + 1);
        fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);
        printf("\nDigite a data de nascimento:");
        fgets(aluno[i].dataNascimento, sizeof(aluno[i].dataNascimento), stdin);
        for (j = 0; j < qtdNotas; j++)
        {
            printf("\nDigite a %dª nota:", j + 1);
            scanf("%f", &aluno[i].nota[j]);
        }
        fflush(stdin);
    }

    calcularMedia(aluno);

    for (i = 0; i < qtdAlunos; i++)
    {
        printf("\nNome: %s", aluno[i].nome);
        printf("\nData de Nascimento: %s", aluno[i].dataNascimento);
        for (j = 0; j < qtdNotas; j++)
        {
            printf("\n %dª Nota: %.2f", j + 1, aluno[i].nota[j]);
        }

        printf("\nMédia: %.2f\n", aluno[i].media);
    resultado(aluno);
    }


    return 0;
}

