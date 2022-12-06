#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int n1;
    int n2;
} quantidade;

int* soma(quantidade *Bn, int *vt, int *vt2)
{
    int i;
    int *vector;


    if((*Bn).n1 >= (*Bn).n2)
    {
        vector = (int*) malloc(sizeof(int)* ((*Bn).n1));
        for(i = 0 ; i < ((*Bn).n1) ; i++)
        {
            if(i <= ((*Bn).n2))
            {
                vector[i] = vt[i] + vt2[i];
            }

            else
            {
                vector[i] = vt[i];
            }
        }
    }

    else
    {
        vector = (int*) malloc(sizeof(int)* ((*Bn).n2));
        for(i = 0 ; i < ((*Bn).n2) ; i++)
        {
            if(i <= ((*Bn).n1))
            {
                vector[i] = vt[i] + vt2[i];
            }

            else
            {
                vector[i] = vt2[i];
            }
        }
    }

    return vector;
}

void mostradora(int *vector, quantidade *Bn)
{
    int i;

    if((*Bn).n1 > (*Bn).n2)
    {
        for(i = 0 ; i < ((*Bn).n1) ; i++)
        {
            printf("%d ", vector[i]);
        }
    }

    else
    {
        for(i = 0 ; i < ((*Bn).n2) ; i++)
        {
            printf("%d ", vector[i]);
        }
    }
}

int main()
{
    quantidade *Bn = malloc(sizeof(quantidade));
    int i, j;

    scanf("%d", &i);
    (*Bn).n1 = i;

    int *vtp = (int*) malloc(sizeof(int)* (*Bn).n1);

    for(i = 0 ; i < (*Bn).n1 ; i++)
    {
        scanf("%d", &j);

        vtp[i] = j;
    }

    scanf("%d", &i);
    (*Bn).n2 = i;

    int *vtp2 = (int*) malloc( ((*Bn).n2) * sizeof(int));

    for(i = 0 ; i < (*Bn).n2 ; i++)
    {
        scanf("%d", &j);

        vtp2[i] = j;
    }

    vtp = soma(Bn, vtp, vtp2);
    mostradora(vtp, Bn);
    
    free(Bn);
    free(vtp);
    free(vtp2);

    return 0;
}
