#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void funcaoPrincipal(){
    FILE *arquivo = fopen("clientes.txt", "a+");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    int numclientes = verificarArquivo(arquivo);
    ordenarClientes(arquivo, numclientes);
}

Cliente *receberCliente()
{   
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
    if (cliente == NULL) {
        printf("Erro ao alocar memória para o cliente.\n");
        exit(EXIT_FAILURE);
    }
    printf("Insira o seu nome:\n");
    scanf(" %[^\n]s", cliente->nome);
    printf("Insira o seu endereco:\n");
    scanf(" %[^\n]s", cliente->endereco);
    int verificacaoInteiro=0;
    do{
        printf("Insira o seu codigo:\n");
        verificacaoInteiro=scanf("%d", &cliente->codigoCliente);
        if(verificacaoInteiro!=1){
            printf("\nDigite novamente o codigo do cliente\n");
            cliente->codigoCliente=0;
            while(getchar()!='\n');
        }
    }while(verificacaoInteiro!=1);
    return cliente;
}

int verificarArquivo(FILE *arquivo) 
{
    rewind(arquivo);
    char linhas[1000];
    int quantidadeClientes = 0;
    while (fgets(linhas, sizeof(linhas), arquivo) != NULL)
    {
        quantidadeClientes++;
    }
    rewind(arquivo);
    return quantidadeClientes;
}

void selectionSortClientes(Cliente *clientes, int numClientes) {
    clock_t tempo0 = clock();
    for (int i = 0; i < numClientes - 1; i++) { 
        int min_index = i; 
        for (int j = i + 1; j < numClientes; j++) { 
            if (strcmp(clientes[j].nome, clientes[min_index].nome) < 0) { 
                min_index = j; 
            }
        }
        if (min_index != i) { 
            Cliente temp = clientes[i]; 
            clientes[i] = clientes[min_index]; 
            clientes[min_index] = temp; 
        }
    }

    double tempo1 = (double)(clock() - tempo0) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %f milissegundos\n", tempo1); 
}

void ordenarClientes(FILE *arquivo, int numClientes) 
{
    Cliente *clientes = (Cliente *)malloc((numClientes + 1) * sizeof(Cliente)); 
    if (clientes == NULL) {
        printf("Erro ao alocar memória para clientes.\n");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    while (fscanf(arquivo, "%[^;];%[^;];%d\n", clientes[j].nome, clientes[j].endereco, &clientes[j].codigoCliente) == 3) {
        j++;
    }

    clientes[j] = *receberCliente(); 
    j++;

    selectionSortClientes(clientes, j);

    fclose(arquivo);
    arquivo = fopen("clientes.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < j; i++) {
        fprintf(arquivo, "%s;%s;%d\n", clientes[i].nome, clientes[i].endereco, clientes[i].codigoCliente);
    }

    fclose(arquivo);
    free(clientes);
}


