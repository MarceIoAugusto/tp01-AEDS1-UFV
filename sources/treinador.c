#include "treinador.h"
#include "cabecalho.h"
#include "pokelista.h"
#include "pokemon.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void InicializaTreinador(TipoTreinador *treinador, int ID, char nomeTemp[50], int pokebolTemp) {
    int caracter = 0;

    // Erros
    if (ID < 0) {
        printf("\nErro ao inicializar o treinador... Id negativo\n");
        exit(EXIT_FAILURE);
    } else if (nomeTemp[0] == '\0') {
        printf("\nErro ao inicializar o treinador... Nome vazio\n");
        exit(EXIT_FAILURE);
    } else if (pokebolTemp < 0) {
        printf(
            "\nErro ao inicializar o treinador... pokebolas iniciais negativas\n");
        exit(EXIT_FAILURE);
    }

    // Preenchendo o ID
    treinador->id = ID;

    // Nome
    while (nomeTemp[caracter] != '\0') {
        treinador->nome[caracter] = nomeTemp[caracter];
        caracter++;
    }
    treinador->nome[caracter] = '\0';

    // Pokebolas Iniciais
    treinador->pokebolas = pokebolTemp;

    // pos X e Y = (0,0)
    treinador->pos[X] = 0;
    treinador->pos[Y] = 0;

    // inicializando a pokelista de cada treinador
    InicializaLista(&treinador->pokelista);
    return;
}
int leTreinador(FILE *arqtreinador, TipoTreinador *treinador, int id) {
    char nome[TAM_NOMET];
    int pokebolas;
    if (fscanf(arqtreinador, "%s %d", nome, &pokebolas) == 2) {
        InicializaTreinador(treinador, id, nome, pokebolas);
        return 1;
    }
    return -1;
}
int Movimentacao(TipoPokemon *pokemon, TipoTreinador *treinador) {
    float distancia[2];
    float resX = 0;
    float resY = 0;

    // posicao do treinador
    float posT[2];

    // Pegando as posicoes do pokemon alvo
    float pokepos[2];
    getPokeLocalizacao(pokemon, &pokepos[X], &pokepos[Y]);

    // calculando a distancia para cada treinador
    for (int i = 0; i < NUM_TREINADORES; i++) {
        posT[X] = treinador[i].pos[X];
        posT[Y] = treinador[i].pos[Y];
        // (X1 - X2)
        resX = (posT[X] - pokepos[X]);

        //(resultado)**2
        resX = resX * resX;

        // (Y1 - Y2)
        resY = (posT[Y] - pokepos[Y]);

        //(resultado)**2
        resY = resY * resY;

        distancia[i] = sqrt(resX + resY);

        treinador[i].distancia = distancia[i];
    }
    int menor_indice = 0;

    // Verifica qual Treinador esta mais proximo do pokemon e retorna seu indice
    for (int i = 1; i < NUM_TREINADORES; i++) {
        if (treinador[i].distancia < treinador[menor_indice].distancia) {
            menor_indice = i;
        }
    }
    return menor_indice;
}
void CapturaPokemon(TipoPokemon *pokemon, TipoTreinador *treinador, int indice) {
    // Retirando uma pokebola do Treinador
    treinador[indice].pokebolas--;
    // Inserindo o pokemon capturado na lista do Treinador
    InserePokemon(&treinador[indice].pokelista, pokemon);
}
int RemoverPokemonTreinador(TipoTreinador *treinador, TipoPokemon *PokemonRetirado) {
    // Remove um pokemon da lista do treinador, retornando o pokemon removido da funçao
    if (RemovePokemon(&treinador->pokelista, &PokemonRetirado)) {
        // A lista ainda nao está vazia (return 0)
        return 0;

    // A lista ja está vazia (return 1)
    return 1;
}
void ImprimeTreinador(TipoTreinador treinador) {
    printf("\nO Treinador %s esta na posicao: (%.0f %.0f) | Pokebolas: %d\n", treinador.nome, treinador.pos[X], treinador.pos[Y], treinador.pokebolas);
}
int getTreinadorID(TipoTreinador *treinador) {
    return treinador->id;
}
double *getTreinadorPos(TipoTreinador *treinador) {
    double pos[2];
    pos[X] = treinador->pos[X];
    pos[Y] = treinador->pos[Y];
    return pos;
}
char *getTreinadorNome(TipoTreinador *treinador) {
    return treinador->nome;
}
void setTreinadorPos(TipoTreinador *treinador, double pos[2]) {
    treinador->pos[X] = pos[X];
    treinador->pos[Y] = pos[Y];
    return;
}
void setTreinadorPokebolas(TipoTreinador *treinador, int pokebolas) {
    treinador->pokebolas = treinador->pokebolas + pokebolas;
    return;
}
double getTreinadorDistancia(TipoTreinador *treinador) {
    return treinador->distancia;
}
int getTreinadorPokebolas(TipoTreinador *treinador) {
    return treinador->pokebolas;
}