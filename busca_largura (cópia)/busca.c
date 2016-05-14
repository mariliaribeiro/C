#include "busca.h"
#include "fila.h"

void printBusca(int cor[], int distancia[], int pai[], Grafo* grafo){
    int i;
    for(i = 0; i < grafo->numeroVertices; i ++){
        printf("\ncor[%d] distancia[%d] pai[%d]", cor[i], distancia[i], pai[i]);
    }
}

void buscaLargura(Grafo* grafo, int s){
    int u; int v;
       
    int cor[5];
    int pai[5];
    int distancia[5];
    int BRANCO = 0; int CINZA = 1; int PRETO = 2;
    
    
    for(u = 0; u < grafo->numeroVertices; u ++){
        cor[u] = BRANCO;
        distancia[u] = 0;
        pai[u] = 0;
    }
    cor[s] = CINZA;
    distancia[s] = 0;
    pai[s] = 0;
    
    //printBusca(cor, distancia, pai, grafo);
   
    int *fila = (int *) malloc(sizeof(int));
    enfileirar(fila, grafo->vetorListaAdjacencia[s].proximo->vertices);
        
    while(fila != NULL){
        int d = desenfileirar(fila);
        
        for(v=0; v < grafo->numeroVertices; v++){
            if(cor[v] == BRANCO){
                cor[v] = CINZA;
                distancia[v] = distancia[u]+1;
                pai[v] = u;
                enfileirar(fila, grafo->vetorListaAdjacencia[v].proximo->vertices);                
            }                
            cor[s] = PRETO;
        }
    }
}
