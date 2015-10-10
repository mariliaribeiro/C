#include<stdlib.h>
#include<stdio.h>

typedef struct node Node;   // Literatura as vezes chama de celula
typedef struct arvoreBinaria Arvore;

struct node {
	int valor;
	Node *fEsquerda;
	Node *fDireita;
};

struct arvoreBinaria {
	Node* raiz;
    int altura;
};

/* Prototipações */
Arvore* criaArvore();
Node* criaNode();
int estaVazia(Arvore*);
void inserir(Arvore*, int);
void inserirRaiz(Arvore*, int);
void inserirEsquerda(Arvore *, int);
void inserirDireita(Arvore *, int);
void popular(Arvore* arvore);

/* Programa principal */
int main(){
	Arvore* minhaArvore;
	minhaArvore = criaArvore();    
    
    inserir(minhaArvore, 15); //raiz
	return 1;
}

Arvore* criaArvore() {
	Arvore* novaArvore = (Arvore*) malloc(sizeof(Arvore));
	novaArvore->raiz = NULL;
	novaArvore->altura = 0;
	return novaArvore;
}

Node* criaNode(){
	Node* novoNo = (Node*) malloc(sizeof(Node));
	novoNo->fEsquerda = NULL;
    novoNo->fDireita = NULL;
	return novoNo;
}

void inserirRaiz(Arvore* arvore, int valor){
	Node* novoNo = criaNode();
	novoNo->valor = valor;
    arvore->raiz = novoNo;
	arvore->altura++
}

void inserirDireita(Arvore* arvore, int valor){
	Node* novoNo = criaNode();
	novoNo->valor = valor;
    arvore->raiz = novoNo;
	arvore->altura++
}

void percorrer(Arvore* arvore){
	Node* no;
	Node* esq;
	Node* dir;
    no = arvore->raiz;
    if(no!=NULL){
        esq = percorreEsq(no);
        dir = percorreDir(no);
    }
}

Node* percorreEsq(Node * no){
    while(no != NULL) {
		esq = no->fEsquerda;
        percorreEsq(esq);
	}
    return no;
}

Node* percorreDir(Node * no){
    Node * dir;
    while(no->fEsquerda != NULL) {
		dir = no->fEsquerda;
        percorreDir(dir);    
	}
    return no;
}

void detalharArvore(Arvore* arvore) {
	if (estaVazia(arvore)) {
		printf("Lista vazia\n");
	} else {
		printf("Lista não vazia\n");
		printf("Quantidade: %d\n", lista->qtde);
		percorrer(lista);
	}
}


void popular(Arvore* arvore){    
    inserir(arvore, 15); //raiz
    inserir(arvore, 13);
    inserir(arvore, 20);
    inserir(arvore, 11);
    inserir(arvore, 14);
    inserir(arvore, 19);
    inserir(arvore, 31);
    inserir(arvore, 29);
    

}

