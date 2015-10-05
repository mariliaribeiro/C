#include <stdio.h>
#include <stdlib.h>
// prototipação
int defineQtdAlunos();
void escreveArquivo(FILE*, int);
void leArquivo(FILE*);
int somaNotas(double, double);
int mediaAluno(double, double);

int main(){
    FILE *arq; // ponteiro para arquivo
    int qtdAlunos;
       
    arq = fopen("teste.txt","w"); //abre arquivo
    qtdAlunos = defineQtdAlunos(); // define a quantidade de alunos (linhas) a serem escritos no arquivo
    escreveArquivo(arq, qtdAlunos); // escreve dados no arquivo
    fclose(arq); // fecha arquivo
    
    leArquivo(arq); // lê dados do arquivo
    

    return 0;
}

int defineQtdAlunos(){
    int qtd;

    printf("Informe quantos alunos você deseja calcular a média: ");
    scanf("%d", &qtd);

    return qtd;
}

void escreveArquivo(FILE * arq, int qtdAlunos){
    char aluno[50]="";
    double nota1= 0.0, nota2 = 0.0;
    int i;
    
    for(i = 0; i < qtdAlunos; i++){
        printf(" \n\n--- Informe ---\n");
        printf("Nome: ");
        scanf("%s", aluno);
        printf("Nota1: ");
        scanf("%lf", &nota1);
        printf("Nota2: ");
        scanf("%lf", &nota2);
        fprintf(arq,"%s %.2lf %.2lf\n", aluno, nota1, nota2);
    }
}

void leArquivo(FILE * arq){
    double nota1=0.0, nota2=0.0;
    double media;
    char aluno[50]="";
    
    arq=fopen("teste.txt","r");
    printf("\n--------------------- \n");
    while(!feof(arq)){ // equanto não for fim de arquivo
        fscanf(arq,"%s %lf %lf\n", aluno, &nota1, &nota2); // leia e pegue os dados
        media = mediaAluno(nota1, nota2); // calcula a média das notas
        printf("%s sua média é: %.2lf\n", aluno, media); //imprime média do aluno       
    }
    fclose(arq); // fecha arquivo
}

int somaNotas(double nota1, double nota2){
    return nota1 + nota2;
}

int mediaAluno(double nota1, double nota2){
    double soma;
    soma = somaNotas(nota1, nota2);
    return soma/2;
}




