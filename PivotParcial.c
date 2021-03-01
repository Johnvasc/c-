#include <stdio.h>
#include <math.h>

int main(){
/////////////////////////////Preenchimento da tabela///////////////////////////////////////////////////
    int Neq;
    printf("Insira o numero de equacoes\n");
    scanf("%d", &Neq);
    float tab[Neq][Neq+1], resps[Neq]; int block[Neq];
    for(int i = 0; i<Neq; i++){
        block[i] = -1;
        printf("preencha a %d linha com seus coefs e result:\n", i+1);
        for(int j = 0; j<Neq+1; j++){
            scanf("%f", &tab[i][j]);
        }
    }
    int k = 0;
    for(int i = 0; i<Neq; i++){
        int maior = 0; float cons = 0; 
        for(int j = 0; j<Neq; j++){
            int banned = 0;
            if(tab[j][i]>cons){
                for(int l = 0; l<Neq; l++){
                    if(block[l]==j) banned = 1;
                }
                if(banned==0){
                    maior = j; cons = tab[j][i]; k++;
                }
            }
        }
        block[k] = maior;
        for(int m = 0; m<Neq; m++){
            if(m==maior) continue;
            float divi = tab[m][i]/cons;
            for(int n = 0; n<=Neq; n++){
                tab[m][n] = tab[m][n] - divi*tab[maior][n];
            }
        }
    }
    printf("matriz ajustada:\n");
    for(int i = 0; i<Neq; i++){
        for(int j = 0; j<Neq; j++){
            printf("%fx%d ", tab[i][j], j+1);
        }
        printf("%f\n", tab[i][Neq]);
    }
}
