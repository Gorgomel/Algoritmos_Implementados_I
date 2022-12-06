#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Vetor Vetor;

struct Vetor
{
    int *v; 
    int n; 
    int q; 
};

static Vetor * scan(Vetor *v)
{
    int i;
    
    for(i = 0 ; i < v->n ; i++)
        scanf("%d", &v->v[i]);
    
    return v;
}

Vetor * iniciar(int n)
{
    Vetor *v = malloc(sizeof(Vetor));
    
    v->v = malloc(n *sizeof(int));
    v->n = n;
    
    v = scan(v);
    
    return v;
}

int inserir(Vetor *v, int x)
{
    v->v = realloc(v->v, (v->n +1) *sizeof(int));
    v->n += 1;
    v->v[v->n-1] = x;
    
    if(v->v[v->n-1] == x)
        return 1;
    
    else
        return 0;
}

Vetor * concatenar(Vetor *v1, Vetor *v2)
{
    Vetor *v3 = iniciar(v1->n + v2->n);
    int i, j;
    
    for(i = 0 ; i < v1->n ; i++)
        v3->v[i] = v1->v[i];
    
    for(i = i, j = 0 ; i < v3->n ; i++, j++)
        v3->v[i] = v2->v[j];
    
    return v3;
}
    
Vetor * soma(Vetor *v1, Vetor *v2)
{
    Vetor *v3;
    int i;
    
    if(v1->n > v2->n)
        v3 = iniciar(v1->n);
    
    else
        v3 = iniciar(v2->n);
    
    for(i = 0 ; i < v1->n && i < v2->n ; i++)
            v3->v[i] = v1->v[i] + v2->v[i];
    
    for(i = i ; i < v3->n ; i++)
    {
        if(v3->n == v1->n)
            v3->v[i] = v1->v[i];
        
        else if(v3->n == v2->n)
            v3->v[i] = v2->v[i];
    }
    
    return v3;
}

void imprimir(Vetor *v)
{
    int i;
       
    for(i = 0 ; i < v->n ; i++)
        printf("%d ", v->v[i]);
    
    printf("\n");
}

void free_vetor(Vetor *v)
{
    free(v->v);
    free(v);
}

int main() 
{
    Vetor *v1, *v2, *v3;
    int n;
    
    scanf("%d", &n);
    v1 = iniciar(n);
    
    scanf("%d", &n);
    v2 = iniciar(n);
    
    v3 = concatenar(v1, v2);
    imprimir(v3);
    
    v3 = soma(v1, v2);
    imprimir(v3);
    
    free_vetor(v1);
    free_vetor(v2);
    free_vetor(v3);
    
    return 0;
}

