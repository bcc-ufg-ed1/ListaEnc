#include <stdlib.h>
#include "ListaEnc.h"

void imprimir(ListaEnc* lista) {
    int qtdeElementos;
    obterTamanho(lista, &qtdeElementos);
    printf("[");
    for(int i = 0;i < qtdeElementos; i++) {
        int el;
        obterElemento(lista, &el, i);
        printf(" %d ", el);
    }
    printf("]\n");
}

int main() {
    ListaEnc* minhaLista = criarLista();

    // insere o 7 no início da lista {7}
    inserirNoInicio(minhaLista, 7);
    inserirNoFim(minhaLista, 5);
    inserirNoInicio(minhaLista, 4);
    inserirNoFim(minhaLista, 3);

    int i;
    obterElemento(minhaLista, &i, 2);
    printf("Elemento da posicao 2: %d\n", i);

    imprimir(minhaLista);
    removerDoFim(minhaLista, NULL);
    imprimir(minhaLista);
    remover(minhaLista, NULL, 2);
    imprimir(minhaLista);
    removerDoInicio(minhaLista, NULL);
    imprimir(minhaLista);
}

