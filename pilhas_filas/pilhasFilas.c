#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criando a struct
typedef struct{
    char nome[50];
    double nota1, nota2, media; 
}NOTAS;

typedef struct{
	int contador;
	NOTAS notas[100];
} reg;


// prototipação
int menu();
void empilhar(reg* registros);
void desempilhar(reg* registros);
void enfileirar(reg* registros);
void desenfileirar(reg* registros);
void printRegistros(reg* registros);

double somaNotas(double, double);
double mediaAluno(double, double);


int main() {
    reg registros;
	registros.contador = 0;
	int op;
      
   	do {
		op = menu();
		switch(op){
			case 1:
                __fpurge(stdin);
				empilhar(&registros);
				break;
			case 2:
                __fpurge(stdin);
                desempilhar(&registros);
				break;
			case 3:	
                __fpurge(stdin);
                enfileirar(&registros);
				break;
			case 4:
                __fpurge(stdin);
                desenfileirar(&registros);
				break;
		}		
	}while (op != 0);
	return 1;
}

int menu(void) {
	int op;
	do {
		system("clear");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Enfileirar\n");
		printf("4 - Desenfileirar\n");
		printf("0 - Sair\n");
		printf("\n\nInforme opção: ");
		scanf("%d", &op);
	} while ((op < 0) || (op > 4));
	return op;	
}


void empilhar(reg* registros){
    system("clear");
    
    int topo;
    topo = registros->contador;
    
    
    printf("Nome: ");
    scanf("%s", registros->notas[topo].nome);
    
    printf("Nota1: ");
    scanf("%lf", &registros->notas[topo].nota1);
    
    printf("Nota2: ");
    scanf("%lf", &registros->notas[topo].nota2);
    
    registros->notas[topo].media = mediaAluno(registros->notas[topo].nota1, registros->notas[topo].nota2);
	
    printRegistros(registros);
    
    registros->contador++;
        
    __fpurge(stdin);
	getchar();
}

void desempilhar(reg* registros){
    system("clear");
    
    int  topo;
    topo = registros->contador-1;
    
    printf("\nRemovendo ...\n>> Valor do vetor[%d]\n Aluno: %s\n Nota1: %.2lf\n Nota2: %.2lf\n Média: %.2lf\n------\n", 
    topo, registros->notas[topo].nome, registros->notas[topo].nota1, registros->notas[topo].nota2, registros->notas[topo].media);
    registros->contador--;
    
    printRegistros(registros);
        
    __fpurge(stdin);
	getchar();
}

void enfileirar(reg* registros){
    system("clear");
    
    int fim;
    fim = registros->contador;    
    
    printf("Nome: ");
    scanf("%s", registros->notas[fim].nome);
    
    printf("Nota1: ");
    scanf("%lf", &registros->notas[fim].nota1);
    
    printf("Nota2: ");
    scanf("%lf", &registros->notas[fim].nota2);
    
    registros->notas[fim].media = mediaAluno(registros->notas[fim].nota1, registros->notas[fim].nota2);
	
   
    
    registros->contador++;
    
     printRegistros(registros);

    __fpurge(stdin);
	getchar();
}
    
void desenfileirar(reg* registros){
    system("clear");
    
    int  inicio, i;
    inicio = 0;
    
    printf("\nSaindo da fila ...\n>> Valor do vetor[%d]\n Aluno: %s\n Nota1: %.2lf\n Nota2: %.2lf\n Média: %.2lf\n------\n", 
    inicio, registros->notas[inicio].nome, registros->notas[inicio].nota1, registros->notas[inicio].nota2, registros->notas[inicio].media);
    registros->contador--;
    
    for (i = 0; i < registros->contador; i++) {
        registros->notas[i] = registros->notas[i+1];

        printRegistros(registros);
    }       
    __fpurge(stdin);
	getchar();
}

void printRegistros(reg* registros){
	int i;
	for (i = 0; i < registros->contador; i++) {
        printf("\n>> Valor do vetor[%d]\n Aluno: %s\n Nota1: %.2lf\n Nota2: %.2lf\n Média: %.2lf\n", 
        i, registros->notas[i].nome, registros->notas[i].nota1, registros->notas[i].nota2, registros->notas[i].media);
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
