#include "fila.h"

void enfileirar(Fila *fila, No *no){      
    fila[fila->tamanho].no = no;
    fila->tamanho++;
}
    
No* desenfileirar(Fila *fila){    
    int i;   
    No *desenfileirado = fila[0].no;

    for (i = 1; i < fila->tamanho; i++)
        fila[i-1].no = fila[i].no;
        
    fila[fila->tamanho].no = NULL;
    fila->tamanho--;
    return desenfileirado;
}


void printFila(Fila *fila){
    int i;
    printf("\nFila:[ ");
        for(i = 0; i < fila->tamanho; i ++){
            printf("%d ", fila[i].no->vertices);
        }
    printf("]");
    printf("tamanho: %d ", fila->tamanho);
}
