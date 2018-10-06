#include <stdio.h>
#include <malloc.h>

struct elemento
{
    struct elemento *proximo;
    int info;
};

struct Lista
{
    struct elemento *inicio;
    struct elemento *final;
    int tamanho;
};

struct Lista *criarLista()
{
    struct Lista *aLista;
    aLista = malloc(sizeof(struct Lista));
    if (aLista != NULL)
    {
        aLista->tamanho = 0;
        aLista->inicio = NULL;
    }
    return aLista;
}

int adicionar(struct Lista *aLista, int info)
{
    struct elemento *novo, *anterior;
        novo = (struct elemento *) malloc(sizeof(struct elemento));

        if (aLista->inicio == NULL)
        {
            aLista->tamanho = aLista->tamanho + 1;
            novo->info = info;
            novo->proximo = NULL;
            aLista->inicio = novo;
            aLista->final = novo;
            return (aLista->tamanho);
        }
        else
        {
            if (novo == NULL)
            {
                return (printf("Error(Full)"));
            }
            else
            {
                anterior = aLista->final;
                novo->info = info;
                novo->proximo = NULL;
                anterior->proximo = novo;
                aLista->final = novo;
                aLista->tamanho = aLista->tamanho +1;
                return (aLista->tamanho);
            }
        }
}

int retira(struct Lista *aLista, int valor)
{
    struct elemento *anterior = NULL, *auxiliar;
    int *volta;
    auxiliar = aLista->inicio;
    while (auxiliar != NULL)
    {
        if (auxiliar->info == valor)
        {
            if (anterior == NULL)
            {
                aLista->inicio = auxiliar->proximo;
            }
            else
            {
                anterior->proximo = auxiliar->proximo;
            }
            aLista->tamanho = aLista->tamanho - 1;
            return 1;
        }
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }
}

int exibe(struct Lista *aLista){
    struct elemento *aux;
    aux = aLista->inicio;
    while(aux != NULL)
    {
        printf("%d ",aux->info);
        aux = aux->proximo;
    }
    return 0;
}
