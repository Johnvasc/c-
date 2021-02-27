#include <stdio.h>
#include <math.h>
#define ERROR 0.001

int main (){
    int Neq, i, j;
    printf("Insira o numero de equacoes:\n");
    scanf("%d", &Neq);
    float tab[Neq][Neq], resul[Neq], chute[Neq], xAnt[Neq], fim[Neq];
    for(int i = 0; i<Neq; i++){
        printf("preencha a %d linha com seus coefs:\n", i+1);
        for(int j = 0; j<Neq; j++){
            scanf("%f", &tab[i][j]);
        }
    }
    for(int i = 0; i<Neq; i++){
        printf("Insira a reposta para a linha n%d do sistema:\n", i+1);
        scanf("%f", &resul[i]);
    }
    for(int i = 0; i<Neq; i++){
        printf("Insira o valor n%d do chute inicial:\n", i+1);
        scanf("%f", &chute[i]); xAnt[i] = 0; fim[Neq] = 0;
    }

    int erro = 0, tentativas = 0;
    do{
        for(i = 0; i < Neq; i++){
            float s = 0;
            for (j = 0; j < Neq; j++) {
                if (j != i)
                    s = s + tab[i][j]*chute[j];
            }
            chute[i] = ((resul[i] - s)/ tab[i][i]);
        }
        //criterio da convergencia
        for (i = 0; i<Neq; i++){
            fim[i] = (fabs((chute[i]- xAnt[i]) / chute[i])) * 100;
            if (fim[i] >= ERROR){
                erro = 1;
            }else{
                erro = 0;
            }
            xAnt[i] = chute[i];
        }
        printf("tentativa n:%d\n", tentativas+1);
        for (i = 0; i <Neq; i++){
           printf("1%i = %f\t |Er| = %f\n",i+1, chute[i], fim[i]);
        }tentativas++;
    } while (erro != 0);
}
