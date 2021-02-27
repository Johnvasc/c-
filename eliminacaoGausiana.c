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
    float soma;
    for(int i=Neq-2; i>=0; i--){
        soma = 0;
        for(int j=(i+1); j<Neq; j++){    
            soma = soma + tab[i][j]*resps[j];
        }
        resps[i] = (tab[i][Neq] - soma)/tab[i][i];
    }

    printf("\nResultado: " );
    for(int i=0; i<Neq; i++){
        printf("\nX%d = %f\n", i+1, resps[i]);
    }
}
