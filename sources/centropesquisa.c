#include "centropesquisa.h"
#include <stdio.h>
#include <stdlib.h>

void Inicializar(CentroPesquisa *Pokecenter) {
    InicializaLista(&Pokecenter->poke_recuperados);
    InicializaLista(&Pokecenter->poke_fugitivos);
    return;
}
void InsercaoPokemonFugitivo(TipoPokemon *pokefugitivo, CentroPesquisa *PokeCenter) {
    InserePokemon(&PokeCenter->poke_fugitivos, pokefugitivo);
    return;
}
void RemoverPokemonFugitivo(TipoPokemon *pokemon, CentroPesquisa *PokeCenter) {
    int IdFugitivo = getPokeId(pokemon);
    RemovePokemon(&PokeCenter->poke_fugitivos, IdFugitivo);
}
