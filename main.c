#include <stdio.h>
#include <stdlib.h>
#include "Mapa.h"
#include "Coordenada.h"
#include "Pilha.h"
int main(){
    system("COLOR 70");
    Mapa mapa;
    Pilha* pilha;
    pilha = (Pilha*)malloc(sizeof(Pilha));
    lerArquivo(&mapa);
    //criarMapa(&mapa);
    int capacidade = (mapa.dimensoesMapa.linha * mapa.dimensoesMapa.coluna) / 2;
    newStack(capacidade,pilha);
//    printf("%d %d",mapa.atual.linha,mapa.atual.coluna);

    while(mapa.conteudo[mapa.atual.linha][mapa.atual.coluna] != 'S'){
        andar(&mapa,pilha);
    }
    return 1;
}
