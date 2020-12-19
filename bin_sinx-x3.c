#include <math.h>
#include <stdio.h>

int main()
{
    // X inferior, X posterior, Xmiddle, F(xAnterior), F(xPosterior), F(xMiddle)
    float Xinf, Xpos, Xmid, Fxa, Fxp, Fxm, erro, y, XmAnt = 1;
    int interacoes = 1; float tol = 0.02;
    Xinf = 0.5; Xpos = 1; Xmid = (float)((Xinf+Xpos)/2);
    Fxa = (sin(Xinf) - pow(Xinf, 3));
    Fxp = (sin(Xpos) - pow(Xpos, 3));
    Fxm = (sin(Xmid) - pow(Xmid, 3));
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
        Fxm = (sin(Xmid) - pow(Xmid, 3));
        erro = fabs((float)((Xmid-XmAnt)/Xmid));
        printf("%f %f %f %f %f %f %f\n",Xinf,Xpos,Xmid,Fxa,Fxp,Fxm,erro);
    }while(erro>=tol);
    printf("Valor estimado, com %d iteracoes da raiz: %f",interacoes, Xmid);
    return 0;
}
