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
    int lin;
    int col;
    Cell *next;
    Cell *down;
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
    ListaE **col;
};

Spa_Mat* criar(int lc)
{
    Spa_Mat* mat = (Spa_Mat*) malloc(sizeof(Spa_Mat));
    int i;

    mat->n_col = lc;
    mat->n_lin = lc;
    mat->lin = (ListaE**) malloc(sizeof(ListaE*) * lc);
    mat->col = (ListaE**) malloc(sizeof(ListaE*) * lc);

    for (i = 0; i < lc; i++)
    {
        mat->lin[i] = (ListaE*) malloc(sizeof(ListaE));
        mat->lin[i]->head = NULL;
    }

    for (i = 0; i < lc; i++)
    {
        mat->col[i] = (ListaE*) malloc(sizeof(ListaE));
        mat->col[i]->head = NULL;
    }

    return mat;
}

Cell* criar_celula(int item, int l, int c)
{
    Cell *novo = NULL;

    if (item > 0)
    {
        novo = (Cell*) malloc(sizeof(Cell));
        novo->item = item;
        novo->lin = l;
        novo->col = c;
        novo->next = NULL;
        novo->down = NULL;
    }

    return novo;
}

static int validar_pos_matriz(int l, int c, Spa_Mat* mat)
{
    return (mat != NULL) && (l >= 0) && (l < mat->n_lin) && (c >= 0) && (l < mat->n_col);
}

static Cell* obter_celula_antes_linha(int l, ListaE* col)
{
    Cell *auxA = NULL;
    Cell *auxP = col->head;

    while ((auxP != NULL) && (auxP->lin < l))
    {
        auxA = auxP;
        auxP = auxP->down;
    }

    return auxA;
}

void alterar(unsigned int item, int l, int c, Spa_Mat* mat)
{
    Cell *auxLA, *auxLP, *auxCA, *novo;

    if (validar_pos_matriz(l, c, mat))
    {
        auxLA = NULL;
        auxLP = mat->lin[l]->head;

        while ((auxLP != NULL) && (auxLP->col < c))
        {
            auxLA = auxLP;
            auxLP = auxLP->next;
        }

        if (item > 0)
        {
            if ((auxLP != NULL) && (auxLP->col == c))
                auxLP->item = item;

            else
            {
                novo = criar_celula(item, l, c);
                auxCA = obter_celula_antes_linha(l, mat->col[c]);

                if (auxLA != NULL)
                {
                    novo->next = auxLA->next;
                    auxLA->next = novo;
                }

                else
                {
                    novo->next = mat->lin[l]->head;
                    mat->lin[l]->head = novo;
                }

                if (auxCA != NULL)
                {
                    novo->down = auxCA->down;
                    auxCA->down = novo;
                }

                else
                {
                    novo->down = mat->col[c]->head;
                    mat->col[c]->head = novo;
                }
            }
        }
    }
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
        Spa_Mat *mates = criar(lc);
        int i, j;

        for(i = 0 ; i < lc ; i++)
            for(j = lc ; j >= 0 ; j--)
                if(matbid[i][j] > 0)
                {
                    alterar(matbid[i][j], i, j, mates);
                }

        desalocar_matriz(matbid, lc);

        return mates;
    }

    return NULL;
}

int triangular(Spa_Mat *mates)
{
    if((mates != NULL) && (mates->n_lin > 0))
    {
        Cell *aux;
        int i = 0;;

        do
        {
            aux = mates->lin[i]->head;

            if(aux == NULL)
                i++;

            else if(aux->col == i && aux->next == NULL)
                i++;

            else if(aux->col < i)
            {
                while(aux->col < i && aux->next != NULL)
                    aux = aux->next;

                if(aux->next == NULL)
                    i++;

                else
                    i = -1;

            }

            else
                i = -1;
        }
        while(i < mates->n_lin -1 && i >= 0);

        if(i >= 0)
            return 0;

        else
        {
            i = 0;
            do
            {
                aux = mates->col[i]->head;

                if(aux == NULL)
                    i++;

                else if(aux->lin == i && aux->down == NULL)
                    i++;

                else if(aux->lin < i)
                {
                    while(aux->lin < i && aux->down != NULL)
                        aux = aux->down;

                    if(aux->down == NULL)
                        i++;

                    else
                        i = -1;
                }

                else
                    i = -1;

            }
            while(i < mates->n_lin -1 && i >= 0);
        }

        if(i >= 0)
            return 0;

        else
            return 1;
    }

    return -1;
}

int main()
{
    int lc, **matbid;

    scanf("%d", &lc);

    matbid = criar_matbid(lc);

    if(triangular(converte_matriz(matbid, lc)) == 0)
        printf("triangular\n");

    else
        printf("nao triangular\n");


    return 0;
}

