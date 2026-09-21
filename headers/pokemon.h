#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>


typedef struct {
    int Id;
    int Numero;
    char Nome [13]; /* O maior nome de pokemon possui 12 caracteres*/
    char Tipo [10]; /* O tipo de pokemon com maior quantidade de caracteres eh o TERRESTRE com 9 caracteres */ 
    float Localizacao [2]; /* Dois numeros de ponto flutuante que registram a localização X e Y */


}TipoPokemon;

int InicializaPokemon(TipoPokemon *pokemon);

int getPokeId(TipoPokemon *pokemon);
int getPokeNumero(TipoPokemon *pokemon);
int getPokeNome(TipoPokemon *pokemon, char nomesaida[13]);
int getPokeTipo(TipoPokemon *pokemon, char tiposaida[10]);
int getPokeLocalizacao(TipoPokemon *pokemon, int *x, int *y);

int setPokeId(TipoPokemon *pokemon);
int setPokeNumero(TipoPokemon *pokemon);
int setPokeNome(TipoPokemon *pokemon);
int setPokeTipo(TipoPokemon *pokemon);
int setPokeLocalizacao(TipoPokemon *pokemon);

int ImprimePokemon(TipoPokemon *pokemon);


#endif;