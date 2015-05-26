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
    inserir(minhaLista, 1, 0);
    inserir(minhaLista, 2, 0);
    inserir(minhaLista, 8, 0);
    inserir(minhaLista, 11, 0);



   // obterInicio(minhaLista,&i,0); // Aqui fiquei com duvida paulo //

  // imprimir(minhaLista);
 // obterUltimo(minhaLista);
   printf("obter: %d\n",obterUltimo(minhaLista));
   imprimir(minhaLista);
   // liberarLista(minhaLista);
}

