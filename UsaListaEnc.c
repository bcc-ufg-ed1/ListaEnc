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

    // insere o 7 no in�cio da lista {7}
    inserir(minhaLista, 7, 0);
    inserir(minhaLista, 5, 0);
    inserir(minhaLista, 4, 0);
    inserir(minhaLista, 3, 0);
    inserirNoFim(minhaLista, 19);

    int i,tam;
    obterElemento(minhaLista, &i, 2);
    printf("Elemento da posicao 2: %d\n", i);
    obterTamanho(minhaLista, &tam);
    int v[tam];
    obterVetor(minhaLista, &v);
    for(int j = 0; j < tam; j++){
        printf("v[%d] = %d \n",j,v[j]);
    }
    imprimir(minhaLista);
    remover(minhaLista, NULL, 3);
    imprimir(minhaLista);
    remover(minhaLista, NULL, 2);
    imprimir(minhaLista);
    remover(minhaLista, NULL, 1);
    imprimir(minhaLista);
}

