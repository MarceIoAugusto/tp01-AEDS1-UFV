#include "centropesquisa.h"
#include "pokelista.h"
#include "pokemon.h"
#include "treinador.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Inicializar(CentroPesquisa *Pokecenter) {
    //Inicializa as duas listas as de pokemons recuperados e de pokemons fugitivos
    InicializaLista(&Pokecenter->poke_recuperados);
    InicializaLista(&Pokecenter->poke_fugitivos);
    return;
}
void InsercaoPokemonFugitivo(TipoPokemon *pokefugitivo, CentroPesquisa *PokeCenter) {
    //Insere um pokemon Fugitivo na lista do PokeCenter
    InserePokemon(&PokeCenter->poke_fugitivos, pokefugitivo);
    return;
}
void RemoverPokemonFugitivo(TipoPokemon *pokemon, CentroPesquisa *PokeCenter) {
    //Remove o exato pokemon da lista de fugitivos
    int IdFugitivo = getPokeId(pokemon);
    RemovePokemon(&PokeCenter->poke_fugitivos, IdFugitivo);
}
void ImprimePokemonsFugitivo(CentroPesquisa *Pokecenter) {
    //Imprime todos os pokemons fugitivos
    ImprimeLista(&Pokecenter->poke_fugitivos);
    return;
}
void InsercaoPokemonRecuperado(TipoPokemon *poke_recuperado, CentroPesquisa *PokeCenter, TipoTreinador *Treinador){
    //Insere o pokemon recuperado no final da lista de Pokemons Recuperados do PokeCenter
    InserePokemon(&PokeCenter->poke_recuperados, poke_recuperado);
    return;
}
void RecarregaPokbol(TipoTreinador *Treinador){
    int pokbol;
    pokbol = 0;
    // Inicializa a semente com o tempo atual
    srand(time(NULL));

    // Gera um numero aleatorio entre 1 e 20
    pokbol = (rand() % 20) + 1;
    
    // Recarrega as pokebolas do treinador
    setTreinadorPokebolas(Treinador,pokbol);

    return;
}