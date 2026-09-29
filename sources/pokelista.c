#include "pokelista.h"

void InicializaLista(PokeLista *Lista) { /* Inicializa a celula cabeça da lista encadeada*/
    Lista->Primeiro = (PokeCelula *)malloc(sizeof(PokeCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Ultimo->Proximo = NULL;
}

void InserePokemon(PokeLista *Lista, TipoPokemon *pokemon) { /* Insere o Pokemon ao Final da Lista*/
    Lista->Ultimo->Proximo = (PokeCelula *)malloc(sizeof(PokeCelula));
    Lista->Ultimo = Lista->Ultimo->Proximo; /*Esta ordem possibilita a existencia de uma celula cabeca, assim, Lista->Primeiro aponta para a celula cabeca, que nao tem nenhum pokemon*/
    Lista->Ultimo->Pokemon = *pokemon;
    Lista->Ultimo->Proximo = NULL;
}

int RemovePokemon(PokeLista *Lista, TipoPokemon *pokemon) { /* Remove o Primeiro pokemon da lista e o retorna como parâmetro*/
    PokeCelula *Auxiliar;
    if (Lista->Primeiro->Proximo == NULL) {
        printf("\nErro Lista Vazia.");
        return 1; /*Padrão adotado de retorno de erro = -1*/
    }
    Auxiliar = Lista->Primeiro->Proximo->Proximo;
    *pokemon = Lista->Primeiro->Proximo->Pokemon;
    free(Lista->Primeiro->Proximo);
    Lista->Primeiro->Proximo = Auxiliar;
    return 0;
}

int BuscaPokemon(PokeLista *Lista, int id, TipoPokemon *pokemon) { /* Busca o Pokemon na lista pelo ID e o retorna com parametro de saida */
    PokeCelula *Auxiliar = Lista->Primeiro->Proximo;
    while (Auxiliar != NULL) {
        if ((getPokeId(&Auxiliar->Pokemon)) == id) {
            *pokemon = Auxiliar->Pokemon;
            return 1;
        }
        Auxiliar = Auxiliar->Proximo;
    }
    printf("\nErro Id Invalido.");
    return -1; /*Padrão adotado de retorno de erro = -1*/
}

TipoPokemon *getPrimeiroItem(PokeLista Lista) {
    return &Lista.Primeiro->Pokemon;
}
void ImprimeLista(PokeLista *Lista) {
    PokeCelula *curr;
    curr = Lista->Primeiro;

    while (curr->Proximo) {
        return;
    }
}