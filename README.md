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
Por sua simplicidade, fácil atribuição e por ser uma técnica bem estabelecida e antiga , não se tem um “criador” definido. Ele funciona ao procurar o menor elemento do vetor (ou maior) e movimentá-lo para a primeira (última) posição do vetor, esse processo vai se repetir para os n elementos do vetor. Ele não altera a ordem dos elementos iguais, sendo uma boa escolha se a estabilidade da ordenação for importante. Pela sua simplicidade ele é uma boa escolha para algoritmos menores que não vão precisar de ordenações muito longas.

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
