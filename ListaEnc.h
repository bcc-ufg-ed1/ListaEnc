#define TRUE 1
#define FALSE 0

#define OK 1
#define ESTRUTURA_NAO_INICIALIZADA -1
#define ESTRUTURA_VAZIA -2
#define INDICE_INVALIDO -4

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
int inserir(ListaEnc* lista, int item, int pos);
int remover(ListaEnc* lista, int* item, int pos);
int obterElemento(ListaEnc* lista, int* item, int pos);
int obterTamanho(ListaEnc* lista, int* tam);
