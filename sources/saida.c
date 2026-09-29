#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"
#include "pokelista.h"
#include "centropesquisa.h"
#include "treinador.h"

void ImprimeInicioMissao(TipoTreinador *treinador,int numero_fugitivos);
//Variaveis
double pos[2];
char nome[TAM_NOME];
printf("========================================\n");
printf("           INICIO DA MISSAO             \n");
printf("========================================\n");
for(int i = 0; i<2; i++){
    //Entradas
    pos = getTreinadorPos(treinador);
    nome = getTreinadorNome(treinador[i]);
    pokebol = getTreinadorPokebolas
    printf("Treinador(a) %s: Posicao (%d,%d) | Pokebolas: %d\n",,);
}
printf("\nPokemons fugitivos a serem resgatados: %d\n");