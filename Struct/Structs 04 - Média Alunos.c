#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int cod;
    char nome[255];
    float notas[3];
    float media;
}aluno_t;

int encontraMaiorP1(aluno_t aluno[], int n){
    int i, maior, aux = 0;

    maior = aluno[0].notas[0];
    for(i = 0 ; i < n ; i++)
    {
        if(aluno[i].notas[0] > maior)
        {
            maior = aluno[i].notas[0];
            aux = i;
        }
    }

    return aux;
}

void calculaMedia(aluno_t aluno[], int n)
{
    int i;

    for(i = 0 ; i < n ; i++)
    {
        aluno[i].media = (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2]) / 3;
    }
}

int encontraMaiorMedia(aluno_t aluno[], int n)
{
    int i, maior, aux = 0;

    maior = aluno[0].media;
    for(i = 0 ; i < n ; i++)
    {
        if(aluno[i].media > maior)
        {
            maior = aluno[i].media;
            aux = i;
        }
    }

    return aux;
}

int encontraMenorMedia(aluno_t aluno[], int n)
{
    int i, menor, aux = 0;

    menor = aluno[0].media;
    for(i = 0 ; i < n ; i++)
    {
        if(aluno[i].media < menor)
        {
            menor = aluno[i].media;
            aux = i;
        }
    }

    return aux;
}

int main(){
    int n, i, j;

    scanf("%d", &n);

    aluno_t aluno[n];

    for(i = 0 ; i < n ; i++)
    {
        scanf("%d", &aluno[i].cod);

        scanf("%s", &aluno[i].nome);

        scanf("%f", &aluno[i].notas[0]);
        scanf("%f", &aluno[i].notas[1]);
        scanf("%f", &aluno[i].notas[2]);

    }

    calculaMedia(aluno, n);
    for(i = 0 ; i < n ; i++)
    {
        if(aluno[i].media >= 6)
        {
            printf("Aprovado!\n");
        }

        else
        {
            printf("Reprovado!\n");
        }
    }

    j = encontraMaiorMedia(aluno, n);
    printf("O aluno com maior media e:");
    printf(" %d", aluno[j].cod);
    printf(" %s", aluno[j].nome);
    printf(" %.1f\n", aluno[j].media);

    j = encontraMenorMedia(aluno, n);
    printf("O aluno com menor media e:");
    printf(" %d", aluno[j].cod);
    printf(" %s", aluno[j].nome);
    printf(" %.1f\n", aluno[j].media);

    j = encontraMaiorP1(aluno, n);
    printf("O aluno com maior P1 e:");
    printf(" %d", aluno[j].cod);
    printf(" %s", aluno[j].nome);
    printf(" %.1f\n", aluno[j].notas[0]);

    return 0;
}


