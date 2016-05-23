#ifndef __busca_h
#define __busca_h

#include "definicoes.h"

void buscaLargura(Grafo*, No*);
void printBusca(Fila*, Grafo*);
void printBuscaP(FilaP*, Grafo*);
Fila *criaFila(Grafo*);
void dfs(Grafo*);
void buscaProfundidade(Grafo*, No*, FilaP*);
FilaP *criaFilaP(Grafo*);

#endif
