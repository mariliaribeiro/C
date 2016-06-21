#include "busca.h"
#include "fila.h"

void printBusca(Fila *fila, Grafo *grafo){
    int i;
    for(i = 0; i < grafo->numeroVertices; i ++){
        printf("\n nó: %d cor:[%d] distancia:[%d] pai:[%d]", grafo->vetorListaAdjacencia[i].vertices, fila->cor[i], fila->distancia[i], fila->pai[i]);
    }
}

void printBuscaP(FilaP *fila, Grafo *grafo){
    int i;
    for(i = 0; i < grafo->numeroVertices; i ++){
        printf("\n nó: %d cor:[%d] pai:[%d] distancia:[%d] fila:[%d]", grafo->vetorListaAdjacencia[i].vertices, fila->cor[i], fila->pai[i], fila->distancia[i], fila->fila[i]);
    }
}

void dfs(Grafo *grafo){
    FilaP *fila = criaFilaP(grafo);
    
    int i;
    for (i=0; i < grafo->numeroVertices; i++){
        if(fila->cor[i] == BRANCO){
            buscaProfundidade(grafo, &grafo->vetorListaAdjacencia[i], fila);
        }
	}
    
    //buscaProfundidade(grafo, &grafo->vetorListaAdjacencia[0], fila);
    printBuscaP(fila, grafo);
}

void buscaProfundidade(Grafo *grafo, No *no, FilaP *fila){
    fila->cor[no->vertices] = CINZA;
    fila->tempo += 1;
    fila->distancia[no->vertices] = fila->tempo;
    
    No* u = no;
    while(u->proximo != NULL){
        No* v = u->proximo;
        if(fila->cor[v->vertices] == BRANCO){
            fila->pai[v->vertices] = no->vertices;
            buscaProfundidade(grafo, &grafo->vetorListaAdjacencia[v->vertices], fila);
        }        
        u = v;
    }
    fila->cor[no->vertices] = PRETO;
    fila->tempo += 1;
    fila->fila[no->vertices] = fila->tempo;
    
}

void buscaLargura(Grafo* grafo, No *no){
   Fila *fila = criaFila(grafo);
            
   fila->cor[no->vertices] = CINZA;
   fila->distancia[no->vertices] += 1;
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

FilaP *criaFilaP(Grafo *grafo){
    FilaP *fila = (FilaP*) malloc(grafo->numeroVertices * sizeof(FilaP));
    fila->cor = (int*) malloc(grafo->numeroVertices * sizeof(int*));
    fila->pai = (int*) malloc(grafo->numeroVertices * sizeof(int*));
    fila->distancia = (int*) malloc(grafo->numeroVertices * sizeof(int*));
    fila->fila = (int*) malloc(grafo->numeroVertices * sizeof(int*));
    fila->tempo = 0;

    int i;
    for (i=0; i < grafo->numeroVertices; i++){
		fila->cor[i] = BRANCO;
		fila->pai[i] = -1;
        fila->distancia[i] = 0;
		fila->fila[i] = 0;
	}
    return fila;
}
