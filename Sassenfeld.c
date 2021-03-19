#include <stdio.h>
#include <math.h>

int main(){
    int Neq, converg = 0; float beta;
    printf("Insira o numero de equacoes\n");
    scanf("%d", &Neq);
    float tab[Neq][Neq], betas[Neq];
    for(int i = 0; i<Neq; i++){
        betas[i] = 0;
        printf("preencha a %d linha com seus coefs\n", i+1);
        for(int j = 0; j<Neq; j++){
            scanf("%f", &tab[i][j]);
        }
    }
    for(int i = 1; i<Neq; i++){
        betas[0] += fabs(tab[0][i]); 
    }
    betas[0] = betas[0]/tab[0][0];      beta = betas[0];
    if(betas[0] >= 1) converg = 1;
    if(betas[0] != 1){
        for(int i = 1; i<Neq; i++){
            for(int j = 0; j<Neq; j++){
                if(j<=i-1) betas[i] += fabs(tab[i][j])*betas[j];
                if(j>i) betas[i] += fabs(tab[i][j]);
            }
            betas[i] = betas[i]/tab[i][i];
            if(betas[i]>1){
                converg = 1;
                break;
            }
            if(betas[i]>beta) beta = betas[i];
        }    
    }
    if(converg==0) printf("Pelo criterio de sassenfeld, o metodo converge!\n");
    else printf("Pelo criterio de sassenfeld o metodo nao converge!");

    return 0;
}
