#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void funcaoPrincipal(Cliente ** cliente,int *contadorCliente, FILE *arquivo){
    if(verificarArquivo(arquivo)==0){ //acontece normal (sem nada no arquivo)
        (*contadorCliente)++; // 1 cliente
        cliente = realloc(cliente, (*contadorCliente) * sizeof(Cliente *));
        if (cliente == NULL)
        {
            printf("Erro\n");
            exit(1);
        }   
        cliente[(*contadorCliente) - 1] = (Cliente *)malloc(sizeof(Cliente));
        if (cliente[(*contadorCliente) - 1] == NULL)
        {
            printf("Erro\n");
            exit(1);
        }   
        cliente[(*contadorCliente) - 1] = receberCliente(cliente[(*contadorCliente) - 1]);
        /* COLOCAR AQUI : Funcao para liberar memoria*/

    }else{ // tiver linha preenchida
        (*contadorCliente)++; // aloca pela quantidade de clientes /quant de linhas com caracteres
        cliente = (Cliente **)realloc(cliente,(*contadorCliente)*sizeof(Cliente*));
        if (cliente == NULL)
        {
            printf("Erro\n");
            exit(1);
        }   
        cliente[0] = receberCliente(cliente[0]); // no primeiro espaco ficara o cliente a ser cadastrado
        cliente=alocandoClientes(cliente,contadorCliente); // aloco o espaco necessario para cada cliente para quando for pegar apenas precisar salvar
        /* COLOCAR AQUI : Funcao para pegar os dados do arquivo e jogar na estrutura , Funcao para liberar memoria, Funcao para imprimir no arquivo, Funcao do SelectionSort*/
    }
}

Cliente *receberCliente(Cliente * cliente)
{   
    cliente = (Cliente *)malloc(sizeof(Cliente));
    printf("Insira o seu nome:\n");
    scanf(" %[^\n]s", cliente->nome);
    printf("Insira o seu endereco:\n");
    scanf(" %[^\n]s", cliente->endereco);
    printf("Insira o seu codigo:\n");
    scanf("%d", &cliente->codigoCliente);
    return cliente;
}

int verificarArquivo(FILE *arquivo) 
{
    fseek(arquivo, 0, SEEK_SET);
    char linhas[120];
    int quantidadeClientes = 0;
    while (fgets(linhas, 120, arquivo) != NULL)
    {
        quantidadeClientes++;
    }
    return quantidadeClientes;
}


void ordenarClientes(FILE *arquivo) {
    rewind(arquivo);
    int numClientes = verificarArquivo(arquivo);
    Cliente *clientes = (Cliente *)malloc((numClientes + 1) * sizeof(Cliente)); // Alocando memória para mais um cliente

    // Lendo clientes do arquivo e armazenando no array
    for (int i = 0; i < numClientes; i++) {
        fscanf(arquivo, "%[^;];%[^;];%d\n", clientes[i].nome, clientes[i].endereco, &clientes[i].codigoCliente);
    }

    // Recebendo novo cliente e adicionando ao final do array
    clientes[numClientes] = *receberCliente();
    numClientes++; // Incrementando o número de clientes

    // Selection Sort para ordenar os clientes
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

    // Fechar o arquivo para reabri-lo em modo de escrita
    fclose(arquivo);
    arquivo = fopen("clientes.txt", "w");

    // Escrever os clientes ordenados de volta no arquivo
    for (int i = 0; i < numClientes; i++) {
        fprintf(arquivo, "%s;%s;%d\n", clientes[i].nome, clientes[i].endereco, clientes[i].codigoCliente);
    }

    fclose(arquivo);
    free(clientes); // Liberar memória alocada dinamicamente
}

void liberarMemoria(Cliente **cliente, int contadorClientes){
    int index = 0;
    for (index = 0; index < contadorClientes; index++)
    {
        free(cliente[index]);
    }
    free(cliente);
    
}

// quando for receber o novo cliente precisa reallocar contador de clientes + 1 para poder criar um espeço para vetor novo
// cliente=(Cliente**)realloc(cliente,(contadorClientes+1)*sizeof(Cliente*));
// cliente[contadorClientes+1]=cadastrarCliente(cliente[contadorClientes+1]);