#ifndef __vetorDefines_h
#define __vetorDefines_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char nome[50];
	float nota[2];
	float media;
} info;

typedef struct{
	int contador;
	info alunos[100];
} reg;

#endif
