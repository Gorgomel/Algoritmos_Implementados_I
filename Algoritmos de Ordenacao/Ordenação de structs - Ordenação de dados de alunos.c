#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char* nome;
    char* curso;
    float coef;
}Aluno;

Aluno * scan(int n)
{
    Aluno *vet = malloc(n *sizeof(Aluno));
    int i;

    for(i = 0 ; i < n ; i++)
    {
        scanf("%d", &vet[i].matricula);

        vet[i].nome = malloc(50* sizeof(char));
        scanf("%s", vet[i].nome);

        vet[i].curso = malloc(50* sizeof(char));
        scanf("%s", vet[i].curso);

        scanf("%f", &vet[i].coef);
    }

    return vet;
}

void imprimir_vetor(Aluno *vet, int n)
{
    int i;

    for(i = 0 ; i < n ; i++)
    {
        printf("%s ", vet[i].nome);
        printf("%d ", vet[i].matricula);
        printf("%s ", vet[i].curso);
        printf("%.2f\n", vet[i].coef);
    }
}

void selectsort(Aluno *v, int n)
{
    Aluno aux;
    int i, j, p;
    
    for (i = 0 ; i < n -1 ; i++)
    {
        p = i;
    
        for (j = i +1 ; j < n ; j++)
        {
            if (v[j].nome[0] < v[p].nome[0])
                p = j;
                
            else if((v[j]).nome[0] == (v[p]).nome[0])
                if(v[j].matricula < v[p].matricula)
                    p = j;
        }
        
        if (p != i)
        {
            aux = v[i];
            v[i] = v[p];
            v[p] = aux;
        }
    }
}

int main()
{
    Aluno *vet ;
    int n;

    scanf("%d", &n);

    vet = scan(n);
    
    selectsort(vet, n);

    imprimir_vetor(vet, n);
    
    free(vet);

    return 0;
}

