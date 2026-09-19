#include "pokemon.h"


int getPokeId(TipoPokemon *pokemon){
    if(pokemon->Id<9999){
    return pokemon->Id;
    }
    else{ 
        printf("\nerro ao receber Id do pokemon.\n")
        return -1;
    }
}

int getPokeNumero(TipoPokemon *pokemon){
    if((pokemon->Numero>0) && (pokemon->Numero<1026)){ /*numero maximo de pokemon na pokedex*/
    return pokemon->Id;
    }
    else{ 
        printf("\nerro ao receber Numero do pokemon.\n")
        return -1;
    }
}

int getPokeNome(TipoPokemon *pokemon, char nomesaida[13]){
    if(pokemon->Nome[12] == '/0'){
        for(int i=0;i<13;i++){
            nomesaida[i] = pokemon->Nome[i];
        }
    }
    else{
        printf("\nerro ao receber Nome do pokemon.\n")
        return -1;
    }
}

int getPokeTipo(TipoPokemon *pokemon, char tiposaida[10]){
    if(pokemon->Tipo[9] == '/0'){
        for(int i=0;i<10;i++){
            tiposaida[i] = pokemon->Tipo[i];
        }
    }
    else{
        printf("\nerro ao receber Tipo do pokemon.\n")
        return -1;
    }
}

int getPokeLocalizacao(TipoPokemon *pokemon, int *x, int *y){
    if((pokemon->Localizacao [0] > 0) || (pokemon->Localizacao [1] > 0)){
       *x = pokemon->Localizacao [0];
       *y = pokemon->Localizacao [1];
       return 0;
    }
    else{
        printf("\nerro ao receber Localizacao do pokemon.\n")
        return -1;
    }
}

