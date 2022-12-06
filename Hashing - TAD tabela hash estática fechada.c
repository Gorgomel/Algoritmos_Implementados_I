#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Hash Hash;

struct Hash
{
    int tam;
    float c;
    int *buckets;
    int *backup;
};

int liberar(Hash *h)
{
    if (h != NULL)
    {
        free(h->buckets);

        free(h);

        return 1;
    }

    return 0;
}

static int h1(int key, int B, float c)
{
    c *= key;
    key = c;
    c -= key;

    return B * c;
}

static int h2(int key, int B)
{
    return 1 + key %(B -1);
}

static int RH(Hash *h, int key, int i, float c)
{
    return (h1(key, h->tam, c) + i * h2(key, h->tam)) % h->tam;
}

Hash *criar(unsigned int tam, float c)
{
    Hash *h = malloc(sizeof(Hash));
    int i;

    h->tam = tam;
    h->buckets = malloc(tam * sizeof(int));
    h->c = c;

    for (i = 0; i < tam; i++)
        h->buckets[i] = -1;

    return h;
}


int buscar(int key, Hash *h)
{
    int x = h1(key, h->tam, h->c);
    int i, rh;

    if (h->buckets[x] == key)
        return x;

    else if (h->buckets[x] >= 0)
    {
        i = 1;
        rh = x;

        while((i < h->tam) && (h->buckets[rh] != key) && (h->buckets[rh] >= 0))
        {
            rh = RH(h, key, i, h->c);
            i++;
        }

        if((i < h->tam) && (h->buckets[rh] == key))
            return rh;

        else
            return 1;
    }


    return -1;
}

int inserir(int key, Hash *h)
{
    int i, rh;
    int x;

    if(h != NULL && key > 0)
    {
        x = h1(key, h->tam, h->c);

        if(h->buckets[x] <= 0)
        {
            h->buckets[x] = key;
            return 1;
        }

        else
        {
            i = 1;
            rh = x;

            while((i < h->tam) && (h->buckets[rh] != key) && (h->buckets[rh] > 0))
            {
                rh = RH(h, key, i, h->c);
                i++;
            }

            if((i < h->tam) && (h->buckets[rh] <= 0))
            {
                h->buckets[rh] = key;
                return 1;
            }
        }

    }

    return 0;
}

void imprimir(Hash *h, int quant)
{
    int i, x;

    if (h != NULL)
    {
        for (i = 0 ; i < quant ; i++)
        {
            x = buscar(h->backup[i], h);
            printf("%d\n", x);

        }
    }
}

Hash *cria_tabela(unsigned int n, unsigned int quant, float c)
{
    if(c != -1 && n > 0)
    {
        Hash *h = criar(n, c);
        int i, key;

        h->backup = malloc(quant *sizeof(int));

        for(i = 0 ; i < quant ; i++)
        {
            scanf("%d", &key);
            h->backup[i] = key;
            inserir(key, h);
        }

        return h;
    }

    return NULL;
}

float valida_c()
{
    float c;

    scanf("%f", &c);

    return(c > 0 && c < 1) ? c : -1;
}

int main()
{
    Hash *h;
    float c = valida_c();
    int n, quant;

    scanf("%d %d", &n, &quant);

    h = cria_tabela(n, quant, c);

    imprimir(h, quant);

    liberar(h);

    return 0;
}

