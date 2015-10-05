#include <stdio.h>
#include <stdlib.h>

int defineTamanhoVetor();
int *criaPonteiroVetor(int tam);
void informaValoresParaVetor(int *vetor, int tam);
void imprimeInformacoes(int *vetor, int tam);
int somaValoresVetor(int *vetor, int tam);
void mediaValoresVetor(int soma, int tam);

int main(){
    int tam;
    int *vetor;
    int soma = 0;

    tam = defineTamanhoVetor();
    vetor = criaPonteiroVetor(tam);
    informaValoresParaVetor(vetor, tam);
    imprimeInformacoes(vetor, tam);    
    
    
    soma = somaValoresVetor(vetor, tam);
    mediaValoresVetor(soma, tam);

    return 0;
}

int defineTamanhoVetor(){
    int tam;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);

    return tam;
}

int *criaPonteiroVetor(int tam){
    int *vetor;

    vetor = (int *) malloc(tam * sizeof(int));

    return vetor;
}

void informaValoresParaVetor(int *vetor, int tam){
        int i;

    for(i = 0; i < tam; i++){
        printf("Informe um valor para o vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }
}

void imprimeInformacoes(int *vetor, int tam){
    int i;

    printf("\n---------------------\n");
    for(i = 0; i < tam; i++){
        printf("Endereço de memória do vetor[%d]: %p\n", i, (void*) &vetor[i]);
        printf("Valor do vetor[%d]: %d\n", i,vetor[i]);
    }
}

int somaValoresVetor(int *vetor, int tam){
    int soma = 0;
    int i;

    printf("\n---------------------\n");
    for (i = 0; i < tam; i++){
        soma += vetor[i];
    }

    return soma;
}

void mediaValoresVetor(int soma, int tam){
//int mediaValoresVetor(int soma, int tam){
    int media = 0;

    media = soma/tam;
    printf("A média dos valores do vetor é: %d\n", media);

    //return media;
}
