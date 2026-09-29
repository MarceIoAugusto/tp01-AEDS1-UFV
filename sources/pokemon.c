#include "pokemon.h"

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

int getPokeNome(TipoPokemon *pokemon, char *nomesaida) {
    if (pokemon->Nome[TAM_NOMEP - 1] == '\0') {
        for (int i = 0; i < TAM_NOMEP; i++) {
            nomesaida[i] = pokemon->Nome[i];
        }
    } else {
        printf("\nerro ao receber Nome do pokemon.\n");
        return -1;
    }
    return 1;
}

int getPokeTipo(TipoPokemon *pokemon, char *tiposaida) {
    if (pokemon->Tipo[TAM_TIPO - 1] == '/0') {
        for (int i = 0; i < TAM_TIPO; i++) {
            tiposaida[i] = pokemon->Tipo[i];
        }
    } else {
        printf("\nerro ao receber Tipo do pokemon.\n");
        return -1;
    }
}

int getPokeLocalizacao(TipoPokemon *pokemon, float *posX, float *posY) {
    *posX = pokemon->Localizacao[X];
    *posY = pokemon->Localizacao[Y];
    return 0;
}

void setPokeId(TipoPokemon *pokemon, int identrada) {
    pokemon->Id = identrada;
    return;
}

void setPokeNumero(TipoPokemon *pokemon, int numeroentrada) {
    pokemon->Numero = numeroentrada;
    return;
}

void setPokeNome(TipoPokemon *pokemon, char *nomeentrada) {
    strncpy(pokemon->Nome, nomeentrada, sizeof(pokemon->Nome));
    return;
}

void setPokeTipo(TipoPokemon *pokemon, char *tipoentrada) {
    strncpy(pokemon->Tipo, tipoentrada, sizeof(pokemon->Tipo));
    return;
}

void setPokeLocalizacao(TipoPokemon *pokemon, float x, float y) {
    pokemon->Localizacao[X] = x;
    pokemon->Localizacao[Y] = y;
    return;
}

int LePokemon(FILE *arquivo, int numero, TipoPokemon *saida) {
    int Id;
    char Nome[TAM_NOMEP];
    char Tipo[TAM_TIPO];
    float x, y;
    if (fscanf(arquivo, "%d %12s %9s %f %f", &Id, Nome, Tipo, &x, &y) == 5) {
        InicializaPokemon(saida, Id, numero, Nome, Tipo, x, y);
        return 1;
    } else {
        return -1;
    }
}

int InicializaPokemon(TipoPokemon *pokemon, int identrada, int numeroentrada, char *nomeentrada, char *tipoentrada, float x, float y) {
    setPokeId(pokemon, identrada);
    setPokeNumero(pokemon, numeroentrada);
    setPokeNome(pokemon, nomeentrada);
    setPokeTipo(pokemon, tipoentrada);
    setPokeLocalizacao(pokemon, x, y);
    return 1;
}

int ImprimePokemon(TipoPokemon *pokemon) {
    char PrintNome[TAM_NOMEP];
    char PrintTipo[TAM_TIPO];
    int x, y;
    getPokeNome(pokemon, &PrintNome);
    getPokeTipo(pokemon, &PrintTipo);
    getLocalizacao(pokemon, &x, &y);
    printf("\n########## Imprimindo informacoes do Pokemon ##########\n");
    printf("\nId: %d", getPokeId(pokemon));
    printf("\nNome: ");
    for (int i = 0; i < TAM_NOMEP; i++) {
        if (PrintNome[i] != '\0') {
            printf("%c", PrintNome[i]);
        } else {
            break;
        }
    }
    printf("\nNumero na Pokedex: %d", getPokeNumero(pokemon));
    printf("\nTipo: ");
    for (int i = 0; i < TAM_TIPO; i++) {
        if (PrintTipo[i] != '\0') {
            printf("%c", PrintTipo[i]);
        } else {
            break;
        }
    }
    printf("\nCoordenadas de localizacao atual: X;%d __ Y;%d", x, y);
    printf("\n############### Fim de Impressão ###############\n");
}