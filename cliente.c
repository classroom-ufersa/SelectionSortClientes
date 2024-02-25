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
    printf("Insira o seu codigo:\n");
    scanf("%d", &cliente->codigoCliente);
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


