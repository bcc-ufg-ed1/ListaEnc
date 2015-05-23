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
    if (lista->inicio == NULL) return TRUE;
    else return FALSE;
}

No* criarNo(int item, No* prox) {
	No *no = malloc(sizeof(*no));
	no->item = item;
	no->prox = prox;
	return no;
}

int inserir(ListaEnc* lista, int item, int pos) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (pos < 0 || pos > lista->tam)
        return INDICE_INVALIDO;

    No *novoNo;
    if (pos == 0) {
        // insere no início da lista
        novoNo = criarNo(item, lista->inicio);
        lista->inicio = novoNo;
    } else {
        // prepara para inserir
        No *aux;
        aux = lista->inicio;
        for(int i = 0; i < pos - 1; i++) {
            aux = aux->prox;
        }

        // adiciona o nó
        novoNo = criarNo(item, aux->prox);
        aux->prox = novoNo;
    }
    lista->tam++;
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
        // remove do início da lista
        atual = lista->inicio;
        if (item != NULL)
            *item = atual->item;
        lista->inicio = atual->prox;
        free(atual);
        atual = NULL;
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

int obterElemento(ListaEnc* lista, int* item, int pos) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(lista))
        return ESTRUTURA_VAZIA;
    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;

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
    *tam = lista->tam;
    return OK;
}

int obterInicio(ListaEnc* lista, int *item, int pos){
  if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(lista))
        return ESTRUTURA_VAZIA;
    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;
        obterElemento(lista,item,0);
        return OK;

}
