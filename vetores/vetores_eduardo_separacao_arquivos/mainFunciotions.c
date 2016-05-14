#include<stdio.h>

int check_main(int argc, char* prog){
	if (argc != 2) {
		printf("Erro de sintaxe: %s NOME_ARQUIVO\n", prog);
		return 1;
	}
	return 0;
}
