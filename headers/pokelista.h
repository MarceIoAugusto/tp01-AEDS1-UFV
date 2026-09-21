#ifndef POKELISTA_H
#define POKELISTA_H

#include "pokecelula.h"
#include "pokemon.h"
#include <stdlib.h>

typedef struct {
    PokeCelula * Primeiro, *Ultimo;
}PokeLista;

void InicializaLista(PokeLista *Lista);
void InserePokemon(PokeLista *Lista,TipoPokemon *pokemon);
int RemovePokemon(PokeLista *Lista,int id);
int RemoveUltimoPokemon(PokeLista *Lista);
int BuscaPokemon(PokeLista *Lista,int id,TipoPokemon *pokemon);
void ImprimeLista();

#endif