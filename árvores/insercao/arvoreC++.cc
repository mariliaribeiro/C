#include <iostream>
using namespace std;

//------------- Prototipação das classes ------------- //
class No {
    public:
        int valor;
        No* direito;
        No* esquerdo;
        No ();
        No (int);
};

class Arvore {
    public:
        No* raiz;
        Arvore ();
        void inserir (int);
        No* inserirR (No*, int);
        void percursoEmOrdem (No*);        
        void percursoPreOrdem (No*);   
        void percursoPosOrdem (No*);
        No* removerFolha(No*);
};

//------------- Métodos da classe No ------------- //
No :: No () {
    this->direito = NULL;
    this->esquerdo = NULL;
    // direito = esquerdo = NULL;
}

No :: No (int v) {
    valor = v;
    direito = esquerdo = NULL;
}

//------------- Metodos da classe Arvore ------------- //
Arvore :: Arvore () {
    raiz = NULL;
}

void Arvore :: percursoEmOrdem (No* subRaiz) {
    if (subRaiz != NULL){
        percursoEmOrdem(subRaiz->esquerdo);
        cout << subRaiz->valor << " ";
        percursoEmOrdem(subRaiz->direito);
    }   
}

void Arvore :: percursoPreOrdem (No* subRaiz) {
    if (subRaiz != NULL){
        cout << subRaiz->valor << " ";
        percursoPreOrdem(subRaiz->esquerdo);
        percursoPreOrdem(subRaiz->direito);
    }   
}

void Arvore :: percursoPosOrdem (No* subRaiz) {
    if (subRaiz != NULL){
        percursoPosOrdem(subRaiz->esquerdo);
        percursoPosOrdem(subRaiz->direito);
        cout << subRaiz->valor << " ";
    }   
}

void Arvore :: inserir (int v) {
    No* noAtual = raiz;
    No* ant = NULL;
    while (noAtual != NULL) {
        ant = noAtual;
        if (noAtual->valor < v) {
            noAtual = noAtual->direito;
        } else {
            noAtual = noAtual->esquerdo;
        }
    }
    
    if (ant == NULL) {
        raiz = new No(v);
    } else if (ant->valor < v) {
        ant->direito = new No(v);
    } else {
        ant->esquerdo = new No(v);
    }        
}

No* Arvore :: inserirR (No* subRaiz, int v) {
    if (subRaiz == NULL)
        return new No(v);
    if (subRaiz->valor < v)
        subRaiz->direito = inserirR(subRaiz->direito, v);
    else
        subRaiz->esquerdo = inserirR(subRaiz->esquerdo, v);
    return subRaiz;
}

No* Arvore :: removerFolha(No* no){
    if (no != NULL){
        removerFolha(no->esquerdo);
        removerFolha(no->direito);
        delete no;
        return no;
    }
    
    return NULL;
}


//------------- Programa Principal ------------- //
int main () {
    //int x;
    Arvore* minhaArvore = new Arvore();

    cout << "Em ordem:";
    minhaArvore->percursoEmOrdem(minhaArvore->raiz);
    cout << endl;

    cout << "Pré ordem:";
    minhaArvore->percursoPreOrdem(minhaArvore->raiz);
    cout << endl;
    
    cout << "Pós ordem:";
    minhaArvore->percursoPosOrdem(minhaArvore->raiz);
    cout << endl;
    
    minhaArvore->inserir(10);
    minhaArvore->inserir(5);
    minhaArvore->inserir(1);
    minhaArvore->inserir(15);
    minhaArvore->raiz = minhaArvore->inserirR(minhaArvore->raiz, 20);
    minhaArvore->raiz = minhaArvore->inserirR(minhaArvore->raiz, 18);
    minhaArvore->inserir(13);

    cout << "Em ordem:";
    minhaArvore->percursoEmOrdem(minhaArvore->raiz);
    cout << endl;

    cout << "Pré ordem:";
    minhaArvore->percursoPreOrdem(minhaArvore->raiz);
    cout << endl;

    cout << "Pós ordem:";
    minhaArvore->percursoPosOrdem(minhaArvore->raiz);
    cout << endl;


    //minhaArvore->removerFolha(minhaArvore->raiz);
    No* remover = minhaArvore->removerFolha(minhaArvore->raiz);
    cout << "Nó removido: " << remover->valor;
    cout << endl;

    cout << "Pós ordem:";
    minhaArvore->percursoPosOrdem(minhaArvore->raiz);
    cout << endl;

    
    return 1;
}

