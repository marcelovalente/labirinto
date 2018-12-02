#include<stdlib.h>
#include<stdio.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include "Mapa.h"
#include "Coordenada.h"
#include "Pilha.h"

void lerArquivo(Mapa *mapa){
    //parametros
    char conteudo,nomeArquivo[20];
    int linha = 1,coluna = 0, flag=0;
    //abrindo arquivo
    printf("Digite o nome do arquivo: ");
    gets(nomeArquivo);
    FILE *arquivo;
    arquivo = fopen(nomeArquivo,"r");
    if(!arquivo){
        printf("\nArquivo incorreto, reinicie o programa\n\n");
        exit(1);
    }
    while((conteudo = fgetc(arquivo)) != EOF){
        if(conteudo=='#' && flag==0){
            flag = 1;
        }
        if(flag==1){
            if(conteudo == '\n')
                linha++;
            else
                coluna++;
        }
    }
    coluna = coluna / linha;
    mapa->dimensoesMapa.coluna = coluna;
    mapa->dimensoesMapa.linha = linha;
    //voltando pointer arquivo
    rewind(arquivo);
    //criarMapa
    int x=0,y=0;
    mapa->conteudo = (char**) malloc(linha * sizeof(char*));
    for(x=0;x<linha;x++){
        mapa->conteudo[x] = (char*) malloc(coluna * sizeof(char));
    }
    flag=0;
    //printf("%d %d\n",mapa->dimensoesMapa.linha,mapa->dimensoesMapa.coluna);
    for(x=0;x<linha;x++){
        for(y=0;y<coluna;y++){
            conteudo = fgetc(arquivo);
            if(conteudo=='#' && flag==0){
                //printf("%d - %d",x,y);exit(1);
                flag = 1;
                x=0;
                y=0;
            }
            if(flag==1){
                //printf("xuxa");
                if(conteudo != '\n'){
                    //printf("%c",conteudo);
                    mapa->conteudo[x][y] = conteudo;
                    if(conteudo == 'E'){
                        mapa->atual.linha = x;
                        mapa->atual.coluna = y;
                    }
                }
                else{
                   y--;
                }
            }
        }
        //printf("\n");
    }
    //fechar arquivo
    fclose(arquivo);
}
/*void criarMapa(Mapa *mapa){
    //FILE* arquivo;
    //char conteudo;
    int x=0,y=0,linha,coluna;
    linha =  mapa->dimensoesMapa.linha;
    coluna = mapa->dimensoesMapa.coluna;
    mapa->conteudo = (char**) malloc(linha * sizeof(char*));
    for(x=0;x<linha;x++){
        mapa->conteudo[x] = (char*) malloc(coluna * sizeof(char));
    }
    arquivo = fopen("labirinto.txt","r");
    x=0;
    printf("%d %d\n",mapa->dimensoesMapa.linha,mapa->dimensoesMapa.coluna);

    for(x=0;x<mapa->dimensoesMapa.linha;x++){
        for(y=0;y<mapa->dimensoesMapa.coluna;y++){
            conteudo = fgetc(arquivo);
            if(conteudo != '\n'){
                printf("%c",conteudo);
                mapa->conteudo[x][y] = conteudo;
                if(conteudo == 'E'){
                    mapa->atual.linha = x;
                    mapa->atual.coluna = y;
                }
            }
            else{
               y--;
            }
        }
        printf("\n");
    }
    fclose(arquivo);
}*/
int verificarConteudo(int x,int y,Mapa *mapa){
    if(mapa->conteudo[x][y] == '.'){
        mapa->conteudo[x][y] = '*';
        return 1;
    }
    else if(mapa->conteudo[x][y] == 'S'){
        printf("\nSaiu");
        exit(1);
    }
    return 0;
}
void andar(Mapa *mapa,Pilha *pilha){
    int cima = (mapa->atual.linha)-1;
    int baixo = (mapa->atual.linha)+1;
    int esquerda = (mapa->atual.coluna)-1;
    int direita = (mapa->atual.coluna)+1;
    int desempilhar = 1;
    if(cima >= 0 || baixo < mapa->dimensoesMapa.linha){
        if(verificarConteudo(cima,mapa->atual.coluna,mapa)){
            desempilhar = 0;
            mapa->atual.linha = cima;
            push(pilha,mapa->atual);
        }
        if(verificarConteudo(baixo,mapa->atual.coluna,mapa) && desempilhar == 1){
            desempilhar = 0;
            mapa->atual.linha = baixo;
            push(pilha,mapa->atual);
        }
    }
    if((esquerda >= 0 || direita < mapa->dimensoesMapa.coluna) && desempilhar == 1){
        if(verificarConteudo(mapa->atual.linha,esquerda,mapa)){
            desempilhar = 0;
            mapa->atual.coluna = esquerda;
            push(pilha,mapa->atual);
        }
        if(verificarConteudo(mapa->atual.linha,direita,mapa) && desempilhar == 1){
            desempilhar = 0;
            mapa->atual.coluna = direita;
            push(pilha,mapa->atual);
        }
    }
    if(desempilhar == 1){
        mapa->conteudo[mapa->atual.linha][mapa->atual.coluna] = '-';
        mapa->atual = pop(pilha);
    }
    imprimirMapa(mapa);
}
void imprimirMapa(Mapa *mapa){
    int x,y;
    system("cls");
    for(x=0;x<mapa->dimensoesMapa.linha;x++){
        for(y=0;y<mapa->dimensoesMapa.coluna;y++){
            if(mapa->conteudo[x][y]=='*'){
                SetColor(14);
            }
            printf("%c",mapa->conteudo[x][y]);
            SetColor(0);
        }
        printf("\n");
    }
    Sleep(50);
}
void SetColor(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
