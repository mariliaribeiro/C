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
    int u, v, x;       
    int s = 0;
    Fila *fila = criaFila(grafo);
            
    for(u = 0; u < grafo->numeroVertices; u ++){       
        fila[u].cor = BRANCO;
        fila[u].distancia = 0;
        fila[u].pai = 0;
    }
    fila[s].cor = CINZA;
    fila[s].distancia = 0;
    fila[s].pai = 0;
    
    enfileirar(fila, no);
    
   while(fila->no != NULL){
        No* noDesenfileirado = desenfileirar(fila);
        int qtdNosAdjacentes = getQtdNosAdjacentes(noDesenfileirado);
        
        for(x=0; x < grafo->numeroVertices; x++){
             //qtdNosAdjacentes = getQtdNosAdjacentes(grafo, s);
             //printf("\n adj: %d", qtdNosAdjacentes);
            for(v=0; v < qtdNosAdjacentes; v++){
                if(fila[v].cor == BRANCO){
                    fila[v].cor = CINZA;
                    fila[v].distancia = fila[x].distancia+1;
                    fila[v].pai = noDesenfileirado->vertices;
                    enfileirar(fila, grafo->vetorListaAdjacencia[v].proximo);                
                }                
                fila[x].cor = PRETO;
            }
            //s++;
            
        } 
    }
    
    printBusca(fila, grafo);
}

//int getQtdNosAdjacentes(Grafo* grafo, int i){
int getQtdNosAdjacentes(No *primeiro){
    int qtdNosAdjacentes = 0;
    //No *primeiro = grafo->vetorListaAdjacencia[i].proximo;
    
    while(primeiro){
        qtdNosAdjacentes +=1;
        primeiro = primeiro->proximo;
    }
    return qtdNosAdjacentes;
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
