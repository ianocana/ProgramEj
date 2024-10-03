#include <stdio.h>
 
#define NUMERO_ESTUDIANTES 5
#define NUMERO_ASIGNATURAS 3
 
int main() {
    float notas[NUMERO_ESTUDIANTES][NUMERO_ASIGNATURAS];
    float promedio_por_estudiante[NUMERO_ESTUDIANTES];
    float promedio_por_asignatura[NUMERO_ASIGNATURAS];
    float nota_max_estudiante[NUMERO_ESTUDIANTES], nota_min_estudiante[NUMERO_ESTUDIANTES];
    float nota_max_asignatura[NUMERO_ASIGNATURAS], nota_min_asignatura[NUMERO_ASIGNATURAS];
    int estudiantes_aprobados[NUMERO_ASIGNATURAS], estudiantes_reprobados[NUMERO_ASIGNATURAS];
 
    // Inicializamos los contadores de aprobados y reprobados
    for (int i = 0; i < NUMERO_ASIGNATURAS; i++) {
        estudiantes_aprobados[i] = 0;
        estudiantes_reprobados[i] = 0;
    }
 
    // Ingreso de notas con validación
    for (int i = 0; i < NUMERO_ESTUDIANTES; i++) {
        for (int j = 0; j < NUMERO_ASIGNATURAS; j++) {
            do {
                printf("Ingrese la nota del estudiante %d en la asignatura %d (0-10): ", i + 1, j + 1);
                scanf("%f", &notas[i][j]);
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }
 
    // Cálculo del promedio, máxima y mínima por estudiante
    for (int i = 0; i < NUMERO_ESTUDIANTES; i++) {
        float suma = 0;
        nota_max_estudiante[i] = notas[i][0];
        nota_min_estudiante[i] = notas[i][0];
        for (int j = 0; j < NUMERO_ASIGNATURAS; j++) {
            suma += notas[i][j];
            if (notas[i][j] > nota_max_estudiante[i])
                nota_max_estudiante[i] = notas[i][j];
            if (notas[i][j] < nota_min_estudiante[i])
                nota_min_estudiante[i] = notas[i][j];
        }
        promedio_por_estudiante[i] = suma / NUMERO_ASIGNATURAS;
    }
 
    // Cálculo del promedio, máxima, mínima, aprobados y reprobados por asignatura
    for (int j = 0; j < NUMERO_ASIGNATURAS; j++) {
        float suma = 0;
        nota_max_asignatura[j] = notas[0][j];
        nota_min_asignatura[j] = notas[0][j];
        for (int i = 0; i < NUMERO_ESTUDIANTES; i++) {
            suma += notas[i][j];
            if (notas[i][j] > nota_max_asignatura[j])
                nota_max_asignatura[j] = notas[i][j];
            if (notas[i][j] < nota_min_asignatura[j])
                nota_min_asignatura[j] = notas[i][j];
            if (notas[i][j] >= 6)
                estudiantes_aprobados[j]++;
            else
                estudiantes_reprobados[j]++;
        }
        promedio_por_asignatura[j] = suma / NUMERO_ESTUDIANTES;
    }
 
    // Mostrar resultados
    for (int i = 0; i < NUMERO_ESTUDIANTES; i++) {
        printf("\nEstudiante %d: Promedio: %.2f, Nota Maxima: %.2f, Nota Minima: %.2f", i + 1, promedio_por_estudiante[i], nota_max_estudiante[i], nota_min_estudiante[i]);
    }
 
    for (int j = 0; j < NUMERO_ASIGNATURAS; j++) {
        printf("\n\nAsignatura %d: Promedio: %.2f, Nota Maxima: %.2f, Nota Minima: %.2f", j + 1, promedio_por_asignatura[j], nota_max_asignatura[j], nota_min_asignatura[j]);
        printf("\nEstudiantes Aprobados: %d, Estudiantes Reprobados: %d", estudiantes_aprobados[j], estudiantes_reprobados[j]);
    }
 
    return 0;
}