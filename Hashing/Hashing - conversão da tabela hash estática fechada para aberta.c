#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct HashT HashT;
typedef struct HashA HashA;
typedef struct Buckets Buckets;
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

struct HashT
{
    int tam;
    int *buckets;
};

struct Buckets
{
    ListaE *l;
};

struct HashA
{
    int tam;
    Buckets *buckets;
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

HashT *criar(unsigned int tam)
{
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}

static int hashingF(int k, int B)
{
    return k % B;
}

static int overflow_prog(int hashC, int B, int tentativa)
{
    return (hashC + tentativa) % B;
}

int inserirT(int key, HashT *t)
{
    int x;
    int i, rh;

    if ((t != NULL) && (key > 0))
    {
        x = hashingF(key, t->tam);

        if (t->buckets[x] <= 0)
        {
            t->buckets[x] = key;

            return 1;
        }

        else
        {
            i = 1;
            rh = x;

            while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] > 0))
            {
                rh = overflow_prog(x, t->tam, i);
                i++;
            }

            if ((i < t->tam) && (t->buckets[rh] <= 0))
            {
                t->buckets[rh] = key;

                return 1;
            }
        }
    }

    return 0;
}

int liberar(HashT *t)
{
    if (t != NULL)
    {
        free(t->buckets);

        free(t);

        return 1;
    }

    return 0;
}

HashT * scan(int n, int quant)
{
    if(n > 0)
    {
        HashT *t = malloc(n *sizeof(HashT));

        t = criar(n);

        if(quant > 0)
        {
            int i, key;
            for(i = 0 ; i < quant ; i++)
            {
                scanf("%d", &key);
                inserirT(key, t);
            }
        }

        return t;
    }

    return NULL;
}

int free_A(HashA *a)
{
    if(a != NULL)
    {
        int i = 0;
    
        for(i = 0 ; i < a->tam ; i++)
        {
            liberar_LE(a[i].buckets->l);
            free(a[i].buckets);
        }
        
        free(a);
        
        return 1;
    }
    
    return 0;
}

void imprimir_A(HashA *a)
{
    Cell *aux;
    int i;

    if (a != NULL)
    {
        for (i = 0; i < a->tam ; i++)
        {
            printf("%d:", i);

            if(!listaE_vazia(a[i].buckets->l))
            {
                aux = a[i].buckets->l->head;

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

HashA *criarA(unsigned int tam)
{
    if(tam > 0)
    {
        HashA *a = malloc(tam *sizeof(HashA));
        int i;

        a->tam = tam;

        for (i = 0; i < tam; i++)
        {
            a[i].buckets = malloc(sizeof(Buckets));
            a[i].buckets->l = criar_listaE();
        }

        return a;
    }

    return NULL;
}

int inserirA(int key, HashA *a)
{
    int x;

    if ((a != NULL) && (key > 0))
    {
        x = hashingF(key, a->tam);

        inserir_ultimo(key, a[x].buckets->l);

        return 1;
    }

    return 0;
}

HashA * converte(HashT *t)
{
    if(t != NULL)
    {
        HashA *a;
        int i;

        a = criarA(t->tam);

        for(i = 0 ; i < t->tam ; i++)
            if(t->buckets[i] > 0)
                inserirA(t->buckets[i], a);
        

        liberar(t);

        return a;
    }

    return NULL;
}

int main()
{
    HashT *t;
    HashA *a;
    int n, quant;

    scanf("%d %d", &n, &quant);

    t = scan(n, quant);

    a = converte(t);

    imprimir_A(a);
    
    free_A(a);

    return 0;
}

