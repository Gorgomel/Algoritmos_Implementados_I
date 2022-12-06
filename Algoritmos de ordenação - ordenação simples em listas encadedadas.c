#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;

struct Cell
{
    int item;
    Cell *next;
};

struct ListaE
{
    Cell *head;
};

Cell* criar_celula(int key)
{
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

ListaE* criar_listaE()
{
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}

int listaE_vazia(ListaE *l)
{
    return (l == NULL) || (l->head == NULL);
}

void inserir_primeiro(int key, ListaE *l)
{
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);
    aux->next = l->head;
    l->head = aux;
}

void inserir_ultimo(int key, ListaE *l)
{
    Cell *aux, *novo;

    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else
    {
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);
        aux->next = novo;
    }
}

void imprimir(ListaE *l)
{
    Cell *aux;

    if (!listaE_vazia(l))
    {
        aux = l->head;

        while (aux != NULL)
        {
            printf("%d ", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}

int liberar_LE(ListaE *l)
{
    Cell *aux = NULL;

    if (l != NULL)
    {
        while(l->head != NULL)
        {
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}

int tamanho_LE(ListaE *l)
{
    Cell *aux;
    int tam = 0;

     if (!listaE_vazia(l))
     {
        aux = l->head;

        while(aux != NULL)
        {
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}

ListaE* scan()
{
    ListaE *l = (ListaE*) malloc(sizeof(ListaE));
    int i;

    l = criar_listaE();

    while(i != -1)
    {
        scanf("%d", &i);

        if(i >= 0)
            inserir_ultimo(i, l);
    }

    return l;
}

void bubblesort(ListaE *l)
{
    Cell *aux;
    int i, j, x, n, troca = 1;

    if(!listaE_vazia(l))
    {
        n = tamanho_LE(l);

        for(i = 0 ; (i < n -1) && (troca) ; i++)
        {
            troca = 0;
            aux = l->head;

            for(j = 0 ; j < n -i -1 ; j++, aux = aux->next)
                if(aux->item > aux->next->item)
                {
                    x = aux->item;
                    aux->item = aux->next->item;
                    aux->next->item = x;
                    troca = 1;
                }
        }
    }
}

int main()
{
    ListaE *l = (ListaE*) malloc(sizeof(ListaE));

    l = scan();

    bubblesort(l);

    imprimir(l);

    liberar_LE(l);

    return 0;
}

