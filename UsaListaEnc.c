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
    inserir(minhaLista, 7, 0);
    inserir(minhaLista, 5, 0);
    inserir(minhaLista, 4, 0);
    inserir(minhaLista, 3, 0);
    inserirNoFim(minhaLista, 19);

    int i;
    obterElemento(minhaLista, &i, 2);
    printf("Elemento da posicao 2: %d\n", i);

    imprimir(minhaLista);
    remover(minhaLista, NULL, 3);
    imprimir(minhaLista);
    remover(minhaLista, NULL, 2);
    imprimir(minhaLista);
    remover(minhaLista, NULL, 1);
    imprimir(minhaLista);
}

