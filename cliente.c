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

void escreverNoArquivo(Cliente *cliente,FILE *arquivo)
{   
    cliente = (Cliente *)malloc(sizeof(Cliente));
    printf("Insira o seu nome:\n");
    scanf(" %[^\n]s", cliente->nome);
    printf("Insira o seu endereco:\n");
    scanf(" %[^\n]s", cliente->endereco);
    printf("Insira o seu codigo:\n");
    scanf("%d", &cliente->codigoCliente);
    // qual estrutura?
    fprintf(arquivo,"%s",cliente->nome);
}

void receberDadosDoArquivo(Cliente **cliente, FILE *arquivo, int *contadorClientes)
{
    // carregar dados do arquivo
    char linha[100];
    if(fgets(linha,sizeof(linha),arquivo)==EOF)
    {
        escreverNoArquivo(cliente[*contadorClientes],arquivo);
    }else
    {
        for (*contadorClientes = 0; fgets(linha, sizeof(linha), arquivo) != NULL; *contadorClientes++)
        {   
            cliente = (Cliente **)realloc(cliente, (*contadorClientes + 1) * sizeof(Cliente *));
            cliente[(*contadorClientes)] = (Cliente *)malloc((*contadorClientes + 1) * sizeof(Cliente));
            fscanf(arquivo, " %[^,],%[^,],%d\n", cliente[(*contadorClientes)]->nome, cliente[(*contadorClientes)]->endereco, &cliente[(*contadorClientes)]->codigoCliente);
        }
    }
    // contadorClientes contem o numero de linhas que estavam preenchidas/total de clientes -> serve para (free) e para o (for) de (cadastrar cliente)
}

void selectionSort(Cliente **clientes, int *contadorClientes)
{
    char nomeTemporario[100];
    int i = 0, j = 0;
    int primeiro = 0;
    for (i = 0; i < *contadorClientes + 1; i++)
    {
        primeiro = i;
        for (j = i + 1; j < *contadorClientes; j++)
        {
            if (strcmp(clientes[j]->nome, clientes[primeiro]->nome) < 0)
            {
                primeiro = j;
            }
            if (primeiro != i)
            {
                strcpy(nomeTemporario, clientes[i]->nome);
                strcpy(clientes[i]->nome, clientes[j]->nome);
                strcpy(clientes[j]->nome, nomeTemporario);
            }
        }
    }
}

// quando for receber o novo cliente precisa reallocar contador de clientes + 1 para poder criar um espeço para vetor novo
// cliente=(Cliente**)realloc(cliente,(contadorClientes+1)*sizeof(Cliente*));
// cliente[contadorClientes+1]=cadastrarCliente(cliente[contadorClientes+1]);