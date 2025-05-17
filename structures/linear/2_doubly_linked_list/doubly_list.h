//
// Created by Math on 17/05/2025.
//

#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct list List;

// Cria uma lista vazia e retorna o ponteiro para ela
List *createList();

// Libera toda a memória da lista, incluindo os nós
void destroyList(List *list);

// Adiciona um elemento no começo da lista
bool addFirst(List *list, int value);

// Adiciona um elemento no final da lista
bool addLast(List *list, int value);

// Insere um elemento numa posição específica da lista
bool addAt(List *list, int index, int value);

// Pega o valor na posição index, retorna false se índice inválido
bool getAt(const List *list, int index, int *out);

// Atualiza o valor na posição index, retorna false se índice inválido
bool setAt(const List *list, int index, int value);

// Remove o nó na posição index, retorna o valor removido por referência
bool removeAt(List *list, int index, int *out);

// Retorna o número de elementos da lista
int size(const List *list);

// Retorna true se a lista estiver vazia, false caso contrário
bool isEmpty(const List *list);

// Retorna o índice do primeiro nó com o valor dado, false se não achar
bool indexOf(const List *list, int value, int *out);

// Remove todos os elementos da lista, deixando-a vazia
void clearList(List *list);

// Imprime todos os elementos da lista.
void printList(const List *list);

// Converte a Lista num Vetor
int* toArray(const List *list);

#endif //DOUBLY_LIST_H
