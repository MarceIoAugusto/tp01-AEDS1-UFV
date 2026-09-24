#include "pokelista.h"
#include "pokecelula.h"

void InicializaLista(PokeLista *Lista){ /* Inicializa a celula cabeça da lista encadeada*/
    Lista->Primeiro = (PokeCelula*) malloc(sizeof(PokeCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Ultimo->Proximo = NULL;
    Lista->Ultimo->Anterior = NULL;
}
void InserePokemon(PokeLista *Lista,TipoPokemon *pokemon){ /* Insere o Pokemon ao Final da Lista*/
    Lista->Ultimo->Proximo = (PokeCelula*) malloc(sizeof(PokeCelula));
    Lista->Ultimo->Proximo->Anterior = Lista->Ultimo;
    Lista->Ultimo = Lista->Ultimo->Proximo; /*Esta ordem possibilita a existencia de uma celula cabeca, assim, Lista->Primeiro aponta para a celula cabeca, que nao tem nenhum pokemon*/
    Lista->Ultimo->Pokemon = *pokemon;
    Lista->Ultimo->Proximo = NULL;
}
int RemovePokemon(PokeLista *Lista,int id){ /* Apaga o pokemon da Lista Pelo ID (Apenas apaga e libera memoria)*/
    PokeCelula *Auxiliar = Lista->Primeiro->Proximo;
    if(Auxiliar == NULL){
        printf("\nErro Lista Vazia.");
        return -1; /*Padrão adotado de retorno de erro = -1*/
    }
    while(Auxiliar != NULL){
        if(Auxiliar->Pokemon.Id == id){
            Auxiliar->Anterior->Proximo = Auxiliar->Proximo;
            if(Auxiliar->Proximo == NULL){ /* Como AUX->PROX apontam para NULL, então AUX é a ultima celula */
                Lista->Ultimo = Auxiliar;
            }
            else{
                Auxiliar->Proximo->Anterior = Auxiliar->Anterior;
            }
            free(Auxiliar);
        return 1;
        }
        Auxiliar = Auxiliar->Proximo;
    }
    printf("\nID não encontrado");
    return -1; /*Padrão adotado de retorno de erro = -1*/
}

int RemovePrimeiroPokemon(PokeLista *Lista){
    if(Lista->Primeiro == Lista->Ultimo){
        printf("\nErro Lista Vazia.");
        return -1; /*Padrão adotado de retorno de erro = -1*/
    }
    PokeCelula *Auxiliar= Lista->Ultimo;
    Lista->Ultimo->Anterior->Proximo = NULL;
    Lista->Ultimo = Lista->Ultimo->Anterior;
    free(Auxiliar);
    return 1; /*Padrão adotado de retorno de sucesso = 1*/
}

int BuscaPokemon(PokeLista *Lista,int id, TipoPokemon *pokemon){ /* Busca o Pokemon na lista pelo ID, e retorna com parametro de saida */
    PokeCelula *Auxiliar = Lista->Primeiro->Proximo;
    while(Auxiliar != NULL){
        if((Auxiliar->Pokemon.Id) == id){
            *pokemon = Auxiliar->Pokemon;
                return 1;
        }
        Auxiliar = Auxiliar->Proximo;
    }
    printf("\nErro Id Invalido.");
    return -1; /*Padrão adotado de retorno de erro = -1*/
}