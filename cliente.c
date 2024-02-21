#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Clientes
{
    char nome[50];
    char endereco[50];
    int codigoCliente;
};


void receberDadosDoArquivo(Cliente **cliente, FILE *arquivo, int *contadorClientes)
{
    char linhasArquivo[100];
    if(fgets(linhasArquivo,sizeof(linhasArquivo),arquivo)==EOF)
    {
        cliente = (Cliente**) malloc(*contadorClientes+1*sizeof(Cliente*));
        receberCliente(cliente[*contadorClientes],arquivo,contadorClientes);
    }else
    {
        receberDados(cliente,arquivo,contadorClientes);
        receberCliente(cliente[(*contadorClientes+1)],arquivo,contadorClientes);
        selectionSort(cliente,contadorClientes);
        imprimirNoArquivo(cliente,arquivo,contadorClientes);
    }
    // contadorClientes contem o numero de linhas que estavam preenchidas/total de clientes -> serve para (free) e para o (for) de (cadastrar cliente)
}

void receberDados(Cliente **cliente,FILE *arquivo,int *contadorClientes){
    char linha[100];
    for (*contadorClientes = 0; fgets(linha, sizeof(linha), arquivo) != NULL; *contadorClientes++)
        {   
            cliente = (Cliente **)realloc(cliente, (*contadorClientes + 1) * sizeof(Cliente *));
            cliente[(*contadorClientes)] = (Cliente *)malloc((*contadorClientes + 1) * sizeof(Cliente));
            fscanf(arquivo, " %[^,],%[^,],%d\n", cliente[(*contadorClientes)]->nome, cliente[(*contadorClientes)]->endereco, &cliente[(*contadorClientes)]->codigoCliente);
        }
}


void receberCliente(Cliente *cliente,FILE *arquivo,int *contadorClientes)
{   
    cliente = (Cliente *)malloc(sizeof(Cliente));
    printf("Insira o seu nome:\n");
    scanf(" %[^\n]s", cliente->nome);
    printf("Insira o seu endereco:\n");
    scanf(" %[^\n]s", cliente->endereco);
    printf("Insira o seu codigo:\n");
    scanf("%d", &cliente->codigoCliente);
    if (*contadorClientes == 0)
    {
    fprintf(arquivo," %s,%s,%d\n", cliente->nome, cliente->endereco, &cliente->codigoCliente);
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
            if (primeiro != i)
            {
                strcpy(nomeTemporario, cliente[i]->nome);
                strcpy(cliente[i]->nome, cliente[j]->nome);
                strcpy(cliente[j]->nome, nomeTemporario);
            }
        }
    }
}


void imprimirNoArquivo(Cliente**cliente,FILE *arquivo ,int *contadorClientes){
    int index=0;
    for(index=0;index<(*contadorClientes);index++){
        fprintf(arquivo,"Nome: %s,Endereco: %s,Codigo do Cliente: %d\n", cliente[index]->nome, cliente[index]->endereco, &cliente[index]->codigoCliente);
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