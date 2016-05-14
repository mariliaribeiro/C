#include "fila.h"

void enfileirar(int *fila, int s){       
    int tamanho = (int)(sizeof(fila)/sizeof(int));     
    
    int fim = tamanho-2;    
    
    fila[fim] = s;
    //printFila(fila, tamanho);
}
    
int desenfileirar(int *fila){
    int i;
    int tamanho = (int)(sizeof(fila)/sizeof(int));     
    int desenfileirado = fila[0];
    
    for (i = 1; i < tamanho-1; i++)
        fila[i-1] = fila[i];
    
    int fim = tamanho-2;
    fila[fim] = NULL;
    //printFila(fila, tamanho);
    return desenfileirado;
}


void printFila(int *fila, int tamanho){
    int i;
    printf("\nFila:[ ");
    if (fila != NULL){
        for(i = 0; i < tamanho-1; i ++){
            printf("%d ", fila[i]);
        }
    }
    printf("]");
}
