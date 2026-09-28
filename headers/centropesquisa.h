#ifndef CENTROPESQUISA_H
#define CENTROPESQUISA_H

#include "pokelista.h"

typedef struct {
    PokeLista poke_fugitivos;
    PokeLista poke_recuperados;
} CentroPesquisa;

void Inicializar(CentroPesquisa *PokeCenter);
void InsercaoPokemonFugitivo(TipoPokemon *PokeFugitivo, CentroPesquisa *PokeCenter);
void RemoverPokemonFugitivo(TipoPokemon *pokemon, CentroPesquisa *PokeCenter);
#endif