#ifndef CENTROPESQUISA_H
#define CENTROPESQUISA_H

#include "pokelista.h"

typedef struct {
    PokeLista poke_fugitivos;
    PokeLista poke_recuperados;
} CentroPesquisa;

void Inicializar(CentroPesquisa *Pokecenter);
void InsercaoPokemonFugitivo(TipoPokemon *PokeFugitivo, CentroPesquisa *PokeCenter);
void RemoverPokemonFugitivo(TipoPokemon *pokemon, CentroPesquisa *PokeCenter);
void ImprimePokemonsFugitivo(CentroPesquisa *Pokecenter);
void InsercaoPokemonRecuperado(TipoPokemon *poke_recuperado, CentroPesquisa *PokeCenter, TipoTreinador *Treinador);
int RecarregaPokbol(TipoTreinador *Treinador);
TipoPokemon *setPokemonAlvo(CentroPesquisa *pokecenter);
#endif