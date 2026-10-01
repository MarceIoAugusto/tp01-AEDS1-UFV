#include "cabecalho.h"
#include "centropesquisa.h"
#include "pokelista.h"
#include "saida.h"
#include "treinador.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Le os treinadores e os pokemons do arquivo
void RegistraInformacoes(FILE *arquivo, CentroPesquisa *CPentrada,
                         TipoTreinador *treinadorentrada, int *npokemons) {

    int POKEBOLAS;
    int cont = 0;
    char nomet[TAM_NOMET];
    TipoPokemon pokemonentrada;

    InicializarCP(CPentrada);

    // Le e inicializa os dados dos treinadores
    for (int i = 0; i < NUM_TREINADORES; i++) {
        fscanf(arquivo, "%s %d", nomet, &POKEBOLAS);
        InicializaTreinador(&treinadorentrada[i], i + 1, nomet, POKEBOLAS);
    }

    // Le a quantidade de pokemons
    fscanf(arquivo, "%d", npokemons);

    // Coloca os pokemons na lista de fugitivos
    for (cont = 0; cont < *npokemons; cont++) {
        if (LePokemon(arquivo, cont, &pokemonentrada) == 1) {
            InsercaoPokemonFugitivo(&pokemonentrada, CPentrada);
        }
    }
}

// Devolve ao centro os pokemons carregados pelo treinador
void DevolvePokemons(CentroPesquisa *centro, TipoTreinador *treinador) {

    TipoPokemon pokemon_retirado;

    while (RemoverPokemonTreinador(treinador, &pokemon_retirado)) {
        InsercaoPokemonRecuperado(&pokemon_retirado, centro);
    }
}

// Faz o treinador voltar ao centro e recarregar as pokebolas
void RetornaERecarrega(CentroPesquisa *centro, TipoTreinador *treinador) {

    int ganhas;

    RetornoTreinadorCP(treinador);
    DevolvePokemons(centro, treinador);

    ganhas = RecarregaPokbol(treinador);
    ImprimeRetornoPC(treinador, ganhas);
}

int main() {

    int num_pokemons = 0;
    char nomeArquivo[TAM_ARQUIVO];

    // Centro de Pesquisa
    CentroPesquisa Pokecenter;

    // Vetor dos treinadores
    TipoTreinador Treinador[NUM_TREINADORES];

    srand(time(NULL));

    system("cls");

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeArquivo);

    // Abre o arquivo de entrada
    FILE *entrada = fopen(nomeArquivo, "r");

    if (entrada == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo %s\n", nomeArquivo);
        return 1;
    }

    RegistraInformacoes(entrada, &Pokecenter,
                        Treinador, &num_pokemons);

    fclose(entrada);

    printf("\n");
    ImprimeInicioMissao(Treinador, num_pokemons);

    // Recarrega os treinadores que iniciam sem pokebolas
    for (int i = 0; i < NUM_TREINADORES; i++) {
        if (getTreinadorPokebolas(&Treinador[i]) == 0) {
            RetornaERecarrega(&Pokecenter, &Treinador[i]);
        }
    }

    // Missao de captura
    while (!ListaEVazia(getListaCPFugitivos(&Pokecenter))) {

        TipoPokemon *Alvo = setPokemonAlvo(&Pokecenter);

        int indice_treinador = Movimentacao(Alvo, Treinador);

        int acabaram_pokebolas =
            CapturaPokemon(Alvo, Treinador, indice_treinador);

        ImprimeAlvo(Treinador, Alvo, indice_treinador);

        RemoverPokemonFugitivo(&Pokecenter);

        if (ListaEVazia(getListaCPFugitivos(&Pokecenter))) {
            break;
        }

        if (acabaram_pokebolas) {
            RetornaERecarrega(
                &Pokecenter,
                &Treinador[indice_treinador]
            );
        }
    }

    // Retorno dos treinadores ao final da missao
    for (int i = 0; i < NUM_TREINADORES; i++) {
        RetornoTreinadorCP(&Treinador[i]);
        DevolvePokemons(&Pokecenter, &Treinador[i]);
    }

    ConclusaoDaMissao(Treinador);

    // Gera o relatorio
    GeraRelatorio(&Pokecenter, NOME_RELATORIO);
    printf("Relatorio gerado em %s\n", NOME_RELATORIO);

    // Libera a memoria
    for (int i = 0; i < NUM_TREINADORES; i++) {
        LiberaLista(&Treinador[i].pokelista);
    }

    LiberaCP(&Pokecenter);

    return 0;
}