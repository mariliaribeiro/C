#include "definicoes.h"
#include "grafo.h"
#include "busca.h"

int main(){    
    Grafo *grafo = criaGrafo(5);
        
    addAresta(grafo, 0, 2, 3);
    addAresta(grafo, 0, 1, 10);
    addAresta(grafo, 1, 3, 2);
    addAresta(grafo, 1, 2, 4);
    addAresta(grafo, 2, 4, 2);
    addAresta(grafo, 2, 3, 8);
    addAresta(grafo, 2, 1, 1);
    addAresta(grafo, 3, 4, 7);
    addAresta(grafo, 4, 3, 9);
    
    printf("\n GRAFO DIRECIONADO - DIGRAFO"); 
    mostraGrafo(grafo);
   
    printf("\n DIJKSTRA - DIGRAFO"); 
    dijkstra(grafo, &grafo->vetorListaAdjacencia[0]);
        
    return 0;
}
