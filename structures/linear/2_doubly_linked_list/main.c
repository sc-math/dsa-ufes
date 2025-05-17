/*
 * Arquivo: main.c
 * Descrição:
 * Arquivo de testes para a estrutura de lista duplamente encadeada.
 * Aqui são testadas inserções, remoções, buscas e impressões da lista.
 */

#include "doubly_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    List *list = createList();
    if (!list) {
        printf("Erro ao criar lista\n");
        return 1;
    }

    printf("Adicionando elementos no comeco: 10, 20, 30\n");
    addFirst(list, 10);
    addFirst(list, 20);
    addFirst(list, 30);
    printList(list); // Esperado: 30 <-> 20 <-> 10

    printf("\nAdicionando elementos no fim: 40, 50\n");
    addLast(list, 40);
    addLast(list, 50);
    printList(list); // Esperado: 30 <-> 20 <-> 10 <-> 40 <-> 50

    printf("\nInserindo 25 na posicao 3\n");
    addAt(list, 3, 25);
    printList(list); // Esperado: 30 <-> 20 <-> 10 <-> 25 <-> 40 <-> 50

    int val;
    printf("\nPegando valor na posicao 4\n");
    if (getAt(list, 4, &val)) {
        printf("Valor: %d\n", val); // Esperado: 40
    } else {
        printf("Indice invalido\n");
    }

    printf("\nAtualizando posicao 2 para 15\n");
    if (setAt(list, 2, 15)) {
        printList(list); // Esperado: 30 <-> 20 <-> 15 <-> 25 <-> 40 <-> 50
    } else {
        printf("Indice invalido\n");
    }

    printf("\nRemovendo elemento na posicao 0\n");
    if (removeAt(list, 0, &val)) {
        printf("Removido: %d\n", val); // Esperado: 30
        printList(list); // Esperado: 20 <-> 15 <-> 25 <-> 40 <-> 50
    }

    printf("\nRemovendo elemento na ultima posicao\n");
    if (removeAt(list, size(list) - 1, &val)) {
        printf("Removido: %d\n", val); // Esperado: 50
        printList(list); // Esperado: 20 <-> 15 <-> 25 <-> 40
    }

    printf("\nRemovendo elemento na posicao 2\n");
    if (removeAt(list, 2, &val)) {
        printf("Removido: %d\n", val); // Esperado: 25
        printList(list); // Esperado: 20 <-> 15 <-> 40
    }

    printf("\nBuscando indice do valor 15\n");
    int index;
    if (indexOf(list, 15, &index)) {
        printf("Indice do 15: %d\n", index); // Esperado: 1
    } else {
        printf("Valor nao encontrado\n");
    }

    printf("\nConvertendo lista para array e imprimindo\n");
    int *arr = toArray(list);
    if (arr != NULL) {
        for (int i = 0; i < size(list); i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
    } else {
        printf("Falha na conversao para array\n");
    }

    printf("\nLimpando lista\n");
    clearList(list);
    printList(list); // Esperado: Lista vazia

    printf("Esta vazia? %s\n", isEmpty(list) ? "Sim" : "Nao");

    destroyList(list);

    return 0;
}
