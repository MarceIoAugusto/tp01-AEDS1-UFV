#ifndef CENTROPESQUISA_H
#define CENTROPESQUISA_H

#include "pokelista.h"
#include "treinador.h" 

typedef struct {
    PokeLista poke_fugitivos;
    PokeLista poke_recuperados;
} CentroPesquisa;

void InicializarCP(CentroPesquisa *Pokecenter);
void InsercaoPokemonFugitivo(TipoPokemon *pokefugitivo, CentroPesquisa *PokeCenter);
int RemoverPokemonFugitivo(CentroPesquisa *PokeCenter);
void ImprimePokemonsFugitivo(CentroPesquisa *Pokecenter);
void InsercaoPokemonRecuperado(TipoPokemon *poke_recuperado, CentroPesquisa *PokeCenter);
int RecarregaPokbol(TipoTreinador *Treinador);
TipoPokemon *setPokemonAlvo(CentroPesquisa *pokecenter);
PokeLista *getListaCPFugitivos(CentroPesquisa *pokecenter);
void GeraRelatorio(CentroPesquisa *PokeCenter, char *nomearquivo);
void LiberaCP(CentroPesquisa *PokeCenter);

#endif
