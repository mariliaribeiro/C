#include <stdio.h>
#include <stdlib.h>		
/* A estrutura digraph representa um digrafo.*/ 
/* O campo matriz_adj � um ponteiro para a matriz de adjac�ncia do digrafo. */
/* O campo numVertice cont�m o n�mero de v�rtices */
 
typedef struct digraph {
   int numVertice;
   int **matriz_adj; //matriz de inteiros
}tipo_digrafo;

/* A fun��o abaixo aloca uma matriz com linhas 0..total_linha-1 e colunas 0..total_coluna-1. 
Cada elemento da matriz recebe valor val. */
 
int **criaMatriz (int total_linha, int total_coluna, int valor) {
   int linha, coluna;
   //cria vetor de ponteiros para inteiro
   int **matriz = malloc(total_linha * sizeof(int *));
   //cria um vetor de inteiros para cada elemento do vetor criado anteriormente
   for (linha = 0; linha < total_linha; linha++)
      matriz[linha] = malloc(total_coluna * sizeof(int));
      
   //inicializa a matriz   
   for (linha = 0; linha < total_linha; linha++)
      for (coluna = 0; coluna < total_coluna; coluna++)
         matriz[linha][coluna] = valor;
         
   return matriz;
}


/* Esta fun��o devolve (o endere�o de) um novo digrafo com v�rtices 0,..,V-1 e nenhum arco. */
tipo_digrafo *criaDIGRAFO (int num_vertices) {
   tipo_digrafo *G = malloc(sizeof *G);
   G->numVertice = num_vertices;
   G->matriz_adj = criaMatriz(num_vertices, num_vertices, 0); //cria a matriz e a inicializa
   
   return G;
}

/* Esta fun��o insere um arco origem - destino no digrafo. 
   Se origem == destino ou o digrafo j� tem arco origem - destino, a fun��o n�o faz nada.  
   � claro que origem e destino n�o podem ser negativos */
/*insere um arco EM UMA MATRIZ DE ADJACENCIA - DIGRAFO*/
void insere_arco_digrafo (tipo_digrafo *digrafo, int origem, int destino) {
   if (origem != destino && digrafo->matriz_adj[origem][destino] == 0) {
      digrafo->matriz_adj[origem][destino] = 1;
   }
}
/* Esta fun��o remove do digrafo G o arco que tem ponta inicial v e ponta final w.  Se n�o existe tal arco, a fun��o nada faz. */
 
void remove_arco_digrafo (tipo_digrafo *digrafo, int origem, int destino) {
   if (digrafo->matriz_adj[origem][destino] == 1) {
      digrafo->matriz_adj[origem][destino] = 0;
   }
}
/* Para cada v�rtice v do digrafo G, esta fun��o imprime, em uma linha, todos os v�rtices adjacentes a v. */
 
void mostra_digrafo (tipo_digrafo *digrafo) {
   int origem, destino;   
   printf("\nMOSTRA MATRIZ ADJACENCIA DIGRAFO\n");
    printf("    %2d %2d %2d %2d %2d \n", 0,1,2,3,4);
    printf("\n");
   for (origem = 0; origem < digrafo->numVertice; origem++)
   {   printf("%2d ", origem);
   	   for (destino = 0; destino < digrafo->numVertice; destino++)
   	   {	
            printf(" %2d", digrafo->matriz_adj[origem][destino]);
       }
       
       printf(" \n");
   }
}

/* Esta fun��o insere EM UMA MATRIZ DE ADJACENCIA - GRAFO, uma aresta v-w no grafo G. */
void insere_arco_GRAFO (tipo_digrafo *digrafo, int origem, int destino) {
   insere_arco_digrafo(digrafo, origem, destino);
   insere_arco_digrafo(digrafo, destino, origem);
}

int main()
{
	tipo_digrafo *digrafo = criaDIGRAFO(5);
	insere_arco_digrafo (digrafo, 0, 1);
	insere_arco_digrafo (digrafo, 0, 4);
	insere_arco_digrafo (digrafo, 1, 2);
	insere_arco_digrafo (digrafo, 2, 3);
	insere_arco_digrafo (digrafo, 3, 0);
	insere_arco_digrafo (digrafo, 3, 4);
	
	mostra_digrafo(digrafo);
	remove_arco_digrafo (digrafo, 0, 4);
	remove_arco_digrafo (digrafo, 2, 3);
	mostra_digrafo(digrafo);
	return 0;
}
