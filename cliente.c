#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Para acessar a função clock() e calcular o tempo de execução de determinado código

void funcaoPrincipal(){
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    ordenarClientes(arquivo);
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


void selectionSortClientes(Cliente *clientes, int numClientes) {
   clock_t tempo0 = clock(); // c1, 1 vez
    for (int i = 0; i < numClientes - 1; i++) { // c2, N-1 vezes, considerando N = numClientes
        int min_index = i; // c3, N-1 vez
        for (int j = i + 1; j < numClientes; j++) { // c4, (N-1)^2 vezes
            if (strcmp(clientes[j].nome, clientes[min_index].nome) < 0) { //c5, (N-1)^2 vezes
                min_index = j; //c6, (N-1)^2 vezes
            }
        }
        if (min_index != i) { // c7, (N-1) vezes
            Cliente temp = clientes[i]; // c8, (N-1) vezes
            clientes[i] = clientes[min_index]; // c9, (N-1) vezes
            clientes[min_index] = temp; // c10, (N-1) vezes
        }
    } 
    double tempo1 = (double)(clock() - tempo0) / CLOCKS_PER_SEC; // c11, 1 vez
    printf("\nTempo de ordenacao: %f milissegundos\n", tempo1); // c12, 1 vez
    
    /*a variável tempo0 é serve para iniciar a contagem do tempo de execução do algoritmo, por isso se encontra
    acima do código. Assim que o algoritmo for executado, a variável tempo1 vai armazenar o tempo que deu para 
    executar esse código a partir da subtração entre o tempo inicial e tempo final.*/

    /*
    Análise da complexidade do SelectionSort
        No pior caso: 
        
        T = c1 + c11 + c12 + (c2 + c3 + c7 + c8 + c9 + c10)(N-1) + (c4 + c5 + c6)(N-1)^2
        
        Substituindo as somas por variáveis aleatórias:
        
        T = c1 + c11 + c12 + a(N-1) + b(N-1)^2
        T = aN - a + bN^2 - 2bN + b + c1 + c11 + c12
        
        Simplificando a expressão, eliminando os termos constantes:
        
        T = N + N^2 - N
        T = N^2
        
        Dessa forma, conclui-se que, no pior dos casos, o tempo de execução do programa vai aumentar na pro 
        porção de N^2. Em outros casos, o resultado não mudaria, pois os loops iriam se repetir a mesma 
        quantidade de vezes, mesmo que os nomes já estejam todos ordenados. Portanto, a complexidade geral
        desse algoritmo sempre será N^2.
        */
}

void ordenarClientes(FILE *arquivo) 
{
    rewind(arquivo);
    int numClientes = verificarArquivo(arquivo);
    Cliente *clientes = (Cliente *)malloc((numClientes + 1) * sizeof(Cliente)); // Alocando memória para mais um cliente

    // Lendo clientes do arquivo e armazenando no array
    for (int i = 0; i < numClientes; i++) {
        fscanf(arquivo, "%[^;];%[^;];%d\n", clientes[i].nome, clientes[i].endereco, &clientes[i].codigoCliente);
    }

    // Recebendo novo cliente e adicionando ao final do array
    clientes[numClientes] = *receberCliente(clientes);
    numClientes++; // Incrementando o número de clientes

    // Ordenar os clientes
    selectionSortClientes(clientes, numClientes);

    // Fechar o arquivo para reabri-lo em modo de escrita
    fclose(arquivo);
    arquivo = fopen("clientes.txt", "w");

    // Escrever os clientes ordenados de volta no arquivo
    for (int i = 0; i < numClientes; i++) {
        fprintf(arquivo, "%s;%s;%d\n", clientes[i].nome, clientes[i].endereco, clientes[i].codigoCliente);
    }

    fclose(arquivo);
    liberarMemoria(clientes, numClientes);
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