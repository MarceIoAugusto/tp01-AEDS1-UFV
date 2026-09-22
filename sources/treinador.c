#include "treinador.h"
#include "cabecalho.h"
#include "pokelista.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void Inicializa(TipoTreinador *treinador, int ID, char nomeTemp[50], int pokebolTemp) {
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
int Movimentacao(TipoPokemon *pokemon, TipoTreinador *treinador) {
    float distancia[2];
    float resX = 0;
    float resY = 0;

    // posicao do treinador
    double posT[2];

    // Pegando as posicoes do pokemon alvo
    double pokepos[2];
    getPokeLocalizacao(&pokemon, &pokepos[X], &pokepos[Y]);

    // calculando a distancia para cada treinador
    for (int i = 0; i < NUM_TREINADORES; i++) {
        getTreinadorPos(&treinador[i], posT);
        // (X1 - X2)
        resX = (posT[X] - pokepos[X]);

        //(resultado)**2
        resX = resX * resX;

        // (Y1 - Y2)
        resY = (posT[Y] - pokepos[Y]);

        //(resultado)**2
        resY = resY * resY;

        distancia[i] = sqrt(resX + resY);
    }
    // Verifica qual Treinador esta mais proximo do pokemon e retorna seu indice
    if (distancia[0] <= distancia[1]) {
        treinador[0].pos[X] = pokepos[X];
        treinador[0].pos[Y] = pokepos[Y];
        return 0;
    } else {
        treinador[1].pos[X] = pokepos[X];
        treinador[1].pos[Y] = pokepos[Y];
        return 1;
    }
}

void CapturaPokemon(TipoPokemon *pokemon, TipoTreinador *treinador, int indice) {
    // Verifica se o treinador tem pokebola suficiente
    if (treinador[indice].pokebolas > 0) {
        char nomepokemon[TAM_NOME];

        // Pegando o nome do pokemon Alvo
        getPokeNome(pokemon, nomepokemon);

        // Retirando uma pokebola do Treinador
        treinador[indice].pokebolas--;

        // Inserindo o pokemon capturado na lista do Treinador
        InserePokemon(&treinador[indice].pokelista, pokemon);
        printf("O Treinador %s capturou o pokemon %s, agora ele tem %d pokebolas\n", treinador[indice].nome, nomepokemon, treinador[indice].pokebolas);
    }
    // Treinador nao tem pokebola suficiente, retornando ele para o centro de pesquisa
    else {
        printf("O Treinador %s nao tem pokebolas suficientes\n", treinador[indice]);
        treinador[indice].pos[X] = 0;
        treinador[indice].pos[Y] = 0;
    }
}

TipoPokemon RemoverPokemonTreinador(TipoTreinador *treinador) {
    TipoPokemon PokemonRetirado;

    // Remove um pokemon da lista do treinador, retornando o pokemon removido da funçao
    PokemonRetirado = RemoveUltimoPokemon(&treinador->pokelista);

    // Apenas verifica se houve um pokemon retirado
    if (getPokeId(&PokemonRetirado) == NULL || getPokeId(&PokemonRetirado) < 0)
        setPokeId(&PokemonRetirado, -1);
    return PokemonRetirado;
}
void ImprimeTreinador(TipoTreinador treinador) {
    printf("\nO Treinador %s esta na posicao: (%.0f %.0f) | Pokebolas: %d\n", treinador.nome, treinador.pos[X], treinador.pos[Y], treinador.pokebolas);
}
int getTreinadorID(TipoTreinador *treinador) {
    return treinador->id;
}

int getTreinadorPos(TipoTreinador *treinador, double pos[2] /*<--saida*/) {
    pos[X] = treinador->pos[X];
    pos[Y] = treinador->pos[Y];
    return 0;
}

int setTreinadorPos(TipoTreinador *treinador, double pos[2] /*<--entrada*/) {
    treinador->pos[X] = pos[X];
    treinador->pos[Y] = pos[Y];
    return 0;
}