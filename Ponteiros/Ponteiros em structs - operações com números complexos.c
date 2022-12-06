#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    float real;
    float img;
    float mod;

}complexo;

void atualizarcomp (complexo * pont, float estreal, float estrimage)
{
    (*pont).real = estreal;
    (*pont).img = estrimage;
    (*pont).mod = sqrt(estreal * estreal + estrimage * estrimage);
}

int main(){
    float estreal, estrimage;
    complexo *pont, comp;

    pont = &comp;

    scanf("%f", &estreal);
    scanf("%f", &estrimage);

    atualizarcomp(pont, estreal, estrimage);

    printf("%.1f", pont->real);
    if((*pont).img >= 0)
    {
        printf("+%.1fi", pont->img);
    }

    else
    {
        printf("%.1fi", pont->img);
    }

    if(pont->mod < 0)
    {
        pont->mod = pont->mod * -1;
        printf("\n%.1f\n", pont->mod);
    }

    else
    {
        printf("\n%.1f\n", pont->mod);
    }

    return 0;
}

