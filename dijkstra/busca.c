#include "busca.h"

void printBusca(Dijkstra *fila, Grafo *grafo){
    int i;
    for(i = 0; i < grafo->numeroVertices; i ++){
        printf("\n nó: %d distancia:[%d] pai:[%d]\n", grafo->vetorListaAdjacencia[i].vertices, fila->distancia[i], fila->pai[i]);
    }
}

void dijkstra(Grafo* grafo, No *no){
    Dijkstra *fila = criaDijkstra(grafo);
    
    fila->distancia[no->vertices] = 0;
    fila->distrancia_provisoria = no->vertices;
           
    /*while(fila->distrancia_provisoria != -1){
        //Q <- Q - u; // extrair o mínimo(Q) // utilizar heap sort
        //S <- S U {u}
        No* u = no;
        while(u->proximo != NULL){
            No* v = u->proximo;
            if(fila->distancia[v->vertices] > (fila->distancia[u->vertices] + grafo->vetorListaAdjacencia[no->vertices].custoAresta)){
				fila->distancia[v->vertices]  = (fila->distancia[u->vertices] + grafo->vetorListaAdjacencia[no->vertices].custoAresta);
                fila->pai[v->vertices] = u->vertices;
			}
             u = v;               
		}            
	} */
    
    printBusca(fila, grafo);
}

Dijkstra *criaDijkstra(Grafo *grafo){
    Dijkstra *fila = (Dijkstra*) malloc(grafo->numeroVertices * sizeof(Dijkstra));
    fila->pai = (int*) malloc(grafo->numeroVertices * sizeof(int*));
    fila->distancia = (int*) malloc(grafo->numeroVertices * sizeof(int*));
    fila->no = (No*) malloc(grafo->numeroVertices * sizeof(No));
    fila->distrancia_provisoria = 0;

    int i;
    for (i=0; i < grafo->numeroVertices; i++){
		fila->pai[i] = -1;
        fila->distancia[i] = -1;
		fila[i].no= NULL;
	}
    return fila;
}
