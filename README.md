# Finalidade do Projeto
O objetivo de tal projeto é demonstrar um exemplo de implementação do algoritmo de ordenação SelectionSort em C, utilizando variáveis do tipo string. 
# Contribuidores do Projeto
O trabalho foi feito por 4 alunos matriculados no curso de Tecnologia da Informação da Universidade Federal Rural do Semi-Árido (UFERSA), cujos nomes são:

- Leandro Carlos Martins de Carvalho, 

- Allyson da Silva Felix, 

- Samuel Iago de Farias Cabral 

- Erik Thadeu Sales Praxedes.
# Requesitos
O código deve conter um tipo estruturado Clientes com os atributos básicos: nome, endereço e código do cliente, assim como um arquivo.txt em que será
armazenados os dados da struct em ordem alfabetica. O programa deve atualizar o arquivo com os dados novos toda vez que for executado novamente, os quais
serão inseridos também na ordem supracitada.
# O que é a SelectionSort?
Selection Sort é um algoritmo de ordenação extremamente simples que atua num vetor e fica ordenando ele do menor para o maior, parando apenas quando tudo estiver ordenado.
Por sua simplicidade, fácil atribuição e por ser uma técnica bem estabelecida e antiga , não se tem um “criador” definido. Ele funciona ao procurar o menor elemento do vetor (ou maior) e movimentá-lo para a primeira (última) posição do vetor, esse processo vai se repetir para os n elementos do vetor.

A seguir está um exemplo que o grupo criou de uso da SelectionSort considerando os requisitos dados:
```c
void selectionSortClientes(Cliente *clientes, int numClientes) {
    for (int i = 0; i < numClientes - 1; i++) { 
        int min_index = i; 
        for (int j = i + 1; j < numClientes; j++) {
            if (strcmp(clientes[j].nome, clientes[min_index].nome) < 0) { 
                min_index = j; 
            }
        }
        if (min_index != i) { 
            Cliente temp = clientes[i]; 
            clientes[i] = clientes[min_index]; 
            clientes[min_index] = temp; 
        }
    } 
```
## Parâmetros
 - Cliente *clientes: vetor de ponteiros que armazena os dados do cliente
 - numClientes: variável do tipo inteiro que recebe o valor correspondente ao total de clientes cadastrados
## Funcionamento
### Inicialização dos iteradores
Inicia-se um loop externo com o iterador i variando de 0 até numClientes - 1. Este loop percorre o array de clientes, considerando cada elemento como um ponto de partida para encontrar o menor elemento subsequente.
### Seleção do menor elemento
Para cada posição i, é definido min_index como i, indicando que o elemento atual é o menor conhecido até o momento.
Inicia-se um loop interno com o iterador j variando de i + 1 até numClientes - 1. Este loop busca pelo menor elemento a partir da posição atual i.
Se o nome do cliente na posição j for lexicograficamente menor do que o nome do cliente na posição min_index, atualiza-se min_index para j, indicando que encontramos um novo menor elemento.
### Troca de elementos 
Após completar o loop interno, se min_index for diferente de i, isso significa que encontramos um elemento menor do que o atual na posição i. Nesse caso, efetua-se a troca de elementos da seguinte forma: uma variável de troca é declarada (temp), na qual serão armazenados os dados do cliente na posição i. A partir daí, os dados do cliente do índice min_index são transferidos para a posição i. No final, a variável de troca com os dados do cliente[i] são colocados na posição de onde ficava antes o menor elemento. 
### Repetição
Esse processo continua até que todos os elementos tenham sido percorridos e colocados em suas posições corretas. Cada iteração do loop externo coloca o menor elemento restante na posição correta, à esquerda dos elementos já ordenados.

## Vantagens
 - Estabilidade: ele não altera a ordem dos elementos iguais, sendo uma boa escolha se a estabilidade da ordenação for importante.
 - Dados pequenos: Pela sua simplicidade ele é uma boa escolha para algoritmos menores que não vão precisar de ordenações muito longas.
## Desvantagens
 - Complexidade de tempo quadrática: seu desempenho piora rapidamente com o aumento do tamanho do array. Para arrays grandes, o tempo de execução pode se tornar impraticável.
 - Desempenho independente da entrada:  Mesmo que o array já esteja parcialmente ordenado ou totalmente ordenado, o algoritmo continua a realizar o mesmo número de comparações e trocas, o que é ineficiente.
# Análise de Complexidade de tempo
O algoritmo de ordenação SelectionSort funciona a partir de dois loops: um externo e um interno, conforme mostrado no exemplo acima. O loop externo percorre o array de clientes de 0 a numClientes - 1. Isso requer n - 1 iterações, onde n é igual ao número de cliente. Dentro do loop externo, há um loop interno que percorre o array de clientes de i + 1 até numClientes, o que requer também n - 1 iterações. Todas as outras operações dentro dos loops possuem complexidade constante, ou seja, O(1). 
```c
void selectionSortClientes(Cliente *clientes, int numClientes) {
    for (int i = 0; i < numClientes - 1; i++) { // O(n-1)
        int min_index = i; // O(1)
        for (int j = i + 1; j < numClientes; j++) { // O(n-1)
            if (strcmp(clientes[j].nome, clientes[min_index].nome) < 0) { // O(1) 
                min_index = j; // O(1)
            }
        }
        if (min_index != i) { // O(1)
            Cliente temp = clientes[i]; // O(1) 
            clientes[i] = clientes[min_index]; // O(1) 
            clientes[min_index] = temp; // O(1) 
        }
    } 
```
Dessa forma, podemos desconsiderar as complexidades constantes para fins de simplificação e apenas levar em conta as dos loops. Portanto, o número total de iterações é 
(n−1)×(n−1), o que simplifica para n^2 - 2n + 1. No entanto, em termos de complexidade assintótica, o termo dominante é n^2. Desse modo, a complexidade do SelecionSort será O(n^2). 
# Análise de Complexidade de espaço
A complexidade de espaço do algoritmo Selection Sort é O(1), o que significa que o espaço adicional necessário para executar o algoritmo é constante e independente do tamanho do array de entrada. Isso ocorre porque o algoritmo Selection Sort opera no próprio array de entrada, realizando apenas trocas de elementos dentro desse array, sem exigir estruturas de dados adicionais proporcionais ao tamanho do array. 

Mesmo que o algoritmo use algumas variáveis ​​adicionais, como os índices i, j e min_index, bem como uma variável temporária temp para a troca de elementos, o número dessas variáveis ​​permanece constante, independentemente do tamanho do array. Portanto, a quantidade de memória adicional necessária não aumenta conforme o tamanho do array cresce. Em resumo, a complexidade de espaço do Selection Sort é constante e não depende do tamanho do array de entrada, sendo O(1). Isso o torna eficiente em termos de espaço, especialmente para grandes conjuntos de dados.





