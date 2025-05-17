/*
* Projeto: Lista Encadeada Simples
 * Tipo: Estrutura de Dados Linear
 * Arquivo: simple_list.c
 *
 * Descrição:
 * Implementação de uma lista encadeada simples em C, com operações básicas como:
 * inserção no início/fim, remoção, busca e exibição.
 *
 * Paradigma: Imperativo
 * Categoria: Estrutura de Dados Linear
 *
 * Autor: Matheus Cruz (sc-math)
 * Universidade: UFES
 * Disciplina: Estrutura de Dados
 * Data: 17/05/2025
 */

#include "simple_list.h"
#include <stdio.h>
#include <stdlib.h>

struct list {
    Node *head;
    Node *tail;
    int size;
};

// Cria uma lista vazia e retorna o ponteiro para ela
List *createList() {
    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Libera toda a memória da lista, incluindo os nós
void destroyList(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current->next;
        free(current);
        current = temp;
    }
    free(list);
}

// Adiciona um elemento no começo da lista
bool addFirst(List *list, const int value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return false;

    newNode->data = value;
    newNode->next = list->head;

    list->head = newNode;
    if (list->tail == NULL) {
        list->tail = newNode;
    }

    list->size++;

    return true;
}

// Adiciona um elemento no final da lista
bool addLast(List *list, const int value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return false;

    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        list->tail->next = newNode;
    }
    list->tail = newNode;

    list->size++;

    return true;
}

// Insere um elemento numa posição específica da lista
bool addAt(List *list, const int index, const int value) {

    if (index < 0 || index > list->size)
        return false;

    if (index == 0)
        return addFirst(list, value);
    if (index == list->size)
        return addLast(list, value);

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return false;

    newNode->data = value;

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    list->size++;

    return true;
}

// Pega o valor na posição index, retorna false se índice inválido
bool getAt(const List *list, const int index, int *out) {

    if (index < 0 || index >= list->size)
        return false;
    if (index == 0) {
        *out = list->head->data;
        return true;
    }
    if (index == list->size - 1) {
        *out = list->tail->data;
        return true;
    }

    const Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    *out = current->data;
    return true;
}

// Atualiza o valor na posição index, retorna false se índice inválido
bool setAt(const List *list, const int index, const int value) {
    if (index < 0 || index >= list->size)
        return false;
    if (index == 0) {
        list->head->data = value;
        return true;
    }
    if (index == list->size - 1) {
        list->tail->data = value;
        return true;
    }

    Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    current->data = value;
    return true;
}

// Remove o nó na posição index, retorna o valor removido por referência
bool removeAt(List *list, const int index, int *out) {

    if (index < 0 || index >= list->size || list->head == NULL)
        return false;

    Node *toRemove;

    // Remove no início
    if (index == 0) {
        toRemove = list->head;
        *out = toRemove->data;

        list->head = list->head->next;

        if (list->head == NULL)
            list->tail = NULL;

        free(toRemove);
        list->size--;
        return true;
    }

    // Remover fora do início
    Node *prev = list->head;
    for (int i = 0; i < index - 1; i++) {
        prev = prev->next;
    }

    toRemove = prev->next;
    *out = toRemove->data;
    prev->next = toRemove->next;

    if (toRemove->next == list->tail)
        list->tail == prev;

    free(toRemove);
    list->size--;
    return true;
}

// Retorna o número de elementos da lista
int size(const List *list) {
    return list->size;
}

// Retorna true se a lista estiver vazia, false caso contrário
bool isEmpty(const List *list) {
    return list->size == 0;
}

// Retorna o índice do primeiro nó com o valor dado, false se não achar
bool indexOf(const List *list, const int value, int *out) {
    const Node *current = list->head;
    int index = 0;

    while (current != NULL) {
        if (current->data == value){
            *out = index;
            return true;
        }

        current = current->next;
        index++;
    }

    return false;
}

// Remove todos os elementos da lista, deixando-a vazia
void clearList(List *list) {
    Node *current = list->head;
    while (current) {
        Node *tmp = current->next;
        free(current);
        current = tmp;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Imprime todos os elementos da lista.
void printList(const List *list) {
    if (isEmpty(list)){
        printf("Lista vazia\n");
        return;
    }

    printf("Lista: %d", list->head->data);
    const Node *current = list->head->next;
    while (current != NULL) {
        printf(" -> %d", current->data);
        current = current->next;
    }
    printf("\n");
}

int* toArray(const List *list) {
    if (list == NULL || list->size == 0) return NULL;

    int *arr = malloc(sizeof(int) * list->size);
    if (arr == NULL) return NULL;

    const Node *current = list->head;
    for (int i = 0; i < list->size; i++) {
        arr[i] = current->data;
        current = current->next;
    }

    return arr;
}