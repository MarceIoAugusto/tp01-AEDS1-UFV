#include "centropesquisa.h"

void InicializarCP(CentroPesquisa *Pokecenter) {
    // Inicializa as duas listas as de pokemons recuperados e de pokemons fugitivos
    InicializaLista(&Pokecenter->poke_recuperados);
    InicializaLista(&Pokecenter->poke_fugitivos);
    return;
}
void InsercaoPokemonFugitivo(TipoPokemon *pokefugitivo, CentroPesquisa *PokeCenter) {
    // Insere um pokemon Fugitivo na lista do PokeCenter
    InserePokemon(&PokeCenter->poke_fugitivos, pokefugitivo);
    return;
}
int RemoverPokemonFugitivo(CentroPesquisa *PokeCenter) {
    // Remove o primeiro pokemon da lista de fugitivos (que e sempre o pokemon alvo capturado)
    TipoPokemon pokemon_recuperado;
    return RemovePokemon(&PokeCenter->poke_fugitivos, &pokemon_recuperado);
}
void ImprimePokemonsFugitivo(CentroPesquisa *Pokecenter) {
    // Imprime todos os pokemons fugitivos
    ImprimeLista(&Pokecenter->poke_fugitivos);
    return;
}
void InsercaoPokemonRecuperado(TipoPokemon *poke_recuperado, CentroPesquisa *PokeCenter) {
    // Insere o pokemon recuperado no final da lista de Pokemons Recuperados do PokeCenter
    InserePokemon(&PokeCenter->poke_recuperados, poke_recuperado);
    return;
}
int RecarregaPokbol(TipoTreinador *Treinador) {
    int pokbol;

    // Gera um numero aleatorio entre 1 e MAX_POKEBOLAS
    pokbol = (rand() % MAX_POKEBOLAS) + 1;

    // Recarrega as pokebolas do treinador
    setTreinadorPokebolas(Treinador, pokbol);

    return pokbol; // Retorna quantas pokebolas ele recebeu
}
TipoPokemon *setPokemonAlvo(CentroPesquisa *pokecenter) {
    return getPrimeiroItem(pokecenter->poke_fugitivos);
}
PokeLista *getListaCPFugitivos(CentroPesquisa *pokecenter) {
    return &pokecenter->poke_fugitivos;
}
//Cria o relatorio com os pokemons recuperados
void GeraRelatorio(CentroPesquisa *PokeCenter, char *nomearquivo) {
    
    char nome[TAM_NOMEP];
    FILE *relatorio = fopen(nomearquivo, "w");
    if (relatorio == NULL) {
        printf("Erro ao criar o relatorio.\n");
        return;
    }

    fprintf(relatorio, "Pokemon recuperados:\n");

    // Percorre a lista de recuperados (pulando a celula cabeca)
    PokeCelula *atual = PokeCenter->poke_recuperados.Primeiro->Proximo;
    while (atual != NULL) {
        getPokeNome(&atual->Pokemon, nome);
        fprintf(relatorio, "%03d %s\n", getPokeNumero(&atual->Pokemon), nome);
        atual = atual->Proximo;
    }

    fclose(relatorio);
}
// libera a memoria das duas listas
void LiberaCP(CentroPesquisa *PokeCenter) {
    LiberaLista(&PokeCenter->poke_fugitivos);
    LiberaLista(&PokeCenter->poke_recuperados);
}
