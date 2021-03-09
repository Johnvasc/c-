//Acha a determinante por john vasc
#include <stdio.h>

float getdeterminanteparte(int n, int termo, float mat[n][n]);
float getdeterminanteRevparte(int n, int termo, float mat[][n]);

int main(){
    int n, interador = 0;
    printf("insira o tamanho da matriz:\n");
    scanf("%d", &n); float mat[n][n];
    for(int i = 0; i<n; i++){
        printf("preencha a %d linha com seus coeficientes\n", i+1);
        for(int j = 0; j<n; j++){
            scanf("%f", &mat[i][j]);
        }
    }
    float determ = getdeterminanteparte(n, 0, mat);
    float determRev = getdeterminanteRevparte(n, 0, mat);
    printf("Sentido esquerda -> direita: %f\n", determ);
    printf("Sentido direita -> esquerda: %f\n", determRev);
    printf("Determinante: %f", determ - determRev);
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
