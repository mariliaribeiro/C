#include "busca.h"
#include "fila.h"

void printBusca(Fila *fila, Grafo *grafo){
    int i;
    for(i = 0; i < grafo->numeroVertices; i ++){
        printf("\n nó: %d cor:[%d] distancia:[%d] pai:[%d]", grafo->vetorListaAdjacencia[i].vertices, fila->cor[i], fila->distancia[i], fila->pai[i]);
    }
}

void buscaLargura(Grafo* grafo, No *no){
   Fila *fila = criaFila(grafo);
            
   fila->cor[no->vertices] = CINZA;
   fila->distancia[no->vertices] = 0;
   fila->pai[no->vertices] = 0;
    
   enfileirar(fila, no);
       
   while(fila->no != NULL){
        No* noDesenfileirado = desenfileirar(fila);
        No* noPai = noDesenfileirado;
                
        while(noDesenfileirado->proximo != NULL){
			No*  noVertice = noDesenfileirado->proximo;            
            if(fila->cor[noVertice->vertices] == BRANCO){
				fila->cor[noVertice->vertices] = CINZA;
				fila->distancia[noVertice->vertices] = (fila->distancia[noPai->vertices] + 1);
				fila->pai[noVertice->vertices] = noPai->vertices;
				enfileirar(fila, &grafo->vetorListaAdjacencia[noVertice->vertices]);                
			}
             noDesenfileirado = noVertice;               
		}
        fila->cor[noPai->vertices] = PRETO;
            
	} 
    printBusca(fila, grafo);
}

void buscaLargura(Grafo* grafo, No *no){
   Fila *fila = criaFila(grafo);
            
   fila->cor[no->vertices] = CINZA;
   fila->distancia[no->vertices] = 0;
   fila->pai[no->vertices] = 0;
    
   enfileirar(fila, no);
       
   while(fila->no != NULL){
        No* noDesenfileirado = desenfileirar(fila);
        No* noPai = noDesenfileirado;
                
        while(noDesenfileirado->proximo != NULL){
			No*  noVertice = noDesenfileirado->proximo;            
            if(fila->cor[noVertice->vertices] == BRANCO){
				fila->cor[noVertice->vertices] = CINZA;
				fila->distancia[noVertice->vertices] = (fila->distancia[noPai->vertices] + 1);
				fila->pai[noVertice->vertices] = noPai->vertices;
				enfileirar(fila, &grafo->vetorListaAdjacencia[noVertice->vertices]);                
			}
             noDesenfileirado = noVertice;               
		}
        fila->cor[noPai->vertices] = PRETO;
            
	} 
    printBusca(fila, grafo);
}


Fila *criaFila(Grafo *grafo){
    Fila *fila = (Fila*) malloc(grafo->numeroVertices * sizeof(Fila)); 
    fila->cor = (int*) malloc(grafo->numeroVertices * sizeof(int*));
    fila->distancia = (int*) malloc(grafo->numeroVertices * sizeof(int*));
    fila->pai = (int*) malloc(grafo->numeroVertices * sizeof(int*));
    fila->no = (No*) malloc(grafo->numeroVertices * sizeof(No));    
    fila->tamanho = 0;

    int i;
    for (i=0; i < grafo->numeroVertices; i++){
		fila->cor[i] = BRANCO;
		fila->distancia[i] = 0;
		fila->pai[i] = 0;
		fila[i].no= NULL;
	}
    
    return fila;
}
