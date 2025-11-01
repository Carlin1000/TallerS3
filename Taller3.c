//Nicole Chancusig, Carlos Luis Viteri, Diego Ponguillo
#include <stdio.h>  
int main() {
    int NUM_ESTUDIANTES = 5;  
    int NUM_ASIGNATURAS = 3; 
    float calificaciones[5][3];
    float promedioEstudiantes[5];  
    float promedioAsignaturas[3]; 

    // Variables para encontrar valores máximos y mínimos
    float maxCalificacionEstudiante, minCalificacionEstudiante;  
    float maxCalificacionAsignatura, minCalificacionAsignatura; 

    // Contadores de aprobados y reprobados por cada asignatura
    int aprobados[3] = {0, 0, 0};    
    int reprobados[3] = {0, 0, 0};   

    // Variables de control para los ciclos
    int i, j;  // i = índice de estudiantes, j = índice de asignaturas
   
    printf("    Sistema de calificaciones de estudiantes\n");
    printf("Por favor, ingrese las calificaciones de cada estudiante (0-10).\n");
    
    for(i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("--- Estudiante %d ---\n", i + 1);
        for(j = 0; j < NUM_ASIGNATURAS; j++) {

            do {
                printf("  Calificacion en Asignatura %d (0-10): ", j + 1);
                scanf("%f", &calificaciones[i][j]);
                
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                    printf("  Error: La calificacion debe estar entre 0 y 10. Intente nuevamente.\n");
                }
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
        printf("\n");  // Separación entre estudiantes
    }
    
    // 1. Cálculo del promedio por estudiante
    for(i = 0; i < NUM_ESTUDIANTES; i++) {
        float suma = 0;  
        for(j = 0; j < NUM_ASIGNATURAS; j++) {
            suma = suma + calificaciones[i][j];
        }
    
        promedioEstudiantes[i] = suma / NUM_ASIGNATURAS;
    }
    
    // 2. Cálculo del promedio por asignatura
    for(j = 0; j < NUM_ASIGNATURAS; j++) {
        float suma = 0;  
        for(i = 0; i < NUM_ESTUDIANTES; i++) {
            suma = suma + calificaciones[i][j];
        }
        
        promedioAsignaturas[j] = suma / NUM_ESTUDIANTES;
    }
    
    printf("              Resultados\n");
    printf("1. Promedio de calificaciones de cada estudiante:\n");
    printf("----------------------------------------------------\n");
    for(i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("   Estudiante %d: %.2f\n", i + 1, promedioEstudiantes[i]);
    }
    
    printf("\n2. Promedio de calificaciones por asignatura:\n");
    for(j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("   Asignatura %d: %.2f\n", j + 1, promedioAsignaturas[j]);
    }

    printf("\n3. Calificacion mas alta y baja de cada estudiante:\n");
    printf("----------------------------------------------------\n");
    for(i = 0; i < NUM_ESTUDIANTES; i++) {
        maxCalificacionEstudiante = calificaciones[i][0];
        minCalificacionEstudiante = calificaciones[i][0];
        
        for(j = 1; j < NUM_ASIGNATURAS; j++) {
            if (calificaciones[i][j] > maxCalificacionEstudiante) {
                maxCalificacionEstudiante = calificaciones[i][j];
            }
            if (calificaciones[i][j] < minCalificacionEstudiante) {
                minCalificacionEstudiante = calificaciones[i][j];
            }
        }
        printf("   Estudiante %d - Maxima: %.2f, Minima: %.2f\n", 
                i + 1, maxCalificacionEstudiante, minCalificacionEstudiante);
    }
    
    
    printf("\n4. Calificacion mas alta y baja por asignatura:\n");
    printf("----------------------------------------------------\n");
    for(j = 0; j < NUM_ASIGNATURAS; j++) {
        maxCalificacionAsignatura = calificaciones[0][j];
        minCalificacionAsignatura = calificaciones[0][j];
        
        for(i = 1; i < NUM_ESTUDIANTES; i++) {
            if (calificaciones[i][j] > maxCalificacionAsignatura) {
                maxCalificacionAsignatura = calificaciones[i][j];
            }
            if (calificaciones[i][j] < minCalificacionAsignatura) {
                minCalificacionAsignatura = calificaciones[i][j];
            }
        }
        printf("   Asignatura %d - Maxima: %.2f, Minima: %.2f\n", 
                j + 1, maxCalificacionAsignatura, minCalificacionAsignatura);
    }
    
    printf("\n5. Estudiantes aprobados y reprobados por asignatura:\n");
    printf("------------------------------------------------------\n");
    
    for(j = 0; j < NUM_ASIGNATURAS; j++) {
        for(i = 0; i < NUM_ESTUDIANTES; i++) {
            if (calificaciones[i][j] >= 6.0) {
                aprobados[j]++; 
            } else {
                reprobados[j]++;  
            }
        }
        printf("   Asignatura %d:\n", j + 1);
        printf("      Aprobados (>= 6.0): %d estudiantes\n", aprobados[j]);
        printf("      Reprobados (< 6.0): %d estudiantes\n", reprobados[j]);
    }
    return 0;
}