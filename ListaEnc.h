#ifndef LISTA_ENC_H
#define LISTA_ENC_H

#define TRUE 1
#define FALSE 0

#define OK 1
#define ESTRUTURA_NAO_INICIALIZADA -1
#define ESTRUTURA_VAZIA -2
#define INDICE_INVALIDO -3
#define PARAMETRO_INVALIDO -4

// declaração da estrutura de uma lista.
typedef struct {
  int item;
  struct No* prox;
} No;

typedef struct {
  No* inicio;
  int tam;
} ListaEnc;

ListaEnc* criarLista();
int liberarLista(ListaEnc* lista);
int estahVazia(ListaEnc* lista);
int inserirNoInicio(ListaEnc* lista, int item);
int inserir(ListaEnc* lista, int item, int pos);
int inserirNoFim(ListaEnc* lista, int item);
int removerDoInicio(ListaEnc* lista, int* item);
int remover(ListaEnc* lista, int* item, int pos);
int removerDoFim(ListaEnc* lista, int* item);
int obterElemento(ListaEnc* lista, int* item, int pos);
int obterTamanho(ListaEnc* lista, int* tam);

#endif
