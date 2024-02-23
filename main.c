#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
int main(){
    FILE *arquivo = fopen("clientes.txt","a+");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo clientes.txt");
        exit(1);
    }
    Cliente**cliente = NULL;
    int contadorCliente=0;
    int *pontContadorCliente=&contadorCliente;
    receberDadosDoArquivo(cliente, arquivo, pontContadorCliente);
    liberarMemoria(cliente, *pontContadorCliente);
    fclose(arquivo);
return 0;
}