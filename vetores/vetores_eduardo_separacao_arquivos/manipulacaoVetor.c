#include "manipulacaoVetor.h"

int inserir(reg* registros, char nome[50], float nota0, float nota1) {
	int c = registros->contador;
	__fpurge(stdin);
	printf("Recebidos os valores %d -> %s - %.2f - %.2f", c, nome, nota0, nota1);
	getchar();
	if ((nota0 >= 0.0 && nota0 <= 10.0)  && (nota1 >= 0.0 && nota1 <= 10.0)) {
		strcpy(registros->alunos[c].nome, nome);
		registros->alunos[c].nota[0] = nota0;
		registros->alunos[c].nota[1] = nota1;
		registros->alunos[c].media = (nota0 + nota1) / 2.0;
		registros->contador++;
		printf("\n\nDeu Certo.");
		printf("%s - %.2f - %.2f", nome, nota0, nota1);
		getchar();
		return 1;
	} else {
		printf("\n\n aqui.");
		printf("%s - %.2f - %.2f", nome, nota0, nota1);
		getchar();
		return 0;
	}
	return 2;
}