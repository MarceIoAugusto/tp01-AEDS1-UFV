#ifndef TREINADOR_H
#define TREINADOR_H

#include "pokelista.h"
#include "cabecalho.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nome[50];
    double pos[2];
    PokeLista pokelista;
    int pokebolas;
} TipoTreinador;

void inicializaTreinador(TipoTreinador *treinador, int ID, char *nomeTemp, int pokebolTemp);
int leTreinador(FILE * arqtreinador,TipoTreinador *treinador, int id);
void movimentacao(TipoPokemon *pokemon, TipoTreinador *treinador, int alvo);
void CapturaPokemon(TipoPokemon *pokemon, TipoTreinador *treinador, int indice);

// Funçoes para receber os dados do Treinador
int getTreinadorPos(TipoTreinador *treinador, double pos[2]);
int getTreinadorID(TipoTreinador *treinador);

// Funçoes para alterar os dados do Treinador
int setTreinadorPos(TipoTreinador *treinador, double pos[2]);

#endif