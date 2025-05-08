#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO 3

int encDiagonalLarga(int matriz[TAMANO][TAMANO]) {
    int maxCon = 0;

     for (int col = 0; col < TAMANO; col++) {
        int i = 0, j = col;
        int contador = 0;
        while (i < TAMANO && j < TAMANO) {
            if (matriz[i][j] == 1)
                contador++;
            else
                contador = 0;
            if (contador > maxCon)
                maxCon = contador;
            i++;
            j++;
        }
    }

     return maxCon;
}

void llenarMatriz(int matriz[TAMANO][TAMANO]) {                                                                             
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            matriz[i][j] = rand() % 2; // 0 o 1
        }
    }
}

void imprMatriz(int matriz[TAMANO][TAMANO]) {
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {

int matriz[TAMANO][TAMANO];

    srand(time(NULL)); 
    llenarMatriz(matriz);

printf("Matriz generada:\n");
imprMatriz(matriz);

int diagonal_mas_larga = encDiagonalLarga(matriz);
printf("La secuencia de 1s más grande en dirección paralela a la diagonal secundaria es: %d\n", diagonal_mas_larga);

    return 0;
}