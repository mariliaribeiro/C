#include <stdio.h>
# include <stdlib.h>
# include <time.h>

/*
 * Esse código deve ser capaz de:
 * -> Calcular o tempo de execussão dos algoritmos de ordenação
 * -> Calcular a quantidade de comparações
 * -> Calcular as movimentações
 * -> Calcular iterações
*/

void insert(int v[], int tamanho);
void insert_for_shell(int v[], int tamanho);
void shell(int v[], int tamanho);
void printVetor(int v[], int tamanho);

int main(int argc, char* argv[]){
    //time_t inicio, fim; //para comparar o tempo de execussão do algoritmo
    
    clock_t tempo_insert, tempo_shell;
    printf("----- Insert Sort ---------\n");
    tempo_insert = clock();
    int v[] = {5, 3, 8, 2, 9, 1, 6, 10, 0, 4, 7}; //caso aleatório
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //melhor caso
    int v[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; //pior caso
    int tamanho = (int)(sizeof(v)/sizeof(int));     
    insert(v, tamanho);
    printVetor(v, tamanho);
    printf("\nTempo de execussão (segundos):%f\n\n",(clock() - tempo_insert)/(double)CLOCKS_PER_SEC);
   
    
	
    printf("----- Shell Sort ---------\n");
    tempo_shell = clock();
    int ve[] = {5, 3, 8, 2, 9, 1, 6, 10, 0, 4, 7}; //caso aleatório
    //int ve[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //melhor caso
    //int ve[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; //pior caso
    int t = (int)(sizeof(ve)/sizeof(int));     
    shell(ve, t);
    printVetor(ve, t);
    printf("\nTempo de execussão (segundos):%f\n\n",(clock() - tempo_shell)/(double)CLOCKS_PER_SEC);
	return 0;
}

void insert(int v[], int tamanho){
    int aux, i_aux;
    int i, j;
    int comparacoes = 0;
    int iteracoes = 0;
    int movimentacoes = 0;
    
    for (i = 1; i < tamanho; i++){
        for(j = 0; j < i; j++){
            if(v[i] < v[j]){
                aux = v[i];
                i_aux = i;
                v[i_aux] = v[j];
                if(i_aux >= j){
                    v[j] = aux;
                }
                movimentacoes += 1;
            }
            comparacoes += 1;
        }
        iteracoes += 1;
    }
    printf("Comparações: %d \nIterações: %d \nMovimentações: %d \n", comparacoes, iteracoes, movimentacoes);
}

void insert_for_shell(int v[], int tamanho){
    int i, j, h =1;
    int aux;
    
    for(i = h; i < tamanho; i ++){
        aux = v[i];
        j = i;
        
        // efetua comparações entre elementos com distância h
        while (v[j-h] > aux){
            v[j] = v[j -h];
            j -= h;
            if(j < h);
                break;
        }
        v[j] = aux;            
    }
}

void shell(int v[], int tamanho){
    int h;
    
    do{
        h = h * 3 + 1; //calcula h inicial
    }while (h < tamanho);
    
    do{
        h = (h - 1) / 3; // atualiza o valor de h
        //printf("\n h atualizado: %d\n", h);
        //printVetor(v, tamanho);
        //printf("\n");
        insert_for_shell(v, tamanho);
        //printf("-- depois da troca\n");
        //printVetor(v, tamanho);
        //printf("\n");        
    }while(h > 0);
    
    insert(v, tamanho);
}

void printVetor(int v[], int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    }    
}
