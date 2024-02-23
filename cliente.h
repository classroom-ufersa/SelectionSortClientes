struct Clientes
{
    char nome[50];
    char endereco[50];
    int codigoCliente;
};

/*Estrutura de Cliente*/
typedef struct Clientes Cliente;


/*Função que cadastra cliente quando o arquivo estiver vazio!*/
void receberCliente(Cliente *cliente,FILE* arquivo,int *contadorClientes);

/*Função que coloca os dados do arquivo em uma estrutura*/
void receberDados(Cliente **cliente,FILE* arquivo,int *contadorClientes);

/*Funcao que recebe os dados do arquivo txt*/
void receberDadosDoArquivo(Cliente ** cliente,FILE* arquivo, int *contadorClientes);

/*Fucao que ordena os nomes dos clientes pelo metodo slectionSort*/
void selectionSort(Cliente **clientes, int *contadorClientes);

/*Imprime os dados dos clientes presentes no arquivo txt*/
void imprimirNoArquivo(Cliente**cliente,FILE* arquivo ,int *contadorClientes);

/*Libea memória do vetor de ponteiros cliente*/
void liberarMemoria(Cliente **cliente, int contadorClientes);

