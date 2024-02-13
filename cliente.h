/*Estrutura de Cliente*/
typedef struct Clientes Cliente;


/*Funcao que cadastra Cliente e retorna um vetor de estrutura Cliente*/
Cliente*cadastrarCliente(Cliente* cliente);


/*Funcao que recebe os dados do arquivo txt*/
void receberDadosDoArquivo(Cliente ** cliente, FILE *arquivo, int *contadorClientes);

/*Funao que ordena os nomes dos clientes pelo metodo slectionSort*/
void selectionSort(Cliente **clientes, int *contadorClientes);