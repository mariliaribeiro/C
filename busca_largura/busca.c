#include "busca.h"
#include "fila.h"

void printBusca(Fila *fila, Grafo *grafo){
    int i;
    for(i = 0; i < grafo->numeroVertices; i ++){
        //printf("\ncor[%d] distancia[%d] pai[%d]", fila->cor[i], fila->distancia[i], fila->pai[i]);
        printf("\ncor[%d] distancia[%d] pai[%d]", fila[i].cor, fila[i].distancia, fila[i].pai);
    }
}

void buscaLargura(Grafo* grafo, No *no){
    int u; int v;       
    int BRANCO = 0; int CINZA = 1; int PRETO = 2;
    Fila *fila = criaFila(grafo);
    int s = 0;
            
    for(u = 0; u < grafo->numeroVertices; u ++){
        fila[u].cor = BRANCO;
        fila[u].distancia = 0;
        fila[u].pai = 0;
    }
    fila[s].cor = CINZA;
    fila[s].distancia = 0;
    fila[s].pai = 0;
    
    enfileirar(fila, no);
    
    while(fila != NULL){
        No* noDesenfileirado = desenfileirar(fila);
        
        for(v=0; v < grafo->numeroVertices; v++){
            if(fila[v].cor == BRANCO){
                fila[v].cor = CINZA;
                fila[v].distancia = fila[s].distancia+1;
                fila[v].pai = no;
                enfileirar(fila, grafo->vetorListaAdjacencia[v].proximo);                
            }                
            fila[s].cor = PRETO;
        }
    }
    
    printBusca(fila, grafo);
}


Fila *criaFila(Grafo *grafo){
    Fila *fila = (Fila*) malloc(grafo->numeroVertices * sizeof(Fila)); 
    fila->cor = (int *) malloc(grafo->numeroVertices * sizeof(int));
    fila->distancia = (int *) malloc(grafo->numeroVertices * sizeof(int));
    fila->pai = (int *) malloc(grafo->numeroVertices * sizeof(int));
    fila->no = (No *) malloc(grafo->numeroVertices * sizeof(No));
    fila->cor = NULL;
    fila->distancia = NULL;
    fila->pai = NULL;
    fila->no = NULL;
    fila->tamanho = 0;
    
    return fila;
}
