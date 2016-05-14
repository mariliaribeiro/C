#include "telasOperacoesVetor.h"

int menu(void) {
	int op;
	do {
		system("clear");
		printf("===============MENU=================\n");
		printf("=\t 1 - Inserir\n");
		printf("=\t 2 - Remover\n");
		printf("=\t 3 - Buscar\n");
		printf("=\t 4 - Listar\n");
		printf("=\t 5 - Popular\n");
		printf("=\n=\t 0 - Sair\n");
		printf("\n\n\t Informe opção: ");
		scanf("%d", &op);
	} while ((op < 0) || (op > 5));
	return op;	
}

void telaInserir(reg* registros) {
	char nome[50];
	float nota[2];
	system("clear");
	printf("\n\nInforme nome: ");
	scanf("%s", nome);
	printf("Informe a nota 1: ");
	scanf("%f", &nota[0]);
	printf("Informe a nota 2: ");
	scanf("%f", &nota[1]);
	inserir(registros, nome, nota[0], nota[1]);
	__fpurge(stdin);
	getchar();
}

void listar(reg* registros) {
	int i;
	system("clear");
	printf("\n\n\n======== LISTAGEM DE ALUNOS =============\n");
	printf("\n \t Nome \t Nota 1 \t Nota 2 \t Média\n\n");
	for (i = 0; i < registros->contador; i++) {
		printf("Aluno %d:\n", i);
		printf("\t %s \t %.2f  \t %.2f \t %.2f\n", registros->alunos[i].nome,registros->alunos[i].nota[0], registros->alunos[i].nota[1], registros->alunos[i].media);
	}
	__fpurge(stdin);
	getchar();
}

void mensagem(int codigoErro, char* nome) {
	if (codigoErro == 1) {
		printf("%s inserido com sucesso\n", nome);
	} else if (codigoErro == 2) {
		printf("E agora??\n");
	} else {
		printf("Erro ao inserir %s\n", nome);
	}
}
