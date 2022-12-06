#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;
typedef struct Spa_Mat Spa_Mat;

struct Cell
{
    int item;
    int col;
    Cell *next;
};

struct ListaE
{
    Cell *head;
};

struct Spa_Mat
{
    int n_lin;
    int n_col;
    ListaE **lin;
};


Spa_Mat* criar(int l, int c)
{
    Spa_Mat* mat = (Spa_Mat*) malloc(sizeof(Spa_Mat));
    int i;

    mat->n_col = c;
    mat->n_lin = l;
    mat->lin = (ListaE**) malloc(sizeof(ListaE*) * l);

    for (i = 0; i < l; i++)
    {
        mat->lin[i] = (ListaE*) malloc(sizeof(ListaE));
        mat->lin[i]->head = NULL;
    }

    return mat;
}

Cell* criar_celula(int item, int col)
{
    Cell *nova = (Cell*) malloc(sizeof(Cell));
    nova->item = item;
    nova->col = col;
    nova->next = NULL;

    return nova;
}

static int validar_matriz(Spa_Mat* mat)
{
    return(mat != NULL) && (mat->n_lin > 0) && (mat->n_col > 0);
}

void desalocar_matriz(int **matbid, int l)
{
    int i;

    for(i = 0 ; i < l ; i++)
        free(matbid[i]);

    free(matbid);
}

int** criar_matbid(int l, int c)
{
    if(l > 0 && c > 0)
    {
        int i, j, **matbid = malloc(l * sizeof(int*));

        for(i = 0 ; i < l ; i++)
            matbid[i] =  malloc(l * sizeof(int*));

        for(i = 0 ; i < l ; i++)
            for(j = 0 ; j < c ; j++)
                scanf("%d", matbid[i] + j);

        return matbid;
    }

    return NULL;
}

Spa_Mat * converte_matriz(int **matbid, int l, int c)
{
    if(matbid != NULL)
    {
        Spa_Mat *mates = criar(l, c);
        Cell *aux;
        int i, j;

        for(i = 0 ; i < l ; i++)
            for(j = c ; j >= 0 ; j--)
                if(matbid[i][j] > 0)
                {
                    aux = criar_celula(matbid[i][j], j);
                    aux->next = mates->lin[i]->head;
                    mates->lin[i]->head = aux;
                }


        desalocar_matriz(matbid, l);

        return mates;
    }

    return NULL;
}

void imprimir(Spa_Mat *mates)
{
    if(validar_matriz(mates))
    {
        Cell *aux;
        int i;

        for(i = 0 ; i < mates->n_lin ; i++)
        {
            if(mates->lin[i]->head != NULL)
            {
                printf("%d:", i);
                aux = mates->lin[i]->head;

                while(aux != NULL)
                {
                    printf(" -> %d,%d", aux->col, aux->item);
                    aux = aux->next;
                }
            }

            else
                printf("%d: ->", i);

            printf("\n");
        }
    }
}

int main()
{
    int l, c, **matbid;

    scanf("%d %d", &l, &c);

    matbid = criar_matbid(l, c);

    imprimir(converte_matriz(matbid, l, c));

    return 0;
}

