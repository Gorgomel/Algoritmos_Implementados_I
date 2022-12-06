#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define TAM_MAX 100

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
    char item = 'a';

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

void flush_in()
{
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF ) {}
}

/*PilhaE * scan(int num)
{
    PilhaE *p = (PilhaE*) malloc(sizeof(PilhaE));
    char c;
    int i;

    p = criar_pilhaE();

    if(num > 0)
    {
        scanf("%c", &c);

        empilhar(c, p);
    }
}*/

int confere(char *str)
{
    PilhaE *p = (PilhaE*) malloc(sizeof(PilhaE));
    int i, j;

    j = strlen(str);

    p = criar_pilhaE();

    i = 0;
    for(j = j ; j > 0 ; j--)
    {
        if(str[i] == '(')
            empilhar('(', p);

        else if(str[i] == ')' && !pilhaE_vazia(p))
            desempilhar(p);

        else if(str[i] == ')' && pilhaE_vazia(p))
            return 1;

        i++;
    }

    if(pilhaE_vazia(p))
        return 0;

    else
        return 1;

    liberar_pilha(p);

}

void avalia(PilhaE *p, int num)
{
    char *str = (char*) malloc(sizeof(char));
    int vet[num], i, j;

    if(num > 0)
    {
        for(i = 0 ; i < num ; i++)
        {
           str = (char*) malloc(sizeof(char));

            scanf("%s", str);

            j = strlen(str);

            while(j >= 0)
            {
                empilhar(str[j], p);
                j--;
            }

            vet[i] = confere(str);

            free(str);

            while(!pilhaE_vazia(p))
                desempilhar(p);
        }

        for(i = 0 ; i < num ; i++)
        {
            if(vet[i] == 0)
                printf("correct\n");

            else
                printf("incorrect\n");
        }
    }

}

int main()
{
    PilhaE *p = malloc(sizeof(PilhaE));
    int num;

    p = criar_pilhaE();

    scanf("%d", &num);

    avalia(p, num);

    liberar_pilha(p);

    return 0;
}

