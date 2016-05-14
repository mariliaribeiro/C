#include "vetorDefines.h"
#include "manipulacaoVetor.h"
#include "telasOperacoesVetor.h"

void popular(reg*);
int main() {
	reg* registros;
	registros = (reg*) malloc (sizeof(registros));
	registros->contador = 0;
	int op;
	do {
		op = menu();
		switch(op){
			case 1:
				__fpurge(stdin);
				telaInserir(registros);
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
				listar(registros);
				break;
			case 5:
				__fpurge(stdin);
				popular(registros);
				break;
		}		
	}while (op != 0);
	return 1;
}



void popular(reg* registros){
	int codigoErro = 0;
	__fpurge(stdin);
	codigoErro = inserir(registros, "Eduardo", 10.0, 10.0);
	mensagem(codigoErro, "Eduardo");
	codigoErro = inserir(registros, "Eduardo2", 9.0, 1.0);
	mensagem(codigoErro, "Eduardo2");
	codigoErro = inserir(registros, "Eduardo3", 11.0, 7.1);
	mensagem(codigoErro, "Eduardo3");
	codigoErro = inserir(registros, "Eduardo4", 8.0, 7.8);
	mensagem(codigoErro, "Eduardo4");
	codigoErro = inserir(registros, "Eduardo5", 7.0, 8.0);
	mensagem(codigoErro, "Eduardo5");
	codigoErro = inserir(registros, "Eduardo6", 9.5, 1.7);	
	mensagem(codigoErro, "Eduardo6");
	/* codigoErro = inserir(registros, 10.0, 10.0);
	mensagem(codigoErro, "Eduardo");
	codigoErro = inserir(registros, 9.0, 1.0);
	mensagem(codigoErro, "Eduardo2");
	codigoErro = inserir(registros, 11.0, 7.1);
	mensagem(codigoErro, "Eduardo3");
	codigoErro = inserir(registros, 8.0, 7.8);
	mensagem(codigoErro, "Eduardo4");
	codigoErro = inserir(registros, 7.0, 8.0);
	mensagem(codigoErro, "Eduardo5");
	codigoErro = inserir(registros, 9.5, 1.7);	
	mensagem(codigoErro, "Eduardo6"); */
	__fpurge(stdin);
	getchar();
}
