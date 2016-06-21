#include "heap.h"

//int tamanho = (int)(sizeof(v)/sizeof(int));          
No *heapsort(No *no){
    Vetor *v = criaV(no);
    int i, aux;
	
	for(i=(v->tamanho-1)/2; i>=0; i--)
		criaheap(v, i, v->tamanho-1);		
		
	for(i=v->tamanho-1; i>=1; i--){
		aux = v[0].no->vertices;
		v[0].no->vertices = v[i].no->vertices;
		v[i].no->vertices = aux;
		criaheap(v, 0, i-1);
	}	
    
    return v[v->tamanho-1].no;
}

void criaheap(Vetor *v, int inicio, int final){
	int aux = v[inicio].no->vertices;
	int filho = (inicio * 2) + 1;
	
	while(filho <= final){
		if (filho < final){
			if(v[filho].no->vertices > v[filho+1].no->vertices)
				filho += 1;
		}
				
		if (aux > v[filho].no->vertices){
			v[inicio].no->vertices = v[filho].no->vertices;
			inicio = filho;
			filho = (2 * inicio) + 1;
		}else
			filho = final + 1;
	}	
	v[inicio].no->vertices = aux;
}

Vetor *criaV(No *no){
    int tamanho = 0;
    while(no->proximo != NULL){
        tamanho ++;
    }
   
    Vetor *v = (Vetor*) malloc(tamanho * sizeof(Vetor));
    v->tamanho = tamanho;

    int i;
    for (i=0; i < v->tamanho; i++){
		v[i].no= NULL;
    }
    
    return v;    
}
