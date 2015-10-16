#include<stdlib.h>
#include<stdio.h>

typedef struct node Node; 
typedef struct arvoreBinaria Arvore;

struct node {
	int valor; //element
	Node *sae; //sub árvore a esquerda
	Node *sad; //sub árvore a direita
};

struct arvoreBinaria {
	Node* raiz;
    int altura;
};

/* Prototipações */
Arvore* criaArvore();
Node* criaNode();
int estaVazia(Arvore*);
int altura(Arvore*);
int getMaior(int, int);
void inserirVerificarNulidade(Arvore*,int);
void inserir(Node*,int);
void inserirRaiz(Arvore*, int);
void inserirSAE(Node*, int);
void inserirSAD(Node*, int);
Node* buscarVerificarNulidade(Arvore*, int);
Node* buscar(Node*, int);
void popular(Arvore * arvore);


/* Programa principal */
int main(){
	Arvore* minhaArvore;
	minhaArvore = criaArvore(); 
    
    popular(minhaArvore);
    
    /* Node* busca;
    busca = buscarVerificarNulidade(minhaArvore, 5);
    printf("Endereço de memória: %p ", busca);*/
    
	return 1;
}


/* funções */
Arvore* criaArvore() {
	Arvore* novaArvore = (Arvore*) malloc(sizeof(Arvore));
	novaArvore->raiz = NULL;
	novaArvore->altura = -1;
	return novaArvore;
}

Node* criaNode(){
	Node* novoNo = (Node*) malloc(sizeof(Node));
	novoNo->sae = NULL;
    novoNo->sad = NULL;
	return novoNo;
}

int estaVazia(Arvore* arvore){
	return (arvore->raiz == NULL);
}

int altura(Arvore* arvore){
    if(estaVazia(arvore)){
        return arvore->altura;
    }else{
        return 0;//maior(altura())
    }
}

int getMaior(int noValor, int valor){
    if(noValor > valor){
        return noValor;
    }else{
        return valor;
    }
}

void inserirVerificarNulidade(Arvore* arvore, int valor){
    Node* no;
    no = arvore->raiz;
    
    if(estaVazia(arvore)){
        inserirRaiz(arvore, valor);
    }
    else{
        inserir(no, valor);
    }
}
        
void inserir(Node* no, int valor){
    Node* noPai;
    int maior;    
    
    if (no != NULL){
        maior = getMaior(no->valor, valor);
        noPai = no;
        
        if(maior != no->valor){
            no = no->sad;
            inserir(no, valor);
            inserirSAD(noPai, valor);
        }
        else{
            no = no->sae;
            inserir(no, valor);
            inserirSAE(noPai, valor);
        }
    }
}

void inserirRaiz(Arvore* arvore, int valor){
	Node* novoNo = criaNode();
	novoNo->valor = valor;
    arvore->raiz = novoNo;
}

void inserirSAD(Node * noPai, int valor){
	Node* novoNo = criaNode();
	novoNo->valor = valor;
    noPai->sad = novoNo;
}

void inserirSAE(Node * noPai, int valor){
	Node* novoNo = criaNode();
	novoNo->valor = valor;
    noPai->sae = novoNo;
}

Node* buscarVerificarNulidade(Arvore* arvore, int valor){
    Node* no;
    no = arvore->raiz;
    
    if(estaVazia(arvore)){
        return NULL;
    }else{
        return buscar(no, valor);
    }
}

Node* buscar(Node* no, int valor){
    Node* encontrado;
    
    if (no != NULL){
        if(no->valor == valor){
            encontrado = no;
        }
        else if(no->valor > valor){
            encontrado = buscar(no->sad, valor);
        }
        else if(no->valor < valor){
            encontrado = buscar(no->sae, valor);
        }
        else{
            encontrado = NULL;
        }
    }
    return encontrado;
}

void popular(Arvore* arvore){   
    inserirVerificarNulidade(arvore, 15); //raiz
    inserirVerificarNulidade(arvore, 13); 
    inserirVerificarNulidade(arvore, 20); 
    inserirVerificarNulidade(arvore, 11); 
    inserirVerificarNulidade(arvore, 14); 
    inserirVerificarNulidade(arvore, 19); 
    inserirVerificarNulidade(arvore, 31); 
    inserirVerificarNulidade(arvore, 7); 
}
