# SelectionSortClientes
O objetivo de tal projeto é demonstrar um exemplo de implementação do algoritmo de ordenação SelectionSort em C, utilizando variáveis do tipo string.
O código deve conter um tipo estruturado Clientes com os atributos básicos: nome, endereço e código do cliente, assim como um arquivo.txt em que será
armazenados os dados da struct em ordem alfabetica. O programa deve atualizar o arquivo com os dados novos toda vez que for executado novamente, os quais
serão inseridos também na ordem supracitada. 

O trabalho foi feito por 4 alunos matriculados no curso de Tecnologia da Informação da Universidade Federal Rural do Semi-Árido (UFERSA), cujos nomes são:
Leandro Carlos Martins de Carvalho, Allyson da Silva Felix, Samuel Iago de Farias Cabral e Erik Thadeu Sales Praxedes.
# Algoritmo Implementado
SelectionSort: esse algoritmo encontra o menor elemento de um array e o coloca na posição desejada, repetindo esse mesmo processo para todos os elementos restantes. 
Sua complexidade em relação ao tempo é O(n^2) nos piores, médios e melhores casos, já na complexidade em relação ao espaço é O(1) pois não há criação de variavel apenas manipulação de variaveis com vetor já existente.

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

