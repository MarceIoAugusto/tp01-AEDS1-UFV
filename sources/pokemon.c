#include "pokemon.h"
#define X 0
#define Y 1
#define NOME 50
// Alterei para ficar mais facil de visualizar o (X,Y)

int getPokeId(TipoPokemon *pokemon) {
    if (pokemon->Id < 9999) {
        return pokemon->Id;
    } else {
        printf("\nerro ao receber Id do pokemon.\n");
        return -1;
    }
}

int getPokeNumero(TipoPokemon *pokemon) {
    if ((pokemon->Numero > 0) && (pokemon->Numero < 1026)) { /*numero maximo de pokemon na pokedex*/
        return pokemon->Numero;
    } else {
        printf("\nerro ao receber Numero do pokemon.\n");
        return -1;
    }
}

int getPokeNome(TipoPokemon *pokemon, char nomesaida[NOME]) {
    if (pokemon->Nome[NOME - 1] == '\0') {
        for (int i = 0; i < NOME; i++) {
            nomesaida[i] = pokemon->Nome[i];
        }
    } else {
        printf("\nerro ao receber Nome do pokemon.\n");
        return -1;
    }
}

int getPokeTipo(TipoPokemon *pokemon, char tiposaida[10]) {
    if (pokemon->Tipo[9] == '/0') {
        for (int i = 0; i < 10; i++) {
            tiposaida[i] = pokemon->Tipo[i];
        }
    } else {
        printf("\nerro ao receber Tipo do pokemon.\n");
        return -1;
    }
}

int getPokeLocalizacao(TipoPokemon *pokemon, int *posX, int *posY) {
    *posX = pokemon->Localizacao[X];
    *posY = pokemon->Localizacao[Y];
    return 0;
}

int ImprimePokemon(TipoPokemon *pokemon) {
    char PrintNome[13];
    char PrintTipo[10];
    int x, y;
    getPokeNome(pokemon, &PrintNome);
    getPokeTipo(pokemon, &PrintTipo);
    getLocalizacao(pokemon, &x, &y);
    printf("\n########## Imprimindo informacoes do Pokemon ##########\n");
    printf("\nId: %d", getPokeId(pokemon));
    printf("\nNome: ");
    for (int i = 0; i < 13; i++) {
        if (PrintNome[i] != '\0') {
            printf("%c", PrintNome[i]);
        } else {
            break;
        }
    }
    printf("\nNumero na Pokedex: %d", getPokeNumero(pokemon));
    printf("\nTipo: ");
    for (int i = 0; i < 10; i++) {
        if (PrintTipo[i] != '\0') {
            printf("%c", PrintTipo[i]);
        } else {
            break;
        }
    }
    printf("\nCoordenadas de localizacao atual: X;%d __ Y;%d", x, y);
    printf("\n############### Fim de Impressão ###############\n");
}
