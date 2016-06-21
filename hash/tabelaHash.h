#ifndef __tabelaHash_h
#define __tabelaHash_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct aluno Aluno;
struct aluno{
    int matricula;
    char nome [30];
    float n1, n2, n3;
};

typedef struct hash Hash;
struct hash{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash *ha);
int chaveDivisao(int chave, int TABLE_SIZE);
int insereHash_SemColisao(Hash *ha, struct aluno al);
int buscaHash_SemColisao(Hash *ha, int mat, struct aluno *al);
#endif
