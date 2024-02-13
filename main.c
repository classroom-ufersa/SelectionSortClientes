#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
int main(){
    FILE *Clientes = fopen("clientes.txt","at");
    if(Clientes == NULL){
        printf("Erro ao abrir o arquivo clientes.txt");
        exit(1);
    }


    fclose(Clientes);
return 0;
}