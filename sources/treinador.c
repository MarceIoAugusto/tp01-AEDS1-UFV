#include <stdio.h>
#include "treinador.h"
#include "pokelista.h"
#include <stdlib.h>
#include <math.h>

#define X 0 //Apenas para ficar mais facil de visualizar (X,Y)
#define Y 1 
#define NUM_TREINADORES 2 //numero maximo de treinadores

void Inicializa(TipoTreinador *treinador,int ID, char nomeTemp[50],int pokebolTemp){
    int caracter = 0;

    //Erros
    if(ID < 0){
        printf("\nErro ao inicializar o treinador... Id negativo\n");
        exit(EXIT_FAILURE);
    }else if(nomeTemp[0] == '\0'){
        printf("\nErro ao inicializar o treinador... Nome vazio\n");
        exit(EXIT_FAILURE);
    }else if(pokebolTemp < 0){
        printf("\nErro ao inicializar o treinador... pokebolas iniciais negativas\n");
        exit(EXIT_FAILURE);
    }

    //Preenchendo o ID
    treinador->id = ID;

    //Nome
    while(nomeTemp[caracter] != '\0'){
        treinador->nome[caracter] = nomeTemp[caracter];
        caracter ++;
    }
    treinador->nome[caracter] = '\0';

    //Pokebolas Iniciais
    treinador->pokebolas = pokebolTemp;
    
    //pos X e Y = (0,0)
    treinador->pos[X] = 0;
    treinador->pos[Y] = 0;

    //inicializando a pokelista de cada treinador
    InicializaLista(&treinador->pokelista);
    return;
}
void Movimentacao(TipoPokemon *pokemon,TipoTreinador *treinador, int alvo){
    float distancia[2];
    float resX = 0;
    float resY = 0;

    //posicao do treinador
    double posT[2];

    //Pegando as posicoes do pokemon alvo
    double pokepos[2];
    getPokeLocalizacao(&pokemon[alvo],&pokepos[X],&pokepos[Y]);

    //calculando a distancia para cada treinador
    for(int i = 0; i < NUM_TREINADORES; i++){
        getTreinadorPos(&treinador[i],posT);
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
    if(distancia[0] <= distancia[1]){
        treinador[0].pos[X] = pokepos[X];
        treinador[0].pos[Y] = pokepos[Y];
    }else{
        treinador[1].pos[X] = pokepos[X];
        treinador[1].pos[Y] = pokepos[Y];
    }
    return;
}
void CapturaPokemon(TipoPokemon *pokemon){}

int getTreinadorID(TipoTreinador *treinador, int *ID){
    *ID = treinador->id;
    return 0;
}
int getTreinadorPos(TipoTreinador *treinador, double pos[2]){
    pos[X] = treinador->pos[X];
    pos[Y] = treinador->pos[Y];
    return 0;
}


int setTreinadorPos(TipoTreinador *treinador, double pos[2]){
    treinador->pos[X] = pos[X];
    treinador->pos[Y] = pos[Y];
    return 0;
}