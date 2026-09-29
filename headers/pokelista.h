#ifndef POKELISTA_H
#define POKELISTA_H

#include "pokecelula.h"
#include "pokemon.h"
#include <stdlib.h>

typedef struct {
    PokeCelula *Primeiro, *Ultimo;
} PokeLista;

void InicializaLista(PokeLista *Lista);
void InserePokemon(PokeLista *Lista, TipoPokemon *pokemon);
int RemovePokemon(PokeLista *Lista, int id);
int RemoveUltimoPokemon(PokeLista *Lista);
int BuscaPokemon(PokeLista *Lista, int id, TipoPokemon *pokemon);
<<<<<<< HEAD
void ImprimeLista();
=======
void ImprimeLista(PokeLista *Lista);
>>>>>>> 4502fcc78b658804d29c6c3f291a88e03662548b
PokeLista *getPrimeiroItem(PokeLista Lista);

#endif