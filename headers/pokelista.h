#ifndef POKELISTA_H
#define POKELISTA_H

#include "pokemon.h"
#include <stdlib.h>

typedef struct PokeCelula{
    TipoPokemon Pokemon;
    struct PokeCelula *Proximo;
}PokeCelula;


typedef struct {
    PokeCelula *Primeiro, *Ultimo;
} PokeLista;

void InicializaLista(PokeLista *Lista); //Faz a inicializacao da lista
void InserePokemon(PokeLista *Lista, TipoPokemon *pokemon); //Insere pokemon no final da lista
int RemovePokemon(PokeLista *Lista, TipoPokemon *pokemon); 
int BuscaPokemon(PokeLista *Lista, int id, TipoPokemon *pokemon);
<<<<<<< HEAD
void ImprimeLista();
=======
void ImprimeLista(PokeLista *Lista);
>>>>>>> 4502fcc78b658804d29c6c3f291a88e03662548b
PokeLista *getPrimeiroItem(PokeLista Lista);

/* void getPrimeiroItem(PokeLista *Lista);
*/
#endif