#include <stdio.h>
#include <limits.h>
#define TAM 3

typedef struct it{
    int valor;
    float peso;
} item;

//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o mochilaFrac mochilaFrac.c && mochilaFrac


void mochila(item listaItem[], int n, int capac){
    float quants[n];
    for(int i=0; i<n; i++) quants[i] = 0.0;

    int j = 0;
    for(int i=0; i<n; i++){
        if(listaItem[i].peso < capac){
            capac -= listaItem[i].peso;
            quants[j] = listaItem[i].peso;
            j++;
        } else
            quants[j] = capac/listaItem[i].peso;
    }

    for(int i=0; i<n; i++) printf("%.2f ", quants[i]);
}


void main(){
    item it1; it1.valor = 60; it1.peso =  10.0;
    item it2; it2.valor = 100; it2.peso = 20.0;
    item it3; it3.valor = 120; it3.peso = 30.0;
    item listaItem[TAM];
    // Ordene baseado na relacao preco/peso do maior para o menor
    listaItem[0] = it1;
    listaItem[1] = it2;
    listaItem[2] = it3;
    mochila(listaItem, TAM, 50);
}