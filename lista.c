#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct aresta_ {
    int no;
    int capacidade;
    int distancia;
    struct aresta_ *proximo;
};

struct lista_ {
    Aresta *primeiro;
};

Lista *criar_lista() {
    Lista *l = malloc(sizeof(Lista));
    l->primeiro = NULL;
    return l;
}

int vazia(Lista *a) {
    return a->primeiro == NULL;
}


void inserir_inicio(Lista *a, int n_no, int capacidade, double dist) {
    Aresta *item = malloc(sizeof(Aresta));
    item->no = n_no;
    item->distancia = dist;
    item->capacidade = capacidade;
    if (!vazia(a))item->proximo = a->primeiro;
    else item->proximo = NULL;
    a->primeiro = item;
}

int contem(Lista *l, int i) {
    if (l == NULL) return 0;

    Aresta *item = l->primeiro;
    while (item != NULL) {
        if (item->no == i) return 1;
        item = item->proximo;
    }
    return 0;
}

int buscar_elemento(Lista *l, int elem, int * item_, double * dist) {
    if (l == NULL) return -1;

    Aresta *item = l->primeiro;
    while (item != NULL) {
        if (item->no == elem) {
            *item_ = item->capacidade;
            *dist =  item->distancia;
            return 1;
        }
        item = item->proximo;
    }
    return 0;
}

int remover_elemento(Lista *l, int elem) {
    Aresta *item = l->primeiro;
    Aresta * aux = NULL;
    while (item != NULL) {
        if (item->no == elem) {
            if (aux != NULL)aux->proximo = item->proximo;
            else l->primeiro = NULL;
            free(item);
            return 1;
        }
        aux = item;
        item = item->proximo;
    }
    return -1;
}

void mostrar_lista(Lista *a) {
    Aresta *item = a->primeiro;
    while (item != NULL) {
        printf("---[%dMB]---> %d   ", item->capacidade, item->no);
        item = item->proximo;
    }
    printf("\n");
}

void liberar_lista(Lista ** l) {
    Aresta *item = (*l)->primeiro;
    Aresta * aux = NULL;
    while (item != NULL) {
        aux = item->proximo;
        free(item);
        item = aux;
    }
    free(*l);
}