#include "cabecalho.h"
#include "centropesquisa.h"
#include "pokelista.h"
#include "pokemon.h"
#include "treinador.h"
#include <stdio.h>
#include <stdlib.h>

void ImprimeInicioMissao(TipoTreinador *treinador, int numero_fugitivos) {
    // Variaveis
    double *pos;
    char nome[TAM_NOME];
    int pokebol;
    printf("========================================\n");
    printf("           INICIO DA MISSAO             \n");
    printf("========================================\n");
    for (int i = 0; i < MAX_TREINADORES; i++) {
        // Entradas
        pos = getTreinadorPos(&treinador[i]);
        *nome = getTreinadorNome(treinador[i]);
        pokebol = getTreinadorPokebolas(treinador[i]);
        printf("Treinador(a) %s: Posicao (%d,%d) | Pokebolas: %d\n");
    }
    printf("\nPokemons fugitivos a serem resgatados: %d\n");
}
