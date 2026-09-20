#ifndef POKECELULA_H
#define POKECELULA_H

#include "pokemon.h"

typedef struct PokeCelula{
    TipoPokemon Pokemon;
    struct PokeCelula *Proximo;
}PokeCelula;

#endif