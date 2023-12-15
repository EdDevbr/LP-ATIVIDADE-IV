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
#define qtdAlunos 2

struct dados_aluno
{
    char nome[300];
    char dataNascimento[100];
    float nota[qtdNotas];
    float media;
};

float calcularMedia(struct dados_aluno *aluno)
{
    float media=0, soma = 0;
    int i, j;
    for (i = 0; i < qtdAlunos; i++)
    {
        for (j = 0; j < qtdNotas; j++)
        {
            soma += aluno[i].nota[j];
        }
       

    media = soma / qtdNotas;
    soma=0;
    }
    return media;
    
    
}

char *resultado(struct dados_aluno *aluno)
{

    char result[300];
    int i;
    for (i = 0; i < qtdAlunos; i++)
    {
        if (aluno[i].media >= 7)
        {
            strcpy(result, "ALUNO APROVADO!");
        }
        else
        {
            strcpy(result, "ALUNO REPROVADO!");
        }
    }

    return result;
}

int main()
{
    setlocale(LC_ALL, "");
    int i, j;

    struct dados_aluno aluno[qtdAlunos];
    for (i = 0; i < qtdAlunos; i++)
    {
        printf("\nDigite o nome do %dº aluno:", i + 1);
        gets(aluno[i].nome);
        printf("\nDigite a data de nascimento:");
        gets(aluno[i].dataNascimento);
        for (j = 0; j < qtdNotas; j++)
        {
            printf("\nDigite a %dª nota:", j + 1);
            scanf("%f", &aluno[i].nota[j]);
        }
        fflush(stdin);
    }

    for (i = 0; i < qtdAlunos; i++)

    {
        aluno[i].media=calcularMedia(aluno);
        printf("\nNome: %s", aluno[i].nome);
        printf("\nData de Nascimento: %s", aluno[i].dataNascimento);
        for (j = 0; j < qtdNotas; j++)
        {
            printf("\n %dª Nota: %.2f", j + 1, aluno[i].nota[j]);
        }

        printf("\nMédia: %.2f", calcularMedia(aluno));
        printf("\n%s", resultado(aluno));
    }

    return 0;
}
