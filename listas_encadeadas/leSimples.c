#include<stdlib.h>
#include<stdio.h>

typedef struct node Node;
typedef struct tipolista Lista;

struct node {
	int valor;
	Node *pProx;
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
void remover(Lista*, Node*);
void buscarRemover(Lista*, int);


/* Programa principal */
int main(){
	Lista* minhaLista;
	minhaLista = criaLista();
	printf("Antes da insercao\n");
	detalharLista(minhaLista);
	inserirPrimeiro(minhaLista, 10);
	inserirPrimeiro(minhaLista, 20);
	inserirPrimeiro(minhaLista, 30);
	printf("Depois da insercao\n");
	detalharLista(minhaLista);
	printf("Ultimo elemento\n");
	mostraUltimo(minhaLista);
	inserirN(minhaLista, 22, 1);
	printf("Depois da insercao 2\n");
	detalharLista(minhaLista);

    printf("Removendo valor 20 ...\n");
    buscarRemover(minhaLista, 20);
    printf("Depois da remoção de 20\n");
	detalharLista(minhaLista);
    
    printf("Removendo valor 10 ...\n");
    buscarRemover(minhaLista, 10);
    printf("Depois da remoção de 10\n");
    detalharLista(minhaLista);
    
	return 1;
}

/* Lista de procedimentos */
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

Node* criaNode(){
	Node* novoNo = (Node*) malloc(sizeof(Node));
	novoNo->pProx = NULL;
	return novoNo;
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

void inserirPrimeiro(Lista* lista, int valor){
	Node* novoNo = criaNode();
	novoNo->valor = valor;
	novoNo->pProx = lista->pPrimeiro;
	if(estaVazia(lista)){
		lista->pUltimo = novoNo;
	}
	lista->pPrimeiro = novoNo;
	lista->qtde++;
}

void inserirN(Lista *lista, int valor, int pos){
	Node* noAux;
	Node* novoNo;
	int cont = 1;
	noAux = lista->pPrimeiro;
	while (cont < pos) {
		noAux = noAux->pProx;
		cont++;
	}
	novoNo = criaNode();
	novoNo->valor = valor;
	novoNo->pProx = noAux->pProx;
	noAux->pProx = novoNo;
    lista->qtde++;
}

void mostrar(Node* nodeAux){
	printf("Valor: %d\n", nodeAux->valor);
}

void mostraUltimo(Lista* lista){
	mostrar(lista->pUltimo);
}

void percorrer(Lista* lista){
	Node* aux;
	aux = lista->pPrimeiro;
	while(aux != NULL) {
		mostrar(aux);
		aux = aux->pProx;
	}
}

Node* buscar(Lista* lista, int valor){
    Node* noPosition;
    noPosition = lista->pPrimeiro;
    
    while(noPosition != NULL){
        if(valor == noPosition->pProx->valor){
            return noPosition;
        }
        noPosition = noPosition->pProx;
    }
    return NULL;
}

void buscarRemover(Lista* lista, int valor){
    Node* noAnteriorRemocao;
        
    noAnteriorRemocao = buscar(lista, valor);
    remover(lista, noAnteriorRemocao);
}

void remover(Lista* lista, Node* noAnteriorRemocao){
    Node* noRemover;
    
    if(noAnteriorRemocao != NULL){
        noRemover = noAnteriorRemocao->pProx;
        noAnteriorRemocao->pProx = noRemover->pProx;
        free(noRemover);
        lista->qtde --;
    }
}

