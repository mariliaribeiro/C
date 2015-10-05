#include <stdio.h>
#include <stdlib.h>

//Criando a struct
struct notasStruct{
    char *nome;
    double nota1, nota2, media; 
};
typedef struct notasStruct NOTAS;


// prototipação
int getTamanhoVetor(FILE*);
NOTAS *criaPonteiroVetor(int tamanho);
void setInfoVetor(FILE* arq, int tamanho, NOTAS *notas);
double somaNotas(double, double);
double mediaAluno(double, double);

int main(int argc, char * argv[]){     
	FILE *arq; // ponteiro para arquivo
    int tamanho;
    NOTAS *notas; //variável do tipo notas
      
	if (argc != 2) {
		printf("Erro de sintaxe: %s NOME_ARQUIVO\n", argv[0]);
		return 1;
	}	
    
    //arq=fopen("notas.txt","r");  
    arq = fopen(argv[1], "r"); 
    if (arq == NULL)
		printf("Erro ao abrir arquivo.\n");
	else {
		tamanho = getTamanhoVetor(arq); // pega tamanho do arquivo
		notas = criaPonteiroVetor(tamanho); //aloca tamanho dinâmico ao vetor
		
		rewind(arq); //"rebubina" arquivo
		setInfoVetor(arq, tamanho, notas);
		   
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

void setInfoVetor(FILE* arq, int tamanho, NOTAS *notas) {
	int i;
	char nome[50]="";
	//char *nome;
	double n1, n2;
	for (i=0; i<tamanho; i++){
		fscanf(arq, "%s %lf %lf", nome, &n1, &n2);		
		notas[i].nome = nome;
		notas[i].nota1 = n1;
		notas[i].nota2 = n2;
		notas[i].media = mediaAluno(notas[i].nota1, notas[i].nota2);
		printf("\n>> Valor do vetor[%d]\n Aluno: %s\n Nota1: %.2lf\n Nota2: %.2lf\n Média: %.2lf\n", i,notas[i].nome, notas[i].nota1, notas[i].nota2, notas[i].media);
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




