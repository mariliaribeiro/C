#include<stdlib.h>
#include<stdio.h>

typedef struct node Node;   // Literatura as vezes chama de celula
typedef struct tipolista Lista;

struct node {
	int valor;
	Node *pProx;
	Node *pAnt;
};

struct tipolista {
	Node* pPrimeiro;
	Node* pUltimo;
	int qtde;
};

/* Prototipações */
Lista* criaLista();
Node* criaNode();
int estaVazia(Lista*);
void detalharLista(Lista*);
void inserirPrimeiro(Lista*, int);
void inserirN(Lista *, int, int);
void mostrar(Node*);
void mostraUltimo(Lista*);
void percorrer(Lista*);
Node* buscar(Lista*, int);
void buscarRemover(Lista*, int);
void remover(Lista*, Node*);
void removerPrimeiro(Lista*, Node*);
void removerUltimo(Lista*, Node*);
void removerLenUm(Lista*);

/* Programa principal */
int main(){
	Lista* minhaLista;
	minhaLista = criaLista();
	
	printf("Antes da inserção\n");
	detalharLista(minhaLista);
	inserirPrimeiro(minhaLista, 10);
	inserirPrimeiro(minhaLista, 20);
	inserirPrimeiro(minhaLista, 30);
	inserirN(minhaLista, 22, 1);
	
	printf("\nDepois da inserção\n");
	detalharLista(minhaLista);

    printf("\nRemovendo valor 20 ...\n");
    buscarRemover(minhaLista, 20);
    printf("Depois da remoção de 20\n");
	detalharLista(minhaLista);
    
    printf("\nRemovendo valor 10 ...\n"); 
    buscarRemover(minhaLista, 10);
    printf("Depois da remoção de 10\n");
    detalharLista(minhaLista);
    
    printf("\nRemovendo valor 30 ...\n");
    buscarRemover(minhaLista, 30);
    printf("Depois da remoção de 30\n");
    detalharLista(minhaLista);
    
    printf("\nRemovendo valor 22 ...\n");
    buscarRemover(minhaLista, 22);
    printf("Depois da remoção de 22\n");
    detalharLista(minhaLista);
    
	return 1;
}

/* Métodos para a Lista* */

Lista* criaLista() {
	Lista* novaLista = (Lista*) malloc(sizeof(Lista));
	novaLista->pPrimeiro = NULL;
	novaLista->pUltimo = NULL;
	novaLista->qtde = 0;
	return novaLista;
}

/* Retorna zero(0) se lista estiver vazia */
int estaVazia(Lista* lista){
	return (lista->pPrimeiro == NULL);
}

void percorrer(Lista* lista){
	Node* aux;
	aux = lista->pPrimeiro;
	while(aux != NULL) {
		mostrar(aux);
		aux = aux->pProx;
	}
}

void detalharLista(Lista* lista) {
	if (estaVazia(lista)) {
		printf("Lista vazia\n");
	} else {
		printf("Lista não vazia\n");
		printf("Quantidade: %d\n", lista->qtde);
		percorrer(lista);
	}
}

void mostraUltimo(Lista* lista){
	mostrar(lista->pUltimo);
}

/* Métodos para o nó */
Node* criaNode(){
	Node* novoNo = (Node*) malloc(sizeof(Node));
	novoNo->pProx = NULL;
    novoNo->pAnt = NULL;
	return novoNo;
}

void inserirPrimeiro(Lista* lista, int valor){
	Node* novoNo = criaNode();
    Node* noAux;
	novoNo->valor = valor;
	novoNo->pProx = lista->pPrimeiro;
    novoNo->pAnt = NULL;
	
    lista->pPrimeiro = novoNo;
    noAux = lista->pPrimeiro;
    
    if(lista->pUltimo == NULL){
        lista->pUltimo = lista->pPrimeiro;
    }else{
        noAux = noAux->pProx;
        noAux = noAux->pAnt;
        noAux = novoNo;
    }
	lista->qtde++;
}

void inserirN(Lista *lista, int valor, int pos){
	Node* noAux;
	Node* novoNo;
    
	noAux = lista->pPrimeiro;
	int cont = 1;	
	while (cont < pos) {
		noAux = noAux->pProx;
		cont++;
	}
    	
	novoNo = criaNode();
	novoNo->valor = valor;

	novoNo->pAnt = noAux; //anterior do novo é o aux
    novoNo->pProx = noAux->pProx; //o proximo do novo é o prox do auxiliar (aux->pProx)
    noAux->pProx->pAnt = novoNo; // prox do novo nó recebe o novo nó como anterior
	noAux->pProx = novoNo; // prox do nó aux é o novoNó
    
    lista->qtde ++;
}

void mostrar(Node* nodeAux){
	printf("Valor: %d\n", nodeAux->valor);
}

Node* buscar(Lista* lista, int valor){
    Node* noPosition;
    noPosition = lista->pPrimeiro;
    
    while(noPosition != NULL){
        if(valor == noPosition->valor){
            return noPosition;
        }
        noPosition = noPosition->pProx;
    }
    return NULL;
}

void buscarRemover(Lista* lista, int valor){
    Node* noRemover;
        
    noRemover = buscar(lista, valor);
    remover(lista, noRemover);
}

void remover(Lista* lista, Node* noRemover){
    if(noRemover != NULL){  
        if(lista->pPrimeiro == lista->pUltimo){
           removerLenUm(lista);
        }else if(noRemover == lista->pPrimeiro){
            removerPrimeiro(lista, noRemover);
        }else if(noRemover == lista->pUltimo){
            removerUltimo(lista, noRemover);
        }else {
            noRemover->pAnt->pProx = noRemover->pProx;
            noRemover->pProx->pAnt = noRemover->pAnt;
        }
        free(noRemover);
        lista->qtde --;
    }
}

void removerPrimeiro(Lista* lista, Node* noRemover){
    noRemover->pProx->pAnt = NULL;
    lista->pPrimeiro = noRemover->pProx;
}

void removerUltimo(Lista* lista, Node* noRemover){
    noRemover->pAnt->pProx = NULL;
    lista->pUltimo = noRemover->pAnt;
}

void removerLenUm(Lista* lista){
    lista->pUltimo = NULL;
    lista->pPrimeiro = lista->pUltimo;
}
