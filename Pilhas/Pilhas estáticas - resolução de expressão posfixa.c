#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define TAM_MAX 100

typedef struct PilhaC PilhaC;

struct PilhaC
{
    int item[TAM_MAX];
    int topo;
};

PilhaC* criar_pilha()
{
    PilhaC *p = (PilhaC*) malloc(sizeof(PilhaC));
    
    p->topo = -1;

    return p;
}

int pilha_cheia(PilhaC *p)
{
    if (p == NULL)
        return -1;
    else if (p->topo == (TAM_MAX - 1))
        return 1;
    else
        return 0;
}

int pilha_vazia(PilhaC *p)
{
    if (p == NULL)
        return -1;
    else if (p->topo == -1)
        return 1;
    else
        return 0;
}

int empilhar(PilhaC *p, int item)
{
    if (p == NULL)
        p = criar_pilha();
    
    if (!pilha_cheia(p))
    {
        p->topo++; 

        p->item[p->topo] = item; 

        return 1;
    }

    return 0; 
}

int desempilhar(PilhaC *p)
{
    int item;
    
    if (!pilha_vazia(p))
    {
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

void imprimir_pilha(PilhaC *p)
{
    PilhaC aux = *p;
    int item;
    
    while (!pilha_vazia(&aux))
    {
        item = desempilhar(&aux);

        printf("%d\n", item);
    }
}

void liberar_pilha(PilhaC *p)
{
    if (p != NULL)
        free(p);
}

int obter_posicao_topo(PilhaC *p)
{
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}

int calcula(char *str)
{
    PilhaC *p = criar_pilha();
    int i, j = strlen(str), aux1, aux2;
    
    for(i = 0 ; i < j ; i++)
    {
        if(str[i] >= 48 && str[i] <= 57)
        {
            aux1 = (str[i] - '0');
            empilhar(p, aux1);
        }
        
        else if(str[i] == 42)
        {
            aux1 = desempilhar(p);
            aux2 = desempilhar(p);
            empilhar(p, (aux1 * aux2));
        }
        
        else if(str[i] == 43)
        {
            aux1 = desempilhar(p);
            aux2 = desempilhar(p);
            empilhar(p, (aux1 + aux2));
        }
        
        else if(str[i] == 45)
        {
            aux1 = desempilhar(p);
            aux2 = desempilhar(p);
            empilhar(p, (aux2 - aux1));
        }
        
        else if(str[i] == 47)
        {
            aux1 = desempilhar(p);
            aux2 = desempilhar(p);
            empilhar(p, (aux2 / aux1));
        }
        
    }
    
    aux1 = desempilhar(p);
    liberar_pilha(p);
    
    return aux1;
}

int main() 
{
    char *str = malloc(100 *sizeof(char));
    
    scanf("%s", str);
    
    printf("%d\n", calcula(str));
    
    free(str);
    
    return 0;
}

