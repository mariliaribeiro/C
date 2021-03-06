#include <stdio.h>
#include <stdlib.h>

// no da lista adjacente
typedef struct no{
    int vertice; // índice do vetor da lista de adjacencia
    struct no *prox; // ponteiro para o pŕoximo nó
}no_t;

/* estrutura do grafo. Um grafo é um vetor da lista de adjacencia. 
 O tamanho do vetor será o número de vertices do grafo */
typedef struct grafo{
    int num_vertices; //numero de vértices
    no_t *VETOR_list_adj; // vetor da lista de adjacencia
}grafo_t;

grafo_t *criaGRAFO(int);
void addARESTA(grafo_t*, int, int);
no_t *criaNO(int);
void mostraGRAFO(grafo_t*, char*);
void destroiGRAFO(grafo_t*);
grafo_t* limparGRAFO(grafo_t*); 

int main(void){
    grafo_t *dir_grafo = criaGRAFO(5); //cria grafo com 5 vértices
    
    addARESTA(dir_grafo, 0, 1);
    addARESTA(dir_grafo, 0, 4);
    addARESTA(dir_grafo, 1, 2);
    addARESTA(dir_grafo, 1, 3);
    addARESTA(dir_grafo, 1, 4);
    addARESTA(dir_grafo, 2, 3);
    addARESTA(dir_grafo, 3, 4);
    
    //printf("\n GRAFO DIRECIONADO - DIGRAFO\n\n"); 
    system("clear");
    mostraGRAFO(dir_grafo, "Grafo");
    
    //destroiGRAFO(dir_grafo);    
    dir_grafo = limparGRAFO(dir_grafo);
    free(dir_grafo);
    
    mostraGRAFO(dir_grafo, "Apos a remoção");
    
    //mostraGRAFO(dir_grafo);
    
    printf("Pressione Enter para continuar...");
    getchar();
    return 0;
}

void mostraGRAFO(grafo_t* grafo, char* mensagem)
{
    printf("Visualização do Grafo: %s\n", mensagem);
    if(grafo->num_vertices == 0)
        printf("Grafo vazio!");
    
    int i;
    for(i=0; i<grafo->num_vertices; i++)
    {
        no_t *Primeiro = grafo->VETOR_list_adj[i].prox;
        printf("\n(%d)->", i);
        while(Primeiro)
        {
            printf("(%d)->", Primeiro->vertice);
            Primeiro = Primeiro->prox;
        }
    }
    printf("\n\n");
}

//cria grafo com n vértices
grafo_t *criaGRAFO(int n){
    int i;
    grafo_t *grafo = (grafo_t*) malloc(sizeof(grafo_t)); //cast para alocar um endereço na memória
    
    if(!grafo)
        printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMÓRIA PARA O GRAFO \n SAINDO ...\n");
    grafo->num_vertices = n;
    
    // cria um vetor de lista adjacente
    grafo->VETOR_list_adj = (no_t*) malloc(n * sizeof(no_t));
    if(!grafo->VETOR_list_adj)
        printf("[ERRO FATAL]: INCAPAZ DE ALOCAR MEMÓRIA PARA O VETOR DE LISTA ADJACENTE \n SAINDO ...\n");
        
    for(i = 0; i < n; i++)
        grafo->VETOR_list_adj[i].prox = NULL;
        
    return grafo;
}

void addARESTA(grafo_t*grafo, int origem, int destino){    
    //adiciona uma aresta da origem para o destino na lista de adjacencia
    no_t *novoNO = criaNO(destino);
    novoNO->prox = grafo->VETOR_list_adj[origem].prox;
    grafo->VETOR_list_adj[origem].prox = novoNO;
    
    //cria caminho contrario
    novoNO = criaNO(origem);
    novoNO->prox = grafo->VETOR_list_adj[destino].prox;
    grafo->VETOR_list_adj[destino].prox = novoNO;
}
no_t *criaNO(int v){
    /*
     * cria um nó na lista de adjacência
     */
    no_t *novoNO = (no_t*)malloc(sizeof(no_t));
    
    if(!novoNO)
        printf("[ERRO FATAL]: IMPOSSÍVEL ALOCAR MEMÓRIA PARA UM NOVO NÓ \n SAINDO ...\n");    
        
    novoNO->vertice = v;
    novoNO->prox = NULL;
    
    return novoNO;
}

void destroiGRAFO(grafo_t* grafo)
{
    if(grafo)
    {
        if(grafo->VETOR_list_adj)
        {
            int v;
            
            for(v=0; v < grafo->num_vertices; v++)
            {
                no_t *Primeiro = grafo->VETOR_list_adj[v].prox;
                while(Primeiro)
                {
                    no_t *tmp = Primeiro;
                    Primeiro = Primeiro->prox;
                    free(tmp);
                }
            }
            grafo->num_vertices = 0;
            free(grafo->VETOR_list_adj);
        }
        free(grafo);
        printf("Grafo destruido!\n");
    }
}

grafo_t* limparGRAFO(grafo_t* grafo)
{
    if(grafo)
    {
        if(grafo->VETOR_list_adj)
        {
            int v;
            
            for(v=0; v < grafo->num_vertices; v++)
            {
                no_t *Primeiro = grafo->VETOR_list_adj[v].prox;
                while(Primeiro)
                {
                    no_t *tmp = Primeiro;
                    Primeiro = Primeiro->prox;
                    free(tmp);
                }
            }
            grafo->num_vertices = 0;
            free(grafo->VETOR_list_adj);
        }
        //free(grafo);
        printf("Grafo destruido!\n");
    }
    return grafo;
}
