#include "fila.h"

Fila *enfileirar(Fila *fila, No *no){      
    fila[fila->tamanho].no = no;
    //fila->distancia[fila->tamanho] = no->;
    fila->tamanho++;
}
    
void removerMinimo(int tamanho, Dijkstra *fila, No* no){    
    int i;
    
    for (i = 1; i < tamanho; i++){
        if(fila[i-1].no == no){
            fila[i-1].no = fila[i].no;
        }
    }
        
    fila[tamanho].no = NULL;
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
