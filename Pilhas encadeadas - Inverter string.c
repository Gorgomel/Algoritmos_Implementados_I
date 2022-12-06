#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;
typedef struct PilhaE PilhaE;

struct Cell
{
    char item;
    Cell *next;
};

struct PilhaE
{
    Cell *topo;
};

Cell* criar_celula(char key)
{
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

PilhaE* criar_pilhaE()
{
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}

int pilhaE_vazia(PilhaE *p)
{
    return (p == NULL) || (p->topo == NULL);
}

void empilhar(char key, PilhaE *p)
{
    Cell *aux;

    if (p == NULL)
        p = criar_pilhaE();

    aux = criar_celula(key);
    aux->next = p->topo;
    p->topo = aux;
}

char desempilhar(PilhaE *p)
{
    Cell *aux;
    char item = -CHAR_MAX;

    if (!pilhaE_vazia(p))
    {
        aux = p->topo;
        item = aux->item;
        p->topo = aux->next;
        free(aux);
    }

    return item;
}

void imprimir_pilha(PilhaE *p)
{
    Cell *aux;

    if (!pilhaE_vazia(p))
    {
        aux = p->topo;

        while (aux != NULL)
        {
            printf("%c", aux->item);

            aux = aux->next;
        }
    }
}

int liberar_pilha(PilhaE *p)
{
    if (p != NULL)
    {
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}

PilhaE* scan()
{
    PilhaE *pi = (PilhaE*) malloc(sizeof(PilhaE));
    char *key = malloc(sizeof(char));
    int i;

    pi = criar_pilhaE();
    
    scanf("%s", key);

    i = 0;
    while(key[i] != '\0')
          i++;
    
    i--;
    while(i >= 0)
    {   
        empilhar(key[i], pi);
        i--;
    }
    
    return pi;
}

PilhaE * inverte_pilha(PilhaE *pi)
{
    PilhaE *p = (PilhaE*) malloc(sizeof(PilhaE));
    char c;

    if(!pilhaE_vazia(pi))
    {
        p = criar_pilhaE();

        while(pi->topo != NULL)
        {
            c = desempilhar(pi);
            empilhar(c, p);
        }
    }

    return p;
}

int main()
{
    PilhaE *pi = malloc(sizeof(PilhaE));

    pi = criar_pilhaE();

    pi = scan();
    
    pi = inverte_pilha(pi);

    imprimir_pilha(pi);

    liberar_pilha(pi);

    return 0;
}

