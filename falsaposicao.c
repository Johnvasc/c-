#include <stdio.h>
#include <math.h>

int main()
{
    float Xinf, Xsup, Xmid, Xant, Finf, Fsup, Fmid, erro, tolerancia = 0.002;
    int interacoes = 0;
    Xinf = 0.5; Xsup = 1; Xmid = (Xinf+Xsup)/2;
    Finf = (0.7*pow(Xinf, 5) - 8*pow(Xinf, 4) + 44*pow(Xinf, 3) - 90*pow(Xinf, 2) + 82*Xinf - 25);
    Fsup = (0.7*pow(Xsup, 5) - 8*pow(Xsup, 4) + 44*pow(Xsup, 3) - 90*pow(Xsup, 2) + 82*Xsup - 25);
    Fmid = (0.7*pow(Xmid, 5) - 8*pow(Xmid, 4) + 44*pow(Xmid, 3) - 90*pow(Xmid, 2) + 82*Xmid - 25);
    do{
        Xant = Xmid; interacoes++;
        if(Finf*Fmid>0){
            Xinf = Xmid; Finf = Fmid;
        }else{
            Xsup = Xmid; Fsup = Fmid;
        }
        Xmid = Xsup - ((Fsup*(Xinf-Xsup))/(Finf-Fsup));
        Fmid = (0.7*pow(Xmid, 5) - 8*pow(Xmid, 4) + 44*pow(Xmid, 3) - 90*pow(Xmid, 2) + 82*Xmid - 25);
        erro = fabs((float)((Xmid-Xant)/Xmid));
        printf("%f %f %f %f %f %f %f\n",Xinf, Xsup, Xmid, Finf, Xsup, Fmid, erro);
    }while(erro>tolerancia);
    printf("numero de interacoes: %d\n", interacoes);
    printf("raiz estimada: %f", Xmid);

    return 0;
}
