#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define tam 3

void imprime_cabecalho()
{
   
    printf("================================\n");
    printf("     SENAI - DENDEZEIROS\n");
    printf("================================\n");
    
}


struct contatos {
    char nome[300];
    char tel[300];
    char email[300];
};

void nomeConfirm (struct contatos dados[], char* nome){

int i;

    for(i=0;i< tam; i++)
    {
        if (strcmp(nome, dados[i].nome)==0){
        	printf("\nNome: %s",nome, dados[i].nome );
        	printf("\nTelefone: %s", dados[i].tel );
        	
              break;
        }else{
        	printf("Contato não encontrado...");
        	
		}

    }

    return ;
}

int main (){
setlocale(LC_ALL,"");
char nome[300];
int i;

struct contatos dados[tam];
for ( i = 0; i < tam; i++)
{
    printf("Digite o nome:");
    gets(dados[i].nome);
    
    printf("Digite o tel:");
    gets(dados[i].tel);

    printf("Digite o email:");
    gets(dados[i].email);
    
    system("cls || clear");
    printf("Contato Salvo...\n");
}

printf("Buscar contato:");
gets(nome);

nomeConfirm(dados, nome);



return 0;

}

