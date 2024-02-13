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

Cliente *cadastrarCliente(Cliente* cliente){
    cliente = (Cliente*) malloc (sizeof(Cliente));
    printf("Insira o seu nome:\n");
    scanf(" %[^\n]s",cliente->nome);
    printf("Insira o seu endereco:\n");
    scanf(" %[^\n]s",cliente->endereco);
    printf("Insira o seu codigo:\n");
    scanf("%d",&cliente->codigoCliente);
    return cliente;
}

void receberDadosDoArquivo(Cliente ** cliente){
// carregar dados do arquivo
    int contadorClientes=0;
    char linha[100];
    for(contadorClientes=0;fgets(linha,sizeof(linha),"clientes.txt")!=NULL;contadorClientes++){
        cliente=(Cliente**)realloc(cliente,(contadorClientes+1)*sizeof(Cliente*));
        cliente[contadorClientes]=(Cliente*)malloc((contadorClientes+1)*sizeof(Cliente));
        fscanf("clientes.txt"," %50[^,],%50[^,],%d\n", cliente[contadorClientes]->nome, cliente[contadorClientes]->endereco, &cliente[contadorClientes]->codigoCliente);
    }
// contadorClientes contem o numero de linhas que estavam preenchidas/total de clientes -> serve para (free) e para o (for) de (cadastrar cliente) 
}


// quando for receber o novo cliente precisa reallocar contador de clientes + 1 para poder criar um espeço para vetor novo
// cliente=(Cliente**)realloc(cliente,(contadorClientes+1)*sizeof(Cliente*));
// cliente[contadorClientes+1]=cadastrarCliente(cliente[contadorClientes+1]);
