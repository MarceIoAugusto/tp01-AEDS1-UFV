#include "pokelista.h"
#include "pokecelula.h"

void InicializaLista(PokeLista *Lista){
    Lista->Primeiro = (PokeCelula*) malloc(sizeof(PokeCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Ultimo->Proximo = NULL;
}
void InserePokemon(PokeLista *Lista,TipoPokemon *pokemon){ /* Insere o Pokemon ao Final da Lista*/
    Lista->Ultimo->Proximo = (PokeCelula*) malloc(sizeof(PokeCelula));
    Lista->Ultimo = Lista->Ultimo->Proximo; /*Esta ordem possibilita a existencia de uma celula cabeca, assim, Lista->Primeiro aponta para a celula cabeca, que nao tem nenhum pokemon*/
    Lista->Ultimo->Pokemon = *pokemon;
    Lista->Ultimo->Proximo = NULL;
}
int RemovePokemon(PokeLista *Lista,int id){ /* Apaga o pokemon da Lista Pelo ID (Apenas apaga e libera memoria)*/
    PokeCelula *Auxiliar0 = Lista->Primeiro;
    PokeCelula *Auxiliar1 = Lista->Primeiro->Proximo;
    if(Auxiliar1==NULL){
        Printf("\nErro Lista Vazia.");
        return -1; /*Padrão adotado de retorno de erro = -1*/
    }
    while(Auxiliar1 != NULL){
        if(Auxiliar1->Pokemon->Id == id){
            Auxiliar1 = Auxiliar1->Proximo;
            free(Auxiliar0->Proximo);
            Auxiliar0->Proximo = Auxiliar1;
            if(Auxiliar1==NULL){ /* Como AUX1 e AUX->Proximo apontam para NULL, então AUX 0 é a ultima celula */
                Lista->Ultimo = Auxiliar0;
            }
        return 1;
        }
        Auxiliar0 = Auxiliar0->Proximo;
        Auxiliar1 = Auxiliar1->Proximo;
    }
    Printf("\nID não encontrado");
    return -1; /*Padrão adotado de retorno de erro = -1*/
}

int BuscaPokemon(PokeLista *Lista,int id, TipoPokemon *pokemon){ /* Busca o Pokemon na lista pelo ID, e retorna com parametro de saida */
    PokeCelula *Auxiliar = Lista->Primeiro;
    while(Auxiliar != NULL){
        if((Auxiliar->Pokemon->Id) == id){
            *pokemon = Auxiliar->Pokemon;
                return 1;
        }
    }
    printf("\nErro Id Invalido.");
    return -1; /*Padrão adotado de retorno de erro = -1*/
}