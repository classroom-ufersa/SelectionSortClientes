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