#ifndef __busca_h
#define __busca_h

#include "definicoes.h"

void buscaLargura(Grafo*, No*);
void printBusca(Fila*, Grafo*);
Fila *criaFila(Grafo*);
int getQtdNosAdjacentes(No*);
//int getQtdNosAdjacentes(Grafo*,int);

#endif
