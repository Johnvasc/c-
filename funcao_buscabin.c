#include <math.h>
#include <stdio.h>

int main()
{
    // Achar a raiz da funcoes f(x)=5x^3-5x^2+6x-2
    // X inferior, X posterior, Xmiddle, F(xAnterior), F(xPosterior), F(xMiddle)
    float Xinf, Xpos, Xmid, Fxa, Fxp, Fxm, erro, XmAnt = 1;
    int interacoes = 1; float tol = 0.00001;
    Xinf = 0; Xpos = 1; Xmid = (float)((Xinf+Xpos)/2);
    Fxa = (5*pow(Xinf, 3) - 5*pow(Xinf, 2) + 6*Xinf - 2);
    Fxp = (5*pow(Xpos, 3) - 5*pow(Xpos, 2) + 6*Xpos - 2);
    Fxm = (5*pow(Xmid, 3) - 5*pow(Xmid, 2) + 6*Xmid - 2);
    do{
        interacoes++; XmAnt = Xmid;
        if(Fxa*Fxm>=0){
            Xinf = Xmid;
            Fxa = Fxm;
        }else{
            Xpos = Xmid;
            Fxp = Fxm;
        }
        Xmid = (float)((Xinf+Xpos)/2);
        Fxm = (5*pow(Xmid,3) - 5*pow(Xmid,2) + 6*Xmid - 2);
        erro = fabs((float)((Xmid-XmAnt)/Xmid));
        printf("%f %f %f %f %f %f %f\n",Xinf,Xpos,Xmid,Fxa,Fxp,Fxm,erro);
    }while(erro>=tol);
    printf("Valor estimado, com %d iteracoes da raiz: %f",interacoes, Xmid);
    return 0;
}
