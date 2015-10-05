#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criando a struct
struct notasStruct{
    char nome[50];
    double nota1, nota2, media; 
};
typedef struct notasStruct NOTAS;

int contador = 0;

// prototipação
int getTamanhoVetor(FILE*);
NOTAS *criaPonteiroVetor(int tamanho);

void menu(NOTAS *notas, int tamanho);
void redirecionaMenu(int opcao, NOTAS *notas, int tamanho);

int getPosicao(NOTAS *notas, int tamanho);

void insert(NOTAS *notas, int tamanho, int posicao);
void remover(NOTAS *notas, int tamanho, int posicao);
int search(NOTAS *notas, int tamanho, char pesquisa[50]);
void printSearch(NOTAS *notas, int posicao);

NOTAS *setInfoVetor(FILE* arq, int tamanho, NOTAS *notas);
void printVetor(NOTAS *notas, int tamanho);
double somaNotas(double, double);
double mediaAluno(double, double);


//Main
int main(int argc, char * argv[]){     
    FILE *arq; // ponteiro para arquivo
    int tamanho, tamanhoArq;
    NOTAS *notas; //variável do tipo notas
      
    if (argc != 2) {
        printf("Erro de sintaxe: %s NOME_ARQUIVO\n", argv[0]);
        return 1;
    }   
    
    arq = fopen(argv[1], "r"); 
    if (arq == NULL)
        printf("Erro ao abrir arquivo.\n");
    else {
        tamanhoArq =  getTamanhoVetor(arq);// pega tamanho do arquivo
        tamanho = tamanhoArq *3; 
        notas = criaPonteiroVetor(tamanho); //aloca tamanho dinâmico ao vetor
        
        rewind(arq); //"rebubina" arquivo
        
        notas = setInfoVetor(arq, tamanhoArq, notas);
        
        //printVetor(notas, tamanhoArq);       
        menu(notas, tamanho);
        
        fclose(arq); // fecha arquivo
    }
    return 0;
}

int getTamanhoVetor(FILE * arq){
    char letra;
    int nlinhas = 0;
    while( (letra = fgetc(arq)) != EOF ){
        if (letra == '\n')
            nlinhas++;
    }
    return nlinhas; 
}

NOTAS *criaPonteiroVetor(int tamanho){
    NOTAS *notas;
    
    notas = (NOTAS *) malloc(tamanho * sizeof(NOTAS));
    return notas;
}

NOTAS *setInfoVetor(FILE* arq, int tamanho, NOTAS *notas) {
    int i;
    char nome[50]="";
    double n1=0.0, n2 =0.0;
    for (i=0; i<tamanho; i++){
        fscanf(arq, "%s %lf %lf", nome, &n1, &n2);      
        strcpy(notas[i].nome, nome);
        notas[i].nota1 = n1;
        notas[i].nota2 = n2;
        notas[i].media = mediaAluno(notas[i].nota1, notas[i].nota2);
        contador++;
    }
    return notas;
}

void printVetor(NOTAS *notas, int tamanho){
	int i;
	for (i=0; i<tamanho; i++){
		printf("\n>> Valor do vetor[%d]\n Aluno: %s\n Nota1: %.2lf\n Nota2: %.2lf\n Média: %.2lf\n", i,notas[i].nome, notas[i].nota1, notas[i].nota2, notas[i].media);
	}
}

void menu(NOTAS *notas, int tamanho){
    int opcao=0;
    printf("O que você deseja fazer?\n");
    printf("Inserir (1)\nRemover (2)\nPesquisar(3) \nSair(4)\nDigite: ");
    scanf("%d",&opcao);
 
    redirecionaMenu(opcao, notas, tamanho);
}

void redirecionaMenu(int opcao, NOTAS *notas, int tamanho){
    int posicao = 0, op;
    char aluno[50]="";
    
    switch(opcao){
        case 1:
            posicao = getPosicao(notas, tamanho);
            insert(notas, tamanho, posicao);
            break;
        case 2:
             printf("\nRemover posicao(1) \nRemover nome(2)\nDigite: ");
             scanf("%d", &op);
             if (op ==1){
                printf("Informe uma posição que esteja no intevalo do vetor[0:%d]: ", tamanho-1);
                scanf("%d", &posicao);
             }else if(op ==2){
                printf("\nInsira o nome do aluno que você deseja pesquisar: ");
                scanf("%s", aluno);
                if (aluno != NULL){
                    posicao = search(notas, tamanho, aluno);
                }
             }   
             remover(notas, tamanho, posicao);
            break;
        case 3:
            printf("\nInsira o nome do aluno que você deseja pesquisar: ");
            scanf("%s", aluno);
            if (aluno != NULL){
				posicao = search(notas, tamanho, aluno);
            }
            printSearch(notas, posicao);
            break;
        case 4:
            exit(4);
            break;
        default:
            printf("Opção inválida!\n");
    }
}

