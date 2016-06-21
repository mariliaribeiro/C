#include "busca.h"
//#include "heap.h"
#include "fila.h"

void printBusca(Dijkstra *fila, Grafo *grafo){
    int i;
    for(i = 0; i < grafo->numeroVertices; i ++){
        printf("\n nó: %d distancia:[%d] pai:[%d]\n", grafo->vetorListaAdjacencia[i].vertices, fila->distancia[i], fila->pai[i]);
    }
}

void dijkstra(Grafo* grafo, No *no){
    Dijkstra *dj = criaDijkstra(grafo);
    Fila *fila = criaFila(grafo);
    
    dj->distancia[no->vertices] = 0;
    dj->distrancia_provisoria = no->vertices;
    dj->minimo = no;
           
    while(dj->distrancia_provisoria != -1){
        No* u = no;
        if(dj->minimo->vertices > u->vertices)
            dj->minimo = u;
        
        /*removerMinimo(grafo->numeroVertices, dj, minimo);
        fila = enfileirar(fila, minimo); //S <- S U {u}
        printf("%d, %d", no->vertices, minimo->vertices);
        */
        
        /*No* u = no;
         while(u->proximo != NULL){
            No* v = u->proximo;
            if(dj->distancia[v->vertices] > (dj->distancia[u->vertices] + grafo->vetorListaAdjacencia[no->vertices].custoAresta)){
				dj->distancia[v->vertices]  = (dj->distancia[u->vertices] + grafo->vetorListaAdjacencia[no->vertices].custoAresta);
                dj->pai[v->vertices] = u->vertices;
			}
             u = v;               
		} */           
	}
    
    //printBusca(fila, grafo);
}

Dijkstra *criaDijkstra(Grafo *grafo){
    Dijkstra *fila = (Dijkstra*) malloc(grafo->numeroVertices * sizeof(Dijkstra));
    fila->pai = (int*) malloc(grafo->numeroVertices * sizeof(int*));
    fila->distancia = (int*) malloc(grafo->numeroVertices * sizeof(int*));
    fila->no = (No*) malloc(grafo->numeroVertices * sizeof(No));
    fila->minimo = (No*) malloc(grafo->numeroVertices * sizeof(No));
    fila->distrancia_provisoria = 0;
    
    fila->minimo= NULL;

    int i;
    for (i=0; i < grafo->numeroVertices; i++){
		fila->pai[i] = -1;
        fila->distancia[i] = -1;
		fila[i].no= NULL;
	}
    return fila;
}

Fila *criaFila(Grafo *grafo){
    Fila *fila = (Fila*) malloc(grafo->numeroVertices * sizeof(Fila)); 
    fila->no = (No*) malloc(grafo->numeroVertices * sizeof(No));    
    //fila->distancia = (int*) malloc(grafo->numeroVertices * sizeof(int*));
    //fila->caminho = (int*) malloc(grafo->numeroVertices * sizeof(int*));    
    fila->tamanho = 0;

    int i;
    for (i=0; i < grafo->numeroVertices; i++){
		fila[i].no= NULL;
        //fila->distancia[i] = 0;	
    }
    
    return fila;
}
