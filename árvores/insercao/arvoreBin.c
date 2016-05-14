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
void popular(Arvore * arvore);
void imprimeArvore(Arvore*);
Node* buscarVerificarNulidade(Arvore*, int);
Node* buscar(Node*, int);
void imprimeBusca(Node*);

/* Programa principal */
int main(){
	Arvore* minhaArvore;
	minhaArvore = criaArvore(); 
    
    popular(minhaArvore);
    
    printf("\n\nBuscando valores da árvore \n");
    imprimeBusca(buscarVerificarNulidade(minhaArvore, 10));
    imprimeBusca(buscarVerificarNulidade(minhaArvore, 20));
    imprimeBusca(buscarVerificarNulidade(minhaArvore, 15));
    imprimeBusca(buscarVerificarNulidade(minhaArvore, 31));
    
    printf("\n\nÁrvore pré-ordem:\n");
    imprimeArvore(minhaArvore);
    
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
    if(noValor >= valor){
        return noValor;
    }else{
        return valor;
    }
}

void inserirVerificarNulidade(Arvore* arvore, int valor){
    
    if(estaVazia(arvore)){
        inserirRaiz(arvore, valor);
    }
    else{
        Node* no;
        no = arvore->raiz;
        inserir(no, valor);
    }
}
        
void inserir(Node* no, int valor){
    Node* noPai;
    int maior;    
            
    maior = getMaior(no->valor, valor);
    noPai = no;        
    if(maior != no->valor){
        no = no->sad;
        if(no != NULL){
            inserir(no, valor);
        }else{                
            inserirSAD(noPai, valor);
        }
    }
    else{
        no = no->sae;
        if(no != NULL){
            inserir(no, valor);
        }else{                
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
    if(estaVazia(arvore)){
        return NULL;
    }else{
        Node* no;
        no = arvore->raiz;
        return buscar(no, valor);
    }
}

Node* buscar(Node* no, int valor){
    Node* encontrado;
    encontrado = NULL;
    
    if(no->valor == valor){
        encontrado =  no;
    }
    else if(no->valor > valor){
        if (no->sae != NULL){
            no = no->sae;
            encontrado = buscar(no, valor);
        }
    }
    else if(no->valor < valor){
        if (no->sad != NULL){
            no = no->sad;
            encontrado = buscar(no, valor);
        }
    }
    
    return encontrado;
}


void imprimeBusca(Node* no){
    if(no != NULL){
        printf("Valor: %d --------> Endereço de memória: %p\n", no->valor, no);
    }else{
        printf("Valor não encontrado!\n");
    }
}

void popular(Arvore* arvore){   
    inserirVerificarNulidade(arvore, 15); //raiz
    inserirVerificarNulidade(arvore, 13); 
    inserirVerificarNulidade(arvore, 20);      
    inserirVerificarNulidade(arvore, 19); 
    inserirVerificarNulidade(arvore, 31);
}

void imprimeArvore(Arvore* arvore){
    Node* no = arvore->raiz;
    
    if(no != NULL){
        printf("%d\n", arvore->raiz->valor);
        
        if(no->sae != NULL){
            arvore->raiz = no->sae;        
            imprimeArvore(arvore);
        }
        if(no->sad != NULL){
            arvore->raiz = no->sad;        
            imprimeArvore(arvore);
        }
    }else{
        printf("Árvore vazia!\n\n");
    }
}
