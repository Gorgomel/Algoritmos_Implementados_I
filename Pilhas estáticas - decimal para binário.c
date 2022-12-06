#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define TAM_MAX 100

typedef struct{
    int item[TAM_MAX];
    int topo;
}Pilha;

Pilha* criar_pilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}

int pilha_cheia(Pilha *p){
    if (p == NULL)
        return -1;

    else if (p->topo == (TAM_MAX - 1))
        return 1;

    else
        return 0;
}

int pilha_vazia(Pilha *p){
    if (p == NULL)
        return -1;

    else if (p->topo == -1)
        return 1;

    else
        return 0;
}

Pilha * empilhar(Pilha *p, int item){
    if (p == NULL)
        p = criar_pilha();

    if (!pilha_cheia(p)){
        p->topo++;

        p->item[p->topo] = item;

        return p;
    }

    return 0;
}

int desempilhar (Pilha *p){
    int item = INT_MIN;

    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

void imprimir_pilha(Pilha *p){
    Pilha aux = *p;
    int item;

    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);

        printf("%d", item);
    }
}

void liberar_pilha(Pilha *p){
    if (p != NULL)
        free(p);
}


int obter_posicao_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}

Pilha * binario(int num)
{
    Pilha *p = malloc(sizeof(Pilha));
    int aux, i = 0;

    p = criar_pilha();

    aux = num;
    do
    {
        if(aux >= 1)
        {
            if(aux % 2 == 0)
                p = empilhar(p, 0);

            else
                p = empilhar(p, 1);

            aux = aux / 2;
            i = 1;
        }

        else
        {
            i = -1;
        }
    }while(i != -1);

    return p;

}

int main()
{
    Pilha *p1 = malloc(sizeof(Pilha));
    int num;
    float num2;

    scanf("%f", &num2);

    if(num2 < 0)
    {
        num2 = num2 * -1;
    }

    num = num2;

    p1 = criar_pilha();

    p1 = binario(num);

    imprimir_pilha(p1);

    return 0;
}


