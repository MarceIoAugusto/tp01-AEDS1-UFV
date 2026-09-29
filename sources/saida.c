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
    char nome[TAM_NOMET];
    int pokebol;
    printf("========================================\n");
    printf("           INICIO DA MISSAO             \n");
    printf("========================================\n");
    for (int i = 0; i < NUM_TREINADORES; i++) {
        // Entradas
        pos = getTreinadorPos(&treinador[i]);
        *nome = getTreinadorNome(&treinador[i]);
        pokebol = getTreinadorPokebolas(&treinador[i]);
        printf("Treinador(a) %s: Posicao (%d,%d) | Pokebolas: %d\n");
    }
    printf("\nPokemons fugitivos a serem resgatados: %d\n");
    printf("----------------------------------------\n\n");
    return;
}

void ImprimeAlvo(TipoTreinador *treinador, TipoPokemon *pokemon, int indice_treinador, int sucesso) {
    // Variaveis
    char nomesaida[TAM_NOMEP];
    float x, y;
    // Entradas
    getPokeNome(pokemon, &nomesaida);
    getPokeLocalizacao(pokemon, &x, &y);

    // Saida
    printf("Pokemon Alvo: %s\n", nomesaida);
    printf("Localizacao: (%d,%d)\n", x, y);
    for (int i = 0; i < NUM_TREINADORES; i++) {
        printf("Distancia Treinador(a) %s: %.2f\n", getTreinadorNome(&treinador[i]), getTreinadorDistancia(&treinador[i]));
    }
    printf("Missao atribuida ao Treinador(a) %s\n", getTreinadorNome(&treinador[indice_treinador]));
    printf("Treinador(a) %s se movimentou para (%d,%d)", getTreinadorNome(&treinador[indice_treinador]), x, y);
    printf("%s capturado com sucesso!\n", nomesaida);
    printf("Pokebolas restantes para o Treinador(a) %s: %d\n", getTreinadorNome(&treinador[indice_treinador]), getTreinadorPokebolas(&treinador[indice_treinador]));
    printf("\n----------------------------------------\n");
}

void ImprimeRetornoPC(TipoTreinador *treinador, int pokebolas_ganhas) {
    printf("========================================\n");
    printf("     Treinador(a) Rosa SEM POKÉBOLAS    \n");
    printf("========================================\n\n");
    printf("Treinador(a) %s retorna ao Centro de Pesquisa\n", getTreinadorNome(treinador));
    printf("Entregando Pokemon ao Centro de Pesquisa\n");
    printf("Treinador(a) %s recebeu %d pokebolas\n", getTreinadorNome(treinador), pokebolas_ganhas);
}

void ConclusaoDaMissao(TipoTreinador *treinador) {
    printf("========================================\n");
    printf("    Todos os Pokemons foram resgatados  \n");
    printf("========================================\n");
    printf("Ambos treinadores retornam ao Centro de Pesquisa\n");
    for (int i = 0; i < NUM_TREINADORES; i++) {
        printf("Treinador(a) %s devolve os pokemons\n", getTreinadorNome(&treinador[i]));
    }
    printf("\n========================================\n");
    printf("              MISSAO CONCLUIDA            \n");
    printf("========================================\n");
}

/*
========================================
Todos Pokemons foram resgatados
========================================
Ambos treinadores retornam ao Centro de Pesquisa.
Treinador(a) Rosa devolve os Pokémon.
Treinador(a) Nate devolve os Pokémon.
========================================
MISSÃO CONCLUÍDA
========================================
*/
