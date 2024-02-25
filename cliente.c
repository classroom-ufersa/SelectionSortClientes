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

Cliente * alocandoClientes(Cliente ** cliente,int *contadorCliente){   
    int index=0;
    for (index = 1; index < (*contadorCliente); index++) 
    {// a partir do 1 pois o [0] ja foi alocado 
        cliente[index] = (Cliente*)malloc(sizeof(Cliente));
        if (cliente[index] == NULL)
        {
            printf("Erro\n");
            exit(1);
        }   
    }
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

// realizado de acordo com a nossa discussao e analise ate aqui, a baixo esta a nossa logica anterior


/* Criei com essa logica anterior a outra funcao que centraliza as funcoes

void receberDadosDoArquivo(Cliente **cliente, FILE* arquivo, int *contadorClientes) 
{
    char* linhasArquivo = NULL;
    size_t* tamanho = 0;
    if(getline(&linhasArquivo, tamanho, arquivo) == -1)
    {
        cliente = (Cliente**) malloc(*contadorClientes+1*sizeof(Cliente*));
        receberCliente(cliente[*contadorClientes],arquivo,contadorClientes);
    }else
    {
        receberDados(cliente,arquivo,contadorClientes);
        receberCliente(cliente[(*contadorClientes+1)],arquivo,contadorClientes);
        selectionSort(cliente,contadorClientes);
    }
    // contadorClientes contem o numero de linhas que estavam preenchidas/total de clientes -> serve para (free) e para o (for) de (cadastrar cliente)
}
*/

void receberDados(Cliente **cliente,FILE* arquivo,int *contadorClientes){
    char* linhasArquivo = NULL;
    size_t* tamanho = 0;
    if (getline(&linhasArquivo, tamanho, arquivo) != -1)
        {   
            cliente = (Cliente **)realloc(cliente, (*contadorClientes + 1) * sizeof(Cliente *));
            cliente[(*contadorClientes)] = (Cliente *)malloc((*contadorClientes + 1) * sizeof(Cliente));
            fscanf(arquivo, " %[^,],%[^,],%d\n", cliente[(*contadorClientes)]->nome, cliente[(*contadorClientes)]->endereco, &cliente[(*contadorClientes)]->codigoCliente);
        }
}




void selectionSort(Cliente **cliente, int *contadorClientes)
{
    char nomeTemporario[100];
    int i = 0, j = 0;
    int primeiro = 0;
    for (i = 0; i < *contadorClientes + 1; i++)
    {
        primeiro = i;
        for (j = i + 1; j < *contadorClientes; j++)
        {
            if (strcmp(cliente[j]->nome, cliente[primeiro]->nome) < 0)
            {
                primeiro = j;
            }
        }
        if (primeiro != i)
        {
            strcpy(nomeTemporario, cliente[i]->nome);
            strcpy(cliente[i]->nome, cliente[primeiro]->nome);
            strcpy(cliente[primeiro]->nome, nomeTemporario);
        }
    }
}



void imprimirNoArquivo(Cliente**cliente,FILE* arquivo ,int *contadorClientes){
    int index=0;
    for(index=0;index<(*contadorClientes);index++){
        fprintf(arquivo,"Nome: %s,Endereco: %s,Codigo do Cliente: %d\n", cliente[index]->nome, cliente[index]->endereco, cliente[index]->codigoCliente);
    }
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