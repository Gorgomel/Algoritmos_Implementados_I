#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Hash Hash;
typedef struct Buckets Buckets;
typedef struct Cell Cell;
typedef struct Lista Lista;

struct Cell
{
    int item;
    Cell *next;
};

struct Lista
{
    Cell *head;
};

struct Buckets
{
    Lista *l;
};

struct Hash
{
    int tam;
    int *backup;
    Buckets *buckets;
};

Cell* criar_celula(int key)
{
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

Lista* criar_listaE()
{
    Lista* l = malloc(sizeof(Lista));

    l->head = NULL;

    return l;
}

int lista_vazia(Lista *l)
{
    return (l == NULL) || (l->head == NULL);
}

static int H1(int k, int B)
{
    return k % B;
}

int buscar_H(int key, Hash *h)
{
    Cell *aux;
    int x = H1(key, h->tam);
    int i;

    if (!lista_vazia(h[x].buckets->l))
    {
        i = 1;
        aux = h[x].buckets->l->head;

        while ((i < h->tam) && (aux->item != key) && (!lista_vazia(h[x].buckets->l)))
        {
            aux = aux->next;
            i++;
        }

        if ((i < h->tam) && (aux->item == key))
            return x;

        else
            return -1;
    }

    else
        return -1;
}

void imprimir_H(Hash *h, int quant)
{
    Cell *aux;
    int i, x;

    if (h != NULL)
    {
        for (i = 0 ; i < quant ; i++)
        {
                x = buscar_H(h[0].backup[i], h);
                printf("%d\n", x);
        }

        printf("\n");
        for (i = 0; i < h->tam ; i++)
        {
            printf("%d:", i);

            if(!lista_vazia(h[i].buckets->l))
            {
                aux = h[i].buckets->l->head;

                while(aux != NULL)
                {
                    printf(" -> %d", aux->item);
                    aux = aux->next;
                }
            }

            else
                printf(" ->");

            printf("\n");
        }
    }
}

int tamanho_LE(Lista *l)
{
    Cell *aux;
    int tam = 0;

     if (!lista_vazia(l))
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

void bubblesort(Lista *l)
{
    if(!lista_vazia(l))
    {
        Cell *aux;
        int i, j, x, n, troca = 1;

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

void inserir_primeiro(int key, Lista *l)
{
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);
    aux->next = l->head;
    l->head = aux;
}

void inserir_ultimo(int key, Lista *l)
{
    Cell *aux, *novo;

    if (l == NULL)
        l = criar_listaE();

    if (lista_vazia(l))
        inserir_primeiro(key, l);

    else
    {
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);
        aux->next = novo;
        bubblesort(l);
    }
}

Hash *criarH(unsigned int tam)
{
    if(tam > 0)
    {
        Hash *h = malloc(tam *sizeof(Hash));
        int i;

        h->tam = tam;

        for (i = 0; i < tam; i++)
        {
            h[i].buckets = malloc(sizeof(Buckets));
            h[i].buckets->l = criar_listaE();
        }

        return h;
    }

    return NULL;
}

int inserirH(int key, Hash *h)
{
    if ((h != NULL) && (key > 0))
    {
        int x;
        x = H1(key, h->tam);

        inserir_ultimo(key, h[x].buckets->l);

        return 1;
    }

    return 0;
}

Hash * scan(int n, int quant)
{
    if(n > 0)
    {
        Hash *h;
        int i, key;

        h = criarH(n);
        h->backup = malloc(quant *sizeof(int));

        if(quant > 0)
        {
            for(i = 0 ; i < quant ; i++)
            {
                scanf("%d", &key);
                inserirH(key, h);
                h[0].backup[i] = key;
            }
        }

        return h;
    }

    return NULL;
}

int main()
{
    Hash *h;
    int n, quant;

    scanf("%d %d", &n, &quant);

    h = scan(n, quant);

    imprimir_H(h, quant);
    
    return 0;
}
