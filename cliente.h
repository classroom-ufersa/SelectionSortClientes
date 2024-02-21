/*Estrutura de Cliente*/
typedef struct Clientes Cliente;


/*Função que cadastra cliente quando o arquivo estiver vazio!*/
void escreverNoArquivo(Cliente *cliente,FILE *arquivo,int *contadorClientes);


/*Funcao que recebe os dados do arquivo txt*/
void receberDadosDoArquivo(Cliente ** cliente, FILE *arquivo, int *contadorClientes);

/*Fucao que ordena os nomes dos clientes pelo metodo slectionSort*/
void selectionSort(Cliente **clientes, int *contadorClientes);