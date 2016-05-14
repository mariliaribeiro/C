// Arranquei o typedef struct list_adj

/*graph.c*/
#include <stdio.h>
#include <stdlib.h>
 
/* No da lista adjacente*/
typedef struct no
{
    int vertice;                /*Indice do vetor da lista de adjacencia*/
    struct no *prox; /*Ponteiro para o proximo no*/
}no_t;
 
/* Estrutura do Grafo. Um grafo é um vetor da lista de adjacencia.
   O tamanho do vetor será o numero de vertices do grafo*/
typedef struct grafo
{
    int num_vertices;         /*Numero de vertices*/
    no_t *VETOR_list_adj;     /*Vetor da lista de Adjacencia*/
}grafo_t;
 
/* Cria um no na lista de adjacencia*/
no_t *criaNO(int v)
{
    no_t *novoNO = (no_t*)malloc(sizeof(no_t));
    if(!novoNO)
        printf("[ERRO FATAL]: IMPOSSIVEL ALOCAR MEMORIA PARA UM NOVO NO \n SAINDO...\n");
 
    novoNO->vertice = v;
    novoNO->prox = NULL;
 
    return novoNO;
}
 
/* Cria um grafo com n vertices */
grafo_t *criaGRAFO(int n)
{
    int i;
    grafo_t *grafo = (grafo_t*)malloc(sizeof(grafo_t));
    if(!grafo)
        printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMORIA PARA O GRAFO \n SAINDO...\n");
    grafo->num_vertices = n;
 
    /* Cria um vetor de lista adjacente*/
    grafo->VETOR_list_adj = (no_t*)malloc(n * sizeof(no_t));
    if(!grafo->VETOR_list_adj)
        printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMORIA PARA O VETOR DE LISTA ADJACENTE \n SAINDO...\n");
 
    for(i = 0; i < n; i++)
        grafo->VETOR_list_adj[i].prox = NULL;
 
    return grafo;
}
 
/*Destroi o grafo*/
void destroiGRAFO(grafo_t* grafo)
{
    if(grafo)
    {
        if(grafo->VETOR_list_adj)
        {
            int v;
            /*Liberar os nos*/
            for (v = 0; v < grafo->num_vertices; v++)
            {
                no_t *Primeiro = grafo->VETOR_list_adj[v].prox;
                while (Primeiro)
                {
                    no_t *tmp = Primeiro;
                    Primeiro = Primeiro->prox;
                    free(tmp);
                }
            }
            /*Liberar o vetor da lista de adjacencia*/
            free(grafo->VETOR_list_adj);
        }
        /*Liberar o grafo*/
        free(grafo);
    }
}
 
/* Adiciona uma aresta para o grafo*/
void addARESTA(grafo_t *grafo, int origem, int dest)
{
    /* Adiciona uma aresta da origem para o destino na lista de adjacencia*/
    no_t *novoNO = criaNO(dest);
    novoNO->prox = grafo->VETOR_list_adj[origem].prox;
    grafo->VETOR_list_adj[origem].prox = novoNO;
}
 
/* Imprime a lista de adjacencia do grafo*/
void mostraGRAFO(grafo_t *grafo)
{
    int i;
    for (i = 0; i < grafo->num_vertices; i++)
    {
        no_t *Primeiro = grafo->VETOR_list_adj[i].prox;
        printf("\n%d->", i);
        while (Primeiro)
        {
            printf("%d->", Primeiro->vertice);
            Primeiro = Primeiro->prox;
        }
        printf("FIM\n");
    }
}
 
int main()
{
    grafo_t *dir_grafo = criaGRAFO(5);
    //*dir_grafo já é um ponteiro, sendo assim, não é necessário passar &.
    //Você passa o & quando há uma variável estática e você quer passar o endereço dela para uma função
    
    addARESTA(dir_grafo, 0, 1);
    addARESTA(dir_grafo, 0, 4);
    addARESTA(dir_grafo, 1, 2);
    addARESTA(dir_grafo, 1, 3);
    addARESTA(dir_grafo, 1, 4);
    addARESTA(dir_grafo, 2, 3);
    addARESTA(dir_grafo, 3, 4);
 
    printf("\nGRAFO DIRECIONADO - DIGRAFO");
    mostraGRAFO(dir_grafo);
    destroiGRAFO(dir_grafo);
 
    return 0;
}

