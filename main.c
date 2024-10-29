/* se desea desarrollar un programa que me permita registrar personas, con nombre, edad 
estado civil y que permita buscar por edad y por estado civil*/
#include <stdio.h>
#include <string.h>
void IngresarDatosPersona (char nombres[5][30], int edad[5], char estado[5][30]);
void buscarxedad (char nombres[5][30], int edad[5]);
void buscarestado (char nombres[5][30], char estado[5][30],char estadoC[1][30]);
int main (int argc, char *argv[]) {
    char nombres[5][30], estado[5][30], edad[5],estadoC[1][30]; 
    IngresarDatosPersona(nombres[5][30],edad[5],estado[5][30]);
    buscarxedad (nombres[5][30], edad[5]);
    buscarestado (nombres[5][30], estado[5][30], estadoC[1][30]);
    return 0;
}
void IngresarDatosPersona (char nombres[5][30], int edad[5], char estado[5][30]){
   for (int i = 0; i < 5; i++)
   {
    printf("Ingrese el nombre de la persona %d \n", i+1);
    scanf("%s", &nombres[i]);

    printf("Ingrese la edad de la persona %d \n", i+1);
    scanf("%d", &edad[i]);

    printf ("Ingrese el estado civil de la persona %d \n", i+1);
    scanf("%s", &estado[i]);
   }
}

void buscarxedad (char nombres[5][30], int edad[5]){
    int edadp;
    printf("Ingrese la edad, el sistema mostrara todas las personas con dicha edad \n");
    scanf ("%d", edadp);
    for (int i = 0; i < 5; i++)
    {
        if (edad[i]==edadp)
        {
           printf("%s cuenta con %d \n", nombres[i], edad[i]);
        }
    }   
}

void buscarestado (char nombres[5][30], char estado[5][30],char estadoC[1][30]){
    printf("Ingrese el estado civil, el sistema mostrara todas las personas con dicho estado civil \n");
    scanf ("%s",estadoC[1]);
    for (int i = 0; i < 5; i++)
    { 
        if (strcmp (estado[i],estadoC[1])==0)
        {
            printf("%s esta %s \n", nombres[i], estado[i]);
        }
        
    }
}