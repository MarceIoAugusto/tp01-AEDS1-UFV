#include <stdlib.h>
#include <stdio.h>
#include "cabecalho.h"
#include "centropesquisa.h"
#include "pokelista.h"
#include "treinador.h"


void RegistraInformacoes(FILE* arquivo,CentroPesquisa *CPentrada,TipoTreinador *treinadorentrada,int *npokemons){
    int  POKEBOLAS;
    int cont=0;
    char nomet[TAM_NOMET];
    TipoPokemon pokemonentrada;
    
    //inicializa CP
    InicializarCP(CPentrada);

    //Inicializa Treinadores <ja insere seus dados
    for(int i=1;i<3;i++){
        fscanf(arquivo,"%s %d", nomet, &POKEBOLAS);
        InicializaTreinador(treinadorentrada[i], i, nomet, POKEBOLAS);
    }

    //Le a quantidade de pokemons
    fscanf(arquivo,"%d",*npokemons);

    // Le os pokemons do arquivo e insere na lista de fugitivos
    while(LePokemon(arquivo, cont, &pokemonentrada) != EOF){
        InsercaoPokemonFugitivo(&pokemonentrada,CPentrada);
    }
}

int main(){

    // INICIALIZACAO
    int Npokemons;
    CentroPesquisa Centro_de_Pesquisa;
    TipoTreinador Treinador[2];

    //Leitura do arquivo
    FILE *teste = fopen("teste.txt","r");

    // REGISTRO DE INFORMACOES
    RegistraInformacoes(teste,&Centro_de_Pesquisa,Treinador,&Npokemons);

    //Missao de capruta

    //recebendo pokemon alvo
    TipoPokemon *Alvo = setPokemonAlvo(&Centro_de_Pesquisa);
    capturaPokemon(Alvo,Treinador,Movimentacao(Alvo,Treinador));

    //Atualizacao listagem de fugas
    removerPokemonFugitivo(&Centro_de_Pesquisa);
    //O if verifica se é o ultimos
    if();



    return 0;
}