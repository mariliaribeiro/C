#ifndef __definicoes_h
#define __definicoes_h

#include<stdio.h>
#include<stdlib.h>

typedef struct node No;
typedef struct graph Grafo;

// no da lista adjacente
struct node{
    int vertices; // índice do vetor da lista de adjacencia
    No *proximo; // ponteiro para o pŕoximo nó
};

//estrutura do grafo (vetor de lista de adjacencia)
struct graph{
    int numeroVertices; //numero de vértices
    No *vetorListaAdjacencia; // vetor da lista de adjacencia
};

#endif
