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
void funcaoPrincipal();

/*Funcao que aloca a posicao,cadastra cliente e retorna a estrutura */
Cliente *receberCliente();

/*Funcao que verifica a quantidade de linhas ocupadas retornando o valor em inteiro*/
int verificarArquivo(FILE *arquivo);

/*Fucao que ordena os nomes dos clientes pelo metodo slectionSort*/
void ordenarClientes(FILE *arquivo, int numClientes) ;

/*Função selection sort*/
void selectionSortClientes(Cliente *clientes, int numClientes);



