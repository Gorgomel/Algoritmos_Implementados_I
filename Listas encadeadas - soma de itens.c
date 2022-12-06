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

int procurar(int key, ListaE *l)
{
    Cell *aux;

    if (l != NULL)
    {
        aux = l->head;

        while (aux != NULL)
        {
            if (aux->item == key)
                return 1;

            aux = aux->next;
        }
    }

    return 0;
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

int remover(int key, ListaE *l)
{
    Cell *auxA, *auxP = NULL;

    if (!listaE_vazia(l))
    {
        auxA = l->head;

        if(auxA->item == key)
        {

            l->head = l->head->next;
        }

        else
        {
            auxP = auxA;

            while((auxA != NULL) && (auxA->item != key))
            {
                if (auxP != NULL)
                    auxP = auxA;

                auxA = auxA->next;
            }
        }

        if (auxA != NULL)
        {
            if (auxP != NULL)
                auxP->next = auxA->next;

            free(auxA);
            return 1;
        }

    }

    return 0;
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

void scan(ListaE * l1)
{
    int i;

    if(listaE_vazia(l1))
        criar_listaE(l1);

    while(i != -1)
    {
        scanf("%d", &i);

        if(i != -1)
        {
            inserir_ultimo(i, l1);
        }
    }
}

int soma_cel(ListaE *l1)
{
    Cell *aux, *aux2;
    int i = 0;

    aux = l1->head;

    if(!listaE_vazia(l1))
    {
        while(aux != NULL)
        {
            i = i + aux->item;
            aux = aux->next;
        }

        aux2 = criar_celula(i);
        aux2->next = NULL;
        l1->head = aux2;

        return 1;
    }

    return 0;
}

int main()
{
    ListaE *l1 = malloc(sizeof(ListaE));

    criar_listaE(l1);

    scan(l1);

    if(soma_cel(l1))
        imprimir(l1);

    else
        printf("\nFail\n");

    return 0;
}

