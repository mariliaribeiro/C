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
int getMaior(int, int);

//inserção
Node* inserirNo(int);
Arvore* inserir(Arvore*,int);
void popular(Arvore * arvore);
void imprimeArvorePreOrdem(Arvore*);

//busca
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
    imprimeArvorePreOrdem(minhaArvore);
    
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

Node* inserirNo(int valor){
    Node* novoNo = criaNode();
    novoNo->valor = valor;
    return novoNo;
}

int estaVazia(Arvore* arvore){
	return (arvore->raiz == NULL);
}

Arvore* inserir(Arvore* arvore, int valor){  
    if (estaVazia(arvore)){
        arvore->raiz = inserirNo(valor);
    }else{
        if(arvore->raiz->valor < valor){
            arvore->raiz = arvore->raiz->sad;
            inserir(arvore, valor);
        }
        else if (arvore->raiz->valor > valor){
            arvore->raiz = arvore->raiz->sae;
            inserir(arvore, valor);
        }
    }
    return arvore;
}

void popular(Arvore* arvore){   
    inserir(arvore, 15); //raiz
    inserir(arvore, 13); 
    inserir(arvore, 20);      
    inserir(arvore, 19); 
    inserir(arvore, 31);
}

void imprimeArvorePreOrdem(Arvore* arvore){
    Node* no = arvore->raiz;
    
    if(no != NULL){
        printf("%d\n", arvore->raiz->valor);
        
        if(no->sae != NULL){
            arvore->raiz = no->sae;        
            imprimeArvorePreOrdem(arvore);
        }
        if(no->sad != NULL){
            arvore->raiz = no->sad;        
            imprimeArvorePreOrdem(arvore);
        }
    }else{
        printf("Árvore vazia!\n\n");
    }
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

int getMaior(int noValor, int valor){
    if(noValor >= valor){
        return noValor;
    }else{
        return valor;
    }
}
