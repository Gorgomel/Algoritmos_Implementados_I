#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;
typedef struct FilaE FilaE;

struct Cell
{
    int item;
    Cell *next;
};

struct FilaE
{
    Cell *inicio;
    Cell *fim;
};

Cell* criar_celula(int key)
{
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

FilaE* criar_filaE()
{
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));

    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

int filaE_vazia(FilaE* f)
{
    return (f == NULL) || (f->inicio == NULL);
}

void enfileirar(int key, FilaE* f)
{
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;

    else
    {
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}

int desenfileirar(FilaE* f)
{
    Cell *aux;
    int item = -INT_MAX;

    if (!filaE_vazia(f))
    {
        aux = f->inicio;
        f->inicio = aux->next;
        item = aux->item;
        free(aux);
    }

    return item;
}

void imprimir_fila(FilaE* f)
{
    Cell *aux;

    if (!filaE_vazia(f))
    {
        aux = f->inicio;

        while (aux != NULL)
        {
            printf("%d ", aux->item);
            aux = aux->next;
        }
    }
}

int liberar_filaE(FilaE* f)
{
    if (!filaE_vazia(f))
    {
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

FilaE * scan()
{
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    int i = 0;

    f = criar_filaE();

    while(i != -1)
    {
        scanf("%d", &i);

        if(i != -1)
        {
            if(i < 0)
                i *= -1;

            enfileirar(i, f);
        }
    }

    return f;

    liberar_filaE(f);
}

int tamanho_fila(FilaE *f)
{
    FilaE *f2 = (FilaE*) malloc(sizeof(FilaE));
    int i = 0;

    f2 = criar_filaE();

    while(!filaE_vazia(f))
    {
        enfileirar(desenfileirar(f), f2);
        i++;
    }

    while(!filaE_vazia(f2))
        enfileirar(desenfileirar(f2), f);

    return i;
}

void semaforo(FilaE* E1, FilaE* E2, FilaE* E3, FilaE* R)
{
    int i, j;

    i = tamanho_fila(E1);
        i = i + tamanho_fila(E2);
        i = i + tamanho_fila(E3);

    if(i > 0)
    {
        if(filaE_vazia(R))
            R = criar_filaE();

        i = tamanho_fila(E1);
        i = i + tamanho_fila(E2);
        i = i + tamanho_fila(E3);

        while(i > 0)
        {
            if(!filaE_vazia(E1))
                for(j = 0 ; j < 3 && (!filaE_vazia(E1)) ; j++)
                    enfileirar(desenfileirar(E1), R);

            if(!filaE_vazia(E2))
                for(j = 0 ; j < 3 && (!filaE_vazia(E2)); j++)
                    enfileirar(desenfileirar(E2), R);

            if(!filaE_vazia(E3))
                for(j = 0 ; j < 3 && (!filaE_vazia(E3)) ; j++)
                    enfileirar(desenfileirar(E3), R);

            i--;
        }

        imprimir_fila(R);
    }
}

int main()
{
    FilaE *E1 = (FilaE*) malloc(sizeof(FilaE));
    FilaE *E2 = (FilaE*) malloc(sizeof(FilaE));
    FilaE *E3 = (FilaE*) malloc(sizeof(FilaE));
    FilaE *R = (FilaE*) malloc(sizeof(FilaE));

    E1 = criar_filaE();
    E2 = criar_filaE();
    E3 = criar_filaE();
    R = criar_filaE();

    E1 = scan();
    E2 = scan();
    E3 = scan();

    semaforo(E1, E2, E3, R);

    liberar_filaE(E1);
    liberar_filaE(E2);
    liberar_filaE(E3);
    liberar_filaE(R);

    return 0;
}