int getPosicao(NOTAS *notas, int tamanho){
    int op = 0;
    int posicao = 0;
     
    printf("Informar posição(1) \nApenas inserir(0) \nDigite: ");
    scanf("%d", &op);
     
    if (op==1){
        printf("Informe uma posição que esteja no intevalo do vetor[0:%d]: ", tamanho-1);
        scanf("%d", &posicao);
    }else{
        posicao = contador; //retorna a posição com elemento nulo
    }
    return posicao;
}


void insert(NOTAS *notas, int tamanho, int posicao) {
    int i, x;
    char nome[50]="";
    double n1, n2;
    int prox;
    
    prox = contador; //posição nula
            
    printf("Nome: ");
    scanf("%s", nome);
    printf("Nota1: ");
    scanf("%lf", &n1);
    printf("Nota2: ");
    scanf("%lf", &n2);
    
    for (i=0; i<tamanho; i++){
        if (i == posicao){
            if (posicao != prox){
                // realoca elementos para a próxima posição
                for (x = i; x<prox; x++){
                    notas[prox] = notas[prox-1];
                    prox -= 1;
                }
            }
            //insere elementos na posição determinada
            strcpy(notas[i].nome, nome);
            notas[i].nota1 = n1;
            notas[i].nota2 = n2;
            notas[i].media = mediaAluno(notas[i].nota1, notas[i].nota2);
            }
        printf("\n>> Valor do vetor[%d]\n Aluno: %s\n Nota1: %.2lf\n Nota2: %.2lf\n Média: %.2lf\n", i,notas[i].nome, notas[i].nota1, notas[i].nota2, notas[i].media);
        }    
}

void remover(NOTAS *notas, int tamanho, int posicao) {
    int i,x;
  
    printf("\nRemovendo ...\n>> Valor do vetor[%d]\n Aluno: %s\n Nota1: %.2lf\n Nota2: %.2lf\n Média: %.2lf\n------\n", posicao,notas[posicao].nome, notas[posicao].nota1, notas[posicao].nota2, notas[posicao].media);
    
    for (i=0; i<tamanho; i++){
        if (i == posicao){
            for (x = i; x<contador; x++){
                strcpy(notas[x].nome, notas[x+1].nome);
                notas[x].nota1 = notas[x+1].nota1;
                notas[x].nota2 = notas[x+1].nota2;
                notas[x].media = mediaAluno(notas[x+1].nota1, notas[x+1].nota2);      
            }
        }
    printf("\n>> Valor do vetor[%d]\n Aluno: %s\n Nota1: %.2lf\n Nota2: %.2lf\n Média: %.2lf\n", i,notas[i].nome, notas[i].nota1, notas[i].nota2, notas[i].media);
    }
}


int search(NOTAS *notas, int tamanho, char pesquisa[50]){
    int i;
   
    for (i=0; i<=tamanho; i++){
        if (strcmp(notas[i].nome, pesquisa)==1){
            return i-1; // não entendi o porque está retornando sempre uma posição a mais, por isso estou diminuindo i;
        }
    }
    return -1;
    
}

void printSearch(NOTAS*notas, int posicao){
	if(posicao >= 0){
		printf("\n>> Valor do vetor[%d]\n Aluno: %s\n Nota1: %.2lf\n Nota2: %.2lf\n Média: %.2lf\n", 
		posicao,notas[posicao].nome, notas[posicao].nota1, notas[posicao].nota2, notas[posicao].media);
		
	}else{
		printf("Aluno não encontrado!\n");
	}
}
	
 
 
double somaNotas(double nota1, double nota2){
    return nota1 + nota2;	
}

double mediaAluno(double nota1, double nota2){
    double soma;
    soma = somaNotas(nota1, nota2);
    return soma/2;
}




