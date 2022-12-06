#include <stdio.h>
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


ListaE* criar_listaE()
{
    ListaE *l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}

Cell * criar_celula(int i)
{
    Cell *aux = (Cell*) malloc(sizeof(Cell));

    aux->item = i;
    aux->next = NULL;

    return aux;
}

int listaE_vazia(ListaE *l)
{
    return (l == NULL) || (l->head == NULL);
}

int procurar(ListaE *l, int key)
{
    Cell *aux;

    if(!listaE_vazia(l))
    {
        aux = l->head;

        while(aux != NULL)
        {
            if(aux->item == key)
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

ListaE * scan()
{
    ListaE *l = (ListaE*) malloc(sizeof(ListaE));
    int i;

    l = criar_listaE();

    while(i != -1)
    {
        scanf("%d", &i);

        if(i != -1)
            inserir_ultimo(i, l);
    }

    return l;
}

int transposicao(ListaE* l, int key)
{
    Cell *aux, *aux2, *aux3, *auxA;
    int i;

    if(!listaE_vazia(l))
    {
        if(procurar(l, key))
        {

            aux = l->head;
            aux2 = l->head;
            aux3 = l->head;

            for(i = 0 ; key != aux3->item && aux3 != NULL ; i++, aux3 = aux3->next)
            {
                if(i >= 1)
                    aux2 = aux2->next;

                if(i >= 2)
                    aux = aux->next;
            }

            if((i >= 2) && (aux != NULL))
            {
                auxA = criar_celula(key);

                auxA->next = aux->next;
                aux2->next = aux3->next;
                aux->next = auxA;
            }

            else if((i == 1) && (aux != NULL))
            {
                auxA = criar_celula(key);

                auxA->next = aux;
                aux->next = aux3->next;
                l->head = auxA;
            }

            return 0;
        }

        else
            return -1;
    }

    return -1;
}

int main()
{
    ListaE *l = (ListaE*) malloc(sizeof(ListaE));
    int i, num;

    l = scan();

    scanf("%d", &num);

    int *key = (int*) malloc(num *sizeof(int));

    for(i = 0 ; i < num ; i++)
    {
        scanf("%d", key + i);
        transposicao(l, key[i]);
    }

    imprimir(l);
    
    free(l);
    free(key);

    return 0;
}

