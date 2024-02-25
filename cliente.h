#include <stdio.h>

/*Estrutura de Cliente*/
typedef struct Clientes Cliente;

struct Clientes
{
    char nome[50];
    char endereco[50];
    int codigoCliente;
};



/*Funcao que centraliza outras funcoes colocando condicao de arquivo vazio ou ocupado e gerenciando*/
void funcaoPrincipal(Cliente ** cliente,int *contadorCliente, FILE *arquivo);

/*Funcao que aloca memoria para gerar espaco na memoria para a quantidade de clientes existentes no arquivo no momento em que o arquivo foi executado e retorna a estrutura*/
Cliente * alocandoClientes(Cliente ** cliente,int *contadorCliente);

/*Funcao que aloca a posicao,cadastra cliente e retorna a estrutura */
Cliente * receberCliente(Cliente*cliente);

/*Funcao que verifica a quantidade de linhas ocupadas retornando o valor em inteiro*/
int verificarArquivo(FILE *arquivo);

// ACIMA: nova logica   ABAIXO: logica antiga    -> esta ai para ser reaproveitada e analisada ao criar as novas funcoes



/*Função que coloca os dados do arquivo em uma estrutura*/
void receberDados(Cliente **cliente,FILE* arquivo,int *contadorClientes);

/*
/*Funcao que recebe os dados do arquivo txt
void receberDadosDoArquivo(Cliente **cliente, FILE* arquivo, int *contadorClientes);
*/

/*Fucao que ordena os nomes dos clientes pelo metodo slectionSort*/
void ordenarClientes(FILE *arquivo);

/*Imprime os dados dos clientes presentes no arquivo txt*/
void imprimirNoArquivo(Cliente**cliente,FILE* arquivo ,int *contadorClientes);

/*Libea memória do vetor de ponteiros cliente*/
void liberarMemoria(Cliente **cliente, int contadorClientes);

/*Faz a comparação entre dois nomes de clientes, retorna 0 caso sejam iguais e caso diferente retorna um valor diferente de zero*/
int compareClientes(const void *a, const void *b);
