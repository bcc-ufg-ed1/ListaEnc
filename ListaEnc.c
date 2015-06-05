#include<stdio.h>
#include<stdlib.h>
#include "ListaEnc.h"

ListaEnc* criarLista() {
    ListaEnc* lista = malloc(sizeof(*lista));
    if (lista == NULL)
        return NULL;
    lista->inicio = NULL;
    lista->tam = 0;
    return lista;
}

int liberarLista(ListaEnc* lista) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;

    // remove todos os elementos da lista
    while(!estahVazia(lista))
        remover(lista, NULL, 0);
    free(lista);
    lista = NULL;
    return OK;
}

int estahVazia(ListaEnc* lista) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (lista->inicio == NULL)
        return TRUE;
    return FALSE;
}

No* criarNo(int item, No* prox) {
	No *no = malloc(sizeof(*no));
	if (no == NULL)
        return NULL;
	no->item = item;
	no->prox = prox;
	return no;
}

int inserirNoInicio(ListaEnc* lista, int item) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    No *novoNo = criarNo(item, lista->inicio);
    if (novoNo == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    lista->inicio = novoNo;
    lista->tam++;
    return OK;
}

int inserir(ListaEnc* lista, int item, int pos) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (pos < 0 || pos > lista->tam)
        return INDICE_INVALIDO;

    No *novoNo;
    if (pos == 0) {
        return inserirNoInicio(lista, item);
    } else {
        // prepara para inserir
        No *aux;
        aux = lista->inicio;
        for(int i = 0; i < pos - 1; i++) {
            aux = aux->prox;
        }

        // adiciona o nó
        novoNo = novoNo = criarNo(item, aux->prox);
        if (novoNo == NULL)
            return ESTRUTURA_NAO_INICIALIZADA;
        aux->prox = novoNo;
    }
    lista->tam++;
    return OK;
}

int inserirNoFim(ListaEnc* lista, int item) {
    return inserir(lista, item, lista->tam);
}

int removerDoInicio(ListaEnc* lista, int* item) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(lista))
        return ESTRUTURA_VAZIA;
    No *aux = lista->inicio;
    if (item != NULL)
        *item = aux->item;
    lista->inicio = aux->prox;
    free(aux);
    aux = NULL;
    lista->tam--;
    return OK;

}

int remover(ListaEnc* lista, int* item, int pos) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(lista))
        return ESTRUTURA_VAZIA;
    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;

    No *ant, *atual;
    if (pos == 0) {
        return removerDoInicio(lista, item);
    } else {
        // prepara para remover
        ant = NULL;
        atual = lista->inicio;
        for(int i = 0; i < pos; i++) {
            ant = atual;
            atual = atual->prox;
        }

        // remove o nó atual
        ant->prox = atual->prox;
        if (item != NULL)
            *item = atual->item;
        free(atual);
        atual = NULL;
    }
    lista->tam--;
    return OK;
}

int removerDoFim(ListaEnc* lista, int* item) {
    return remover(lista, item, lista->tam - 1);
}

int obterElemento(ListaEnc* lista, int* item, int pos) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(lista))
        return ESTRUTURA_VAZIA;
    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;
    if (item == NULL)
        return PARAMETRO_INVALIDO;
    No *aux;
    aux = lista->inicio;
    for(int i = 0; i < pos; i++) {
        aux = aux->prox;
    }
    *item = aux->item;

    return OK;
}

int obterTamanho(ListaEnc* lista, int* tam) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (tam == NULL)
        return PARAMETRO_INVALIDO;
    *tam = lista->tam;
    return OK;
}
