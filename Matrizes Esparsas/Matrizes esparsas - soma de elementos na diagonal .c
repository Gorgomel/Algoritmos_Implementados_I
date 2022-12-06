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

void desalocar_matriz(int **matbid, int l)
{
    int i;

    for(i = 0 ; i < l ; i++)
        free(matbid[i]);

    free(matbid);

}

int** criar_matbid(int lc)
{
    if(lc > 0)
    {
        int i, j, **matbid = malloc(lc * sizeof(int*));

        for(i = 0 ; i < lc ; i++)
            matbid[i] =  malloc(lc * sizeof(int*));

        for(i = 0 ; i < lc ; i++)
            for(j = 0 ; j < lc ; j++)
                scanf("%d", matbid[i] + j);

        return matbid;
    }

    return NULL;
}

Spa_Mat * converte_matriz(int **matbid, int lc)
{
    if(matbid != NULL)
    {
        Spa_Mat *mates = criar(lc, lc);
        Cell *aux;
        int i, j;

        for(i = 0 ; i < lc ; i++)
            for(j = lc ; j >= 0 ; j--)
                if(matbid[i][j] > 0)
                {
                    aux = criar_celula(matbid[i][j], j);
                    aux->next = mates->lin[i]->head;
                    mates->lin[i]->head = aux;
                }


        desalocar_matriz(matbid, lc);

        return mates;
    }

    return NULL;
}

int soma_diagonal(Spa_Mat *mates)
{
    if(mates != NULL && mates->n_lin > 0)
    {
        Cell *aux;
        int i, j, soma = 0;

        for(i = 0 ; i < mates->n_lin ; i++)
        {
            if(mates->lin[i]->head != NULL)
            {
                aux = mates->lin[i]->head;

                for(j = 0 ; j < i && aux->next != NULL ; j++, aux = aux->next);

                if(aux->col == i)
                    soma += aux->item;
            }
        }

        return soma;
    }

    return -1;
}

int main()
{
    int lc, **matbid, n;

    scanf("%d", &lc);

    matbid = criar_matbid(lc);

    if((n = soma_diagonal(converte_matriz(matbid, lc))) >= 0)
        printf("%d\n", n);

    return 0;
}

