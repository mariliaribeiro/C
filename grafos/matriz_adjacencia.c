#include <stdio.h>
#include <stdlib.h>
//matriz de adjacencia para dígrafo

typedef struct digraph{
    int numVertices; //numero de vértices
    int ** matriz_adj; 
}tipo_digrafo;

tipo_digrafo **criaDigrafo(int);
int **criaMatriz(int, int, int);
void insere_arco_digrafo(tipo_digrafo *, int, int);
void remove_arco_digrafo(tipo_digrafo *, int, int);
void mostraDigrafo(tipo_digrafo *);

int main(void){
    tipo_digrafo *digrafo = criaDigrafo(5); //cria grafo com 5 vértices
        
    insere_arco_digrafo(digrafo, 0, 1);
    insere_arco_digrafo(digrafo, 0, 4);
    insere_arco_digrafo(digrafo, 1, 2);
    insere_arco_digrafo(digrafo, 1, 3);
    insere_arco_digrafo(digrafo, 1, 4);
    insere_arco_digrafo(digrafo, 2, 3);
    insere_arco_digrafo(digrafo, 3, 4);
    
    mostraDigrafo(digrafo);
	remove_arco_digrafo (digrafo, 0, 4);
	remove_arco_digrafo (digrafo, 2, 3);
	mostraDigrafo(digrafo);
    
    return 0;
}

tipo_digrafo **criaDigrafo(int num_vertices){
    tipo_digrafo *G = malloc(sizeof *G);
    G->numVertices = num_vertices;
    G->matriz_adj = criaMatriz(num_vertices, num_vertices, 0);
    
    return G;
}

/*
 A função abaixo aloca uma matriz com linhas 0.. total_linha-1 e colunas 0.. total_coluna-1.
 Cada elemento da matriz recebe valor val.
 */
int **criaMatriz(int total_linha, int total_coluna, int valor){
    int linha, coluna;
    
    // cria vetor de ponteiros para inteiro
    int **matriz = malloc(total_linha * sizeof(int *));
    
    //cria um vetor de inteiros para cada elemento do vetor criado anteriormente
    for (linha=0; linha < total_linha; linha++)
        matriz[linha] = malloc(total_coluna * sizeof(int));
    
    // inicializa a matriz
    for (linha = 0; linha < total_linha; linha ++)
        for(coluna = 0; coluna < total_coluna; coluna++)
            matriz[linha][coluna] = valor;
            
    return matriz;
}

void insere_arco_digrafo(tipo_digrafo *digrafo, int origem, int destino){
    if(origem != destino && digrafo->matriz_adj[origem][destino] == 0)
        digrafo->matriz_adj[origem][destino] = 1;
    
}

void remove_arco_digrafo(tipo_digrafo *digrafo, int origem, int destino){
    if(digrafo->matriz_adj[origem][destino] == 1)
        digrafo->matriz_adj[origem][destino] = 0;    
}

void mostraDigrafo(tipo_digrafo *digrafo){
    int origem, destino;
    printf("\n MOSTRA MATRIZ DE ADJACENCIA DIGRAFO\n");
    printf("%2d %2d %2d %2d %2d\n", 0, 1, 2, 3, 4);
    printf("\n");
    
    for(origem = 0; origem < digrafo->numVertices; destino++){
        printf("%2d ", origem);
        for(destino = 0; destino < digrafo->numVertices; destino++){
            printf(" %2d", digrafo->matriz_adj[origem][destino]);
        }
        printf(" \n");
    }
}
