#ifndef __definicoes_h
#define __definicoes_h

#include<stdio.h>
#include<stdlib.h>

typedef struct node No;
typedef struct graph Grafo;
typedef struct estrutua_dijkstra Dijkstra;

// no da lista adjacente
struct node{
    int vertices; // índice do vetor da lista de adjacencia
    No *proximo; // ponteiro para o pŕoximo nó
    int custoAresta;
};

//estrutura do grafo (vetor de lista de adjacencia)
struct graph{
    int numeroVertices; //numero de vértices
    int *qtdNosAdjacentes;
    No *vetorListaAdjacencia; // vetor da lista de adjacencia
};

struct estrutua_dijkstra{
    int *pai;
    int *distancia;
    int distrancia_provisoria;
    No *no;
};

#define BRANCO 0
#define CINZA 1
#define PRETO 2


#endif
