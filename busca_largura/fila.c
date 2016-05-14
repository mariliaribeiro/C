#include "fila.h"

void enfileirar(Fila *fila, No *no){       
    int fim = fila->tamanho; 
    int i;
    
    for(i=0; i <= fim; i++){
        if (i == fim){
            fila[i].no = no;
        }
    }
    fila->tamanho++;
    
    printFila(fila);
}
    
No* desenfileirar(Fila *fila){
    int i;   
    No *desenfileirado = fila[0].no;
    
    for (i = 1; i < fila->tamanho; i++)
        fila[i-1].no = fila[i].no;
    
    
    fila[fila->tamanho].no = NULL;
    fila->tamanho--;
    printFila(fila);
    return desenfileirado;
}


void printFila(Fila *fila){
    int i;
    printf("\nFila:[ ");
    //if (fila != NULL){
        for(i = 0; i < fila->tamanho; i ++){
            printf("%d ", fila[i].no->vertices);
        }
    //}
    printf("]");
    printf("tamanho: %d ", fila->tamanho);
}
