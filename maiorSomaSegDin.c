#include <stdio.h>
#include <limits.h>
#define TAM 5

//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o maiorSomaSegDin maiorSomaSegDin.c && maiorSomaSegDin

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int maiorSub(int arr[], int n){
    int sol[n];
    for(int i=0; i<n; i++) sol[i] = 1;  // Inicializa tudo com 1 pois eh o valor minimo
    int maior = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i])
                sol[i] = max(sol[i], sol[j] + 1);  // Coloca o anterior incrementado
            //no novo valor da direita do anterior (se for maior claro)
        }
        maior = max(maior, sol[i]);
    }

    //for(int i=0; i<n; i++) printf("%d ", sol[i]);
    return maior;
}


void main(){
    int arr[TAM] = {3, 10, 2, 1, 20};
    printf("\n%d", maiorSub(arr,TAM));
}