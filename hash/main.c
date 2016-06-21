#include "tabelaHash.h"

int main(){
    Hash* ha = criaHash(1427);
    liberaHash(ha);   
    
    struct aluno al;
    int mat;
    
    int x = insereHash_SemColisao(ha, al);    
    //int y = buscaHash_SemColisao(ha, mat, &al); //erro
    
    return 0;
}
