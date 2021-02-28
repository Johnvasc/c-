#include <stdio.h>
#include <math.h>

int main(){
/////////////////////////////Preenchimento da tabela///////////////////////////////////////////////////
    int Neq;
    printf("Insira o numero de equacoes\n");
    scanf("%d", &Neq);
    float tab[Neq][Neq+1], resps[Neq];
    for(int i = 0; i<Neq; i++){
        printf("preencha a %d linha com seus coefs e result:\n", i+1);
        for(int j = 0; j<Neq+1; j++){
            scanf("%f", &tab[i][j]);
        }
    }
///////////////////////Eliminacao de gauss/////////////////////////////////////////////////////////////
    float fator;
    for(int k = 0; k<Neq-1; k++){
        for(int i = (k+1); i<Neq; i++){
            fator = tab[i][k] / tab[k][k];
            for(int j=0; j<=Neq; j++){
                tab[i][j] = tab[i][j] - fator*tab[k][j];
            }
        }
    }
    
////////////////////////Representacao parcial da tabela/////////////////////////////////////////////////////
    for(int i = 0; i<Neq; i++){
        for(int j = 0; j<Neq; j++){
            printf("%fx%d ", tab[i][j], j+1);
        }
        printf("%f\n", tab[i][Neq]);
    }
    
//////////////Determinacao do vetor com as repostas/////////////////////////////////////////////////////////
    resps[Neq-1] = tab[Neq-1][Neq] / tab[Neq-1][Neq-1];
    float divisor; int controle;
    for(int i = 0; i<Neq; i++){
        controle = 0;
        for(int j = 0; j<Neq+1; j++){
            if(tab[i][j]!=0 && controle==0){
                controle = 1;
                divisor = tab[i][j];
            }
            if(controle==1) tab[i][j]=(tab[i][j]/divisor);
        }
    }
    float divisao;
    for(int i = Neq-1; i>0; i--){
        for(int j = i-1; j>-1; j--){
            divisao = (tab[j][i]/tab[i][i]);
            tab[j][i] = 0; tab[j][Neq] = tab[j][Neq]-divisao*tab[i][Neq];
        }
    }
    printf("matriz de gauss-jordan:\n");
    for(int i = 0; i<Neq; i++){
        for(int j = 0; j<Neq; j++){
            printf("%fx%d ", tab[i][j], j+1);
        }
        printf("%f\n", tab[i][Neq]);
    }
}
