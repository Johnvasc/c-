#include <stdio.h>
#include <math.h>

int main(){
/////////////////////////////Preenchimento da tabela///////////////////////////////////////////////////
    int Neq;
    printf("Insira o numero de equacoes\n");
    scanf("%d", &Neq);
    float tab[Neq][Neq+1], L[Neq][Neq+1], y[Neq], resps[Neq];
    for(int i = 0; i<Neq; i++){
        printf("preencha a %d linha com seus coefs e result:\n", i+1);
        for(int j = 0; j<Neq+1; j++){
            scanf("%f", &tab[i][j]);
            if(i==j) L[i][j] = 1;
            else if(j==Neq) L[i][j] = tab[i][j];
            else L[i][j] = 0;
        }
    }

///////////////////////Eliminacao de gauss/////////////////////////////////////////////////////////////
    float fator; int m = 0;
    for(int k = 0; k<Neq-1; k++){
        for(int i = (k+1); i<Neq; i++){
            fator = tab[i][k] / tab[k][k];
            y[m] = fator; m++;
            for(int j=0; j<=Neq; j++){
                tab[i][j] = tab[i][j] - fator*tab[k][j];
            }
        }
    }

////////////////////////Preenchendo a tabela L/////////////////////////////////////////////////////
    int o = m;
    for(int i = 1; i<Neq; i++){
        for(int j = 0; j<i; j++){
            L[i][j] = y[o-m];
            m--;
        }
    }
/////////////////////////Representacao da tabela L////////////////////////////////////////////////
    printf("tabela L:\n");
    for(int i = 0; i<Neq; i++){
        for(int j = 0; j<Neq; j++){
            printf("%fy%d ", L[i][j], j+1);
        }
        printf("%f\n", L[i][Neq]);
    }
//////////////Determinacao do vetor y com as repostas para L/////////////////////////////////////////////////////////
    y[0] = L[0][Neq];
    float soma;
    for(int i = 1; i<Neq; i++){
        soma = 0; int n = 0;
        for(int j = 0; j<=Neq; j++){
            soma = soma + L[i][j]*y[j];
        }
        y[i] = (L[i][Neq] - soma);
    }
    printf("Resultado do y: " );
    for(int i = 0; i<Neq; i++){
        printf("\ny%d = %f", i+1, y[i]);
    }
    for(int i = 0; i<Neq; i++){
        tab[i][Neq] = y[i];
    }
///////////////////Representacao da tabela U/////////////////////////////////////////////////////////////////
    printf("\nTabela U:\n");
    for(int i = 0; i<Neq; i++){
        for(int j = 0; j<Neq; j++){
            printf("%fx%d ", tab[i][j], j+1);
        }
        printf("%f\n", tab[i][Neq]);
    }
///////////////////Determinacao da resp final///////////////////////////////////////////////////////////////////////////////
    resps[Neq-1] = tab[Neq-1][Neq] / tab[Neq-1][Neq-1];

    for(int i=Neq-2; i>=0; i--){
        soma = 0;
        for(int j=(i+1); j<Neq; j++){    
            soma = soma + tab[i][j]*resps[j];
        }
        resps[i] = (tab[i][Neq] - soma)/tab[i][i];
    }
    printf("Resultado do x:" );
    for(int i=0; i<Neq; i++){
        printf("\nx%d = %f", i+1, resps[i]);
    }
}
