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
        
    for(i = 0; i < n; i++)
        grafo->vetorListaAdjacencia[i].proximo = NULL;
        
    return grafo;
}

// add aresta para o grafo
void addAresta(Grafo *grafo, int origem, int destino){    
    //adiciona uma aresta da origem para o destino na lista de adjacencia
    No *novoNo = criaNo(destino);
    novoNo->proximo = grafo->vetorListaAdjacencia[origem].proximo;
    grafo->vetorListaAdjacencia[origem].proximo = novoNo;
}

//cria um nó na lista de adjacência
No *criaNo(int v){
    No *novoNo = (No*)malloc(sizeof(No));
    
    if(!novoNo)
        printf("[ERRO FATAL]: IMPOSSÍVEL ALOCAR MEMÓRIA PARA UM NOVO NÓ \n SAINDO ...\n");    
        
        novoNo->vertices = v;
        novoNo->proximo = NULL;
        
        return novoNo;
}

void mostraGrafo(Grafo *grafo){
    int i;  
   
    for (i=0; i < grafo->numeroVertices; i++){
        No *primeiro = grafo->vetorListaAdjacencia[i].proximo;
        printf("\n [%d]->", i+1);
        
        while(primeiro){
            printf("%d->", primeiro->vertices);
            primeiro = primeiro->proximo;
        }
        printf("NULL\n");
    }
}

void destroiGrafo(Grafo *grafo){
    if(grafo){
        if(grafo->vetorListaAdjacencia){
            int v;            
            //liberar os nós
            for(v=0; v < grafo->numeroVertices; v++){
                No *primeiro = grafo->vetorListaAdjacencia[v].proximo;
                while(primeiro){
                    No *tmp = primeiro;
                    primeiro = primeiro->proximo;
                    tmp = NULL;
                    free(tmp);
                }
            }
            // liberar o vetor da lista de adjacencia
            free(grafo->vetorListaAdjacencia);
            
        }
        //liberar o grafo
        free(grafo);        
    }
}
