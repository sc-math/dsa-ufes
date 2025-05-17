/*
* Arquivo: main.c
 * Descrição:
 * Arquivo de testes para a estrutura de lista encadeada simples.
 * Aqui são testadas inserções, remoções, buscas e impressões da lista.
 */

#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

int main() {
    List *list = createList();

    printf("Adicionando elementos...\n");
    addFirst(list, 10);
    addLast(list, 20);
    addAt(list, 1, 15);
    printList(list); // >> Lista: 10 -> 15 -> 20

    int value;
    printf("\nPegando valor no indice 1:\n");
    if (getAt(list, 1, &value)) {
        printf("Valor em index 1: %d\n", value); // >> 15
    }

    printf("\nAtualizando valor no indice 1 pra 99...\n");
    setAt(list, 1, 99);
    printList(list);  // >> Lista: 10 -> 99 -> 20

    printf("\nRemovendo valor no indice 0:\n");
    if (removeAt(list, 0, &value)) {
        printf("Valor removido: %d\n", value);
    }
    printList(list); // >> Lista: 99 -> 20

    printf("\nTamanho da lista: %d\n", size(list)); // >> 2
    printf("Lista esta vazia? %s\n", isEmpty(list) ? "Sim" : "Nao"); // False

    printf("\nBuscando indice do valor 99:\n");
    if (indexOf(list, 99, &value)) {
        printf("Valor 99 encontrado no indice: %d\n", value); // >> 0
    } else {
        printf("Valor 99 nao encontrado\n");
    }

    printf("\nConvertendo pra array...\n");
    int *arr = toArray(list);
    for (int i = 0; i < size(list); i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);

    printf("\nLimpando lista...\n");
    clearList(list);
    printList(list); // >> Lista vazia

    destroyList(list);
    return 0;
}