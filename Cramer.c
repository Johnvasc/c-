//Método de cramer por john vasc
#include <stdio.h>

float getdeterminanteparte(int n, int termo, float mat[n][n]);
float getdeterminanteRevparte(int n, int termo, float mat[][n]);
float determinanteDeCramer(int n, int index, float mat[][n], float re[n]);

int main(){
    int n, interador = 0;
    printf("insira o tamanho da matriz:\n");
    scanf("%d", &n); float mat[n][n], results[n];
    for(int i = 0; i<n; i++){
        printf("preencha a %d linha com seus coeficientes\n", i+1);
        for(int j = 0; j<n; j++){
            scanf("%f", &mat[i][j]);
        }
    }
    printf("informe a linha resultado do sistema\n");
    for(int i = 0; i<n; i++){
        scanf("%f", &results[i]);
    }
    float d = getdeterminanteparte(n, 0, mat);
    float dRev = getdeterminanteRevparte(n, 0, mat);
    float derterminante = d - dRev;
    float resultFinal;
    for(int i = 0; i<n; i++){
        resultFinal = (determinanteDeCramer(n, i, mat, results)/derterminante);
        printf("x%d: %f\n", i+1, resultFinal);
    }
}

float getdeterminanteparte(int n, int termo, float mat[][n]){
    int a = termo; float determ = 0;
    if(termo < n-1) determ += getdeterminanteparte(n, termo+1, mat);
    float soma = 1;
    for(int i = 0; i<n; i++){
        if(a >= n) a = 0;
        soma = soma * mat[i][a];
        a++;
    }
    return (soma+determ);
}
float getdeterminanteRevparte(int n, int termo, float mat[][n]){
    int a = termo; float determ = 0;
    if(termo < n-1) determ += getdeterminanteRevparte(n, termo+1, mat);
    float soma = 1;
    for(int i = 0; i<n; i++){
        if(a >= n) a = 0;
        soma = soma * mat[i][(n-1)-a];
        a++;
    }
    return (soma+determ);
}
float determinanteDeCramer(int n, int index, float mat[][n], float re[n]){
    float matCramer[n][n]; int a = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(j==index){
                matCramer[i][j] = re[a]; a++;
            }
            else matCramer[i][j] = mat[i][j];
        }
    }
    float res = getdeterminanteparte(n, 0, matCramer) - getdeterminanteRevparte(n, 0, matCramer);
    return res;
}
