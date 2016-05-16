#include "definicoes.h"
#include "grafo.h"
#include "fila.h"
#include "busca.h"

int main(){    
    Grafo *grafo = criaGrafo(5); //cria grafo com 5 vértices
        
    addAresta(grafo, 0, 1);
    addAresta(grafo, 1, 4);
    addAresta(grafo, 1, 2);
    addAresta(grafo, 1, 0);
    addAresta(grafo, 2, 3);
    addAresta(grafo, 3, 4);
    addAresta(grafo, 3, 0);
    addAresta(grafo, 4, 1);
    
    printf("\n GRAFO DIRECIONADO - DIGRAFO"); 
    mostraGrafo(grafo);
    
    printf("\n BUSCA EM LARGURA - DIGRAFO"); 
    buscaLargura(grafo, &grafo->vetorListaAdjacencia[0]); 
        
    printf("\n\n DESTROI GRAFO"); 
    destroiGrafo(grafo);    
    mostraGrafo(grafo);
    printf("\n");
        
    return 0;
}
