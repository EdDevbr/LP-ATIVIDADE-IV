#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Produto {
    char nome[100];
    float preco;
    int quantidade;
};

void adicionarProduto(struct Produto *produtos, int *quantidadeProdutos) {
    printf("Digite o nome do produto: ");
    scanf("%s", produtos[*quantidadeProdutos].nome);
    printf("Digite o preço do produto: ");
    scanf("%f", &produtos[*quantidadeProdutos].preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produtos[*quantidadeProdutos].quantidade);
    
    (*quantidadeProdutos)++;
    
    printf("Produto adicionado com sucesso!\n");
}

void realizarCompra(struct Produto *produtos, int quantidadeProdutos) {
    char nomeProduto[100];
    int quantidadeComprada;
    int i;
    float totalCompra

    printf("Digite o nome do produto que deseja comprar: ");
    scanf("%s", nomeProduto);

    for (i = 0; i < quantidadeProdutos; i++) {
        if (strcmp(nomeProduto, produtos[i].nome) == 0) {
            printf("Digite a quantidade que deseja comprar: ");
            scanf("%d", &quantidadeComprada);

            if (quantidadeComprada <= produtos[i].quantidade && quantidadeComprada > 0) {
                totalCompra = quantidadeComprada * produtos[i].preco;
                printf("Compra realizada com sucesso. Total: R$ %.2f\n", totalCompra);
                produtos[i].quantidade -= quantidadeComprada;
            } else {
                printf("Quantidade indisponível em estoque ou inválida.\n");
            }
            return;
        }
    }

    printf("Produto não encontrado.\n");
}

void consultarEstoque(struct Produto *produtos, int quantidadeProdutos) {
    int i;

    printf("Estoque:\n");

    for (i = 0; i < quantidadeProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preço: R$ %.2f\n", produtos[i].preco);
        printf("Quantidade em estoque: %d\n", produtos[i].quantidade);
        printf("Valor total em estoque: R$ %.2f\n", produtos[i].preco * produtos[i].quantidade);
        printf("\n");
    }
}

int main() {
    struct Produto produtos[100]; 
    int quantidadeProdutos = 0;
    int opcao;

    do {
        printf("\n=== SISTEMA ===\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Realizar uma compra\n");
        printf("3 - Consultar estoque\n");
        printf("4 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(produtos, &quantidadeProdutos);
                break;
            case 2:
                realizarCompra(produtos, quantidadeProdutos);
                break;
            case 3:
                consultarEstoque(produtos, quantidadeProdutos);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
