#include "grafo.h"

//cria grafo com n vértices
Grafo *criaGrafo(int n){
    int i;
    Grafo *grafo = (Grafo*) malloc(sizeof(Grafo)); //cast para alocar um endereço na memória
    
    if(!grafo)
        printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMÓRIA PARA O GRAFO \n SAINDO ...\n");
    grafo->numeroVertices = n;
    
    // cria um vetor de lista adjacente
    grafo->vetorListaAdjacencia = (No*) malloc(n * sizeof(No));
    if(!grafo->vetorListaAdjacencia)
        printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMÓRIA PARA O VETOR DE LISTA ADJACENTE \n SAINDO ...\n");
        
    for(i = 0; i < n; i++){
        grafo->vetorListaAdjacencia[i].proximo = NULL;
        grafo->vetorListaAdjacencia[i].vertices = i;
	}
    
    
    return grafo;
}

// add aresta para o grafo
void addAresta(Grafo *grafo, int origem, int valor, int custoAresta){
    //adiciona uma aresta da origem para o destino na lista de adjacencia
    No *novoNo = criaNo(valor, custoAresta);
    novoNo->proximo = grafo->vetorListaAdjacencia[origem].proximo;
    grafo->vetorListaAdjacencia[origem].proximo = novoNo;
}

//cria um nó na lista de adjacência
No *criaNo(int v, int custoAresta){
    No *novoNo = (No*)malloc(sizeof(No));
    
    if(!novoNo)
        printf("[ERRO FATAL]: IMPOSSÍVEL ALOCAR MEMÓRIA PARA UM NOVO NÓ \n SAINDO ...\n");    
        
        novoNo->vertices = v;
        novoNo->proximo = NULL;
        novoNo->custoAresta = custoAresta;
        
        return novoNo;
}

void mostraGrafo(Grafo *grafo){
    int i;  
   
    for (i=0; i < grafo->numeroVertices; i++){
        No *primeiro = grafo->vetorListaAdjacencia[i].proximo;
        printf("\n [%d]->", i);
        
        while(primeiro){
            printf("[%d|%d]->", primeiro->vertices, primeiro->custoAresta);
            primeiro = primeiro->proximo;
        }
        printf("NULL\n");
    }
}
