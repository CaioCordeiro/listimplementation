#include <stdio.h>
#include <malloc.h>

struct elemento {
        struct elemento *proximo;
        int info;

};

struct Lista {
    struct elemento *dados;
    int tamanho;
};


struct Lista * criarLista(){
    struct Lista *aLista;
    aLista = malloc(sizeof(struct Lista));
    if(aLista != NULL){
        aLista->tamanho = 0;
        aLista->dados = NULL;
    }
    return 0;

}
int adicionarnaposicao(struct Lista *aLista, int *info,int posicao){
    struct elemento *novo,*anterior;
    if(posicao>aLista->tamanho +1){
        return(printf("Error(Posi)"));

    }
    else{
        novo = malloc(sizeof(struct elemento));
        if(posicao == 1){
            aLista->tamanho = aLista->tamanho + 1;
            novo->info = info;
            novo->proximo =NULL;
            aLista->dados = novo;
            return(aLista->tamanho);
        }
        else{
            if(novo == NULL){
                return(printf("Error(Full)"));
            }
            else{
                anterior = aLista->dados;
                for(int i = 0;(i<posicao-2);i++){
                    anterior = anterior->proximo;
                }
                novo->proximo = anterior->proximo;
                novo->info = info;
                anterior->proximo = novo;
                aLista->tamanho = aLista ->tamanho +1;
                return(aLista->tamanho);
            }

        }
    }

}
int retira(struct Lista *aLista,int valor){
    struct elemento *anterior,*auxiliar;
    int *volta;
    auxiliar= aLista->dados;
    while(auxiliar != NULL){
        if(auxiliar->info==valor){
            if(anterior==NULL){
                aLista->dados=auxiliar->proximo;
            }
            else{
                anterior->proximo=auxiliar->proximo;
            }
            aLista->tamanho = aLista->tamanho - 1;    
            return 1;
        }
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }

}

int main(){
    

}
