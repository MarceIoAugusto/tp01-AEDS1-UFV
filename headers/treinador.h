#ifndef TREINADOR_H
#define TREINADOR_H

#include "pokelista.h"

typedef struct {
    int id;
    char nome[50];
    double pos[2];
    PokeLista pokelista;
    int pokebolas;
}   TipoTreinador;

void inicializa(FILE * entrada,TipoTreinador *treinador);
void movimentacao(TipoPokemon *pokemon,TipoTreinador *treinador, int alvo);

//Funçoes para receber os dados do Treinador
int getTreinadorPos(TipoTreinador *treinador, double pos[2]);
int getTreinadorID(TipoTreinador *treinador, int ID); 

//Funçoes para alterar os dados do Treinador
int setTreinadorPos(TipoTreinador *treinador, double pos[2]);





#endif