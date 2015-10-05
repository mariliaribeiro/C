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

int menu();
void telaInserir(reg*);
int inserir(reg*, char nome[50], float nota1, float nota2);
void listar(reg*);
void popular(reg*);
void mensagem(int codigoErro, char* nome);

int main() {
	reg registros;
	registros.contador = 0;
	int op;
	do {
		op = menu();
		switch(op){
			case 1:
				//__fpurge(stdin);
				telaInserir(&registros);
				break;
			case 2:
				system("clear");
				printf("Mostrar algo R");
				__fpurge(stdin);
				getchar();
				break;
			case 3:			
				system("clear");
				printf("Mostrar algo B");
				__fpurge(stdin);
				getchar();
				break;
			case 4:
				__fpurge(stdin);
				listar(&registros);
				break;
            case 5:
                //__furge(stdin);
                popular(&registros);
                break;
		}	
	}while (op != 0);
	return 1;
}

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
    float nota1, nota2;
    
	system("clear");
	printf("\n\nInforme nome: ");
	scanf("%s", nome);
	printf("Informe a nota 1: ");
	scanf("%f", &nota1);
	printf("Informe a nota 2: ");
	scanf("%f", &nota2);

    inserir(registros, nome, nota1, nota2);
    
	__fpurge(stdin);
	getchar();
}

int inserir(reg*registros, char nome[50], float nota1, float nota2){
    int c = registros->contador;

    if((nota1 >=0 && nota1 <= 10.0) && (nota2 >=0 && nota2 <= 10.0)){
        strcpy(registros->alunos[c].nome,nome);
        registros->alunos[c].nota[0] = nota1;
        registros->alunos[c].nota[1] = nota2;
        registros->alunos[c].media = (nota1 + nota2)/2;
        registros->contador++;
        return 1;
    }else{
        return 0;
    }
	

    
}
void mensagem(int codigoErro, char* nome){
    if(codigoErro == 1){
        printf("%s inserido com sucesso!\n", nome);
    }else{
        printf("Erro ao inserir %s!\n", nome);
    }
}

void popular(reg* registros){
    int codigoErro;
     
    codigoErro = inserir(registros, "Marilia", 1.0, 9.9);
    mensagem(codigoErro, "Marilia");   
    codigoErro = inserir(registros, "Marilia2", 2.0, 9.9);
    mensagem(codigoErro, "Marilia2");
    codigoErro = inserir(registros, "Marilia3", 3.0, 9.9);
    mensagem(codigoErro, "Marilia3");
    codigoErro = inserir(registros, "Marilia4", 4.0, 9.9);
    mensagem(codigoErro, "Marilia4");
    codigoErro = inserir(registros, "Marilia5", 5.0, 9.9);
    mensagem(codigoErro, "Marilia5");
    codigoErro = inserir(registros, "Marilia6", 6.0, 9.9);
    mensagem(codigoErro, "Marilia6");

}


void listar(reg* registros) {
	int i;
	system("clear");
	printf("\n\n\n======== LISTAGEM DE ALUNOS =============\n");
	printf("\n Nome \t Nota 1 \t Nota 2 \t Média\n\n");
	for (i = 0; i < registros->contador; i++) {
		printf("Aluno %d:\n", i);
		printf("\t %s \t %.2f  \t %.2f \t %.2f\n", registros->alunos[i].nome,registros->alunos[i].nota[0], registros->alunos[i].nota[1], registros->alunos[i].media);
	}
	__fpurge(stdin);
	getchar();
}
