#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <string.h>
#include "cabecalho.h"


typedef struct {
    int Id;
    int Numero;
    char Nome [TAM_NOMEP]; /* O maior nome de pokemon possui 12 caracteres*/
    char Tipo [TAM_TIPO]; /* O tipo de pokemon com maior quantidade de caracteres eh o TERRESTRE com 9 caracteres */ 
    float Localizacao[COORDENADAS]; /* Dois numeros de ponto flutuante que registram a localização X e Y */


}TipoPokemon;

int LePokemon(FILE* arquivo, int numero, TipoPokemon *saida);
int InicializaPokemon(TipoPokemon *pokemon, int identrada, int numeroentrada, char *nomeentrada, char *tipoentrada,float x, float y);


int getPokeId(TipoPokemon *pokemon);
int getPokeNumero(TipoPokemon *pokemon);
int getPokeNome(TipoPokemon *pokemon, char *nomesaida);
int getPokeTipo(TipoPokemon *pokemon, char *tiposaida);
int getPokeLocalizacao(TipoPokemon *pokemon, float *x, float *y);

void setPokeId(TipoPokemon *pokemon,int identrada);
void setPokeNumero(TipoPokemon *pokemon,int numeroentrada);
void setPokeNome(TipoPokemon *pokemon,char *nomeentrada);
void setPokeTipo(TipoPokemon *pokemon,char *tipoentrada);
void setPokeLocalizacao(TipoPokemon *pokemon, float x, float y);

int ImprimePokemon(TipoPokemon *pokemon);


#endif;