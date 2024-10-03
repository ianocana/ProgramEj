#include <stdio.h>

int main (int argc, char *argv[]) {

    float cal[6];
    float min=10, max=0, prom=0;
    for (int i = 0; i < 6; i++)
    {
        printf("Ingrese la calificacion %d: ",i);
        scanf("%f",&cal[i]);
        if (cal[i]>10 || cal[i]<0)
        {
            printf("El valor ingresado no es correcto, se debe volver a ingresar\n");
            i--;
        }
        
    }

    for (int i = 0; i < 6; i++)
    {
        if(cal[i]>max){
            max=cal[i];
        }
        if (cal[i]<min)
        {
            min=cal[i];
        }
        prom=prom+cal[i];
    }
    prom=prom/6;
    printf("La calificion mas alta es: %.2f\n",max);
    printf("La calificion mas baja es: %.2f\n",min);
    printf("El promedio es: %.2f\n",prom);

    return 0;
}