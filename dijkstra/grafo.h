#ifndef __grafo_h
#define __grafo_h

#include "definicoes.h"

Grafo *criaGrafo(int);
void addAresta(Grafo*, int, int, int);
No *criaNo(int, int);
void mostraGrafo(Grafo*);

#endif
