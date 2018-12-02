#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include "Coordenada.h"
#include "Pilha.h"

typedef struct{
    char **conteudo;
    Coordenada atual;
    Coordenada dimensoesMapa;
}Mapa;
extern void lerArquivo(Mapa *mapa);
extern void criarMapa(Mapa *mapa);
//extern void gravarArquivo(Mapa mapa);
extern void andar(Mapa *mapa, Pilha *pilha);
extern int verificarConteudo(int x,int y,Mapa *mapa);
extern void imprimirMapa(Mapa *mapa);
extern void SetColor(int ForgC);
#endif // MAPA_H_INCLUDED
