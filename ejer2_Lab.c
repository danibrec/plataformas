#include <stdio.h>
#define TAMANO 3

void imprMatriz(int matriz[TAMANO][TAMANO]) {
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[TAMANO][TAMANO] = {
        {4, 2, 6},
        {18, 15, 2},
        {9, 8, 10}
    };

    int suma[2 * TAMANO - 1] = {0};
    int suma2[2 * TAMANO - 1] = {0};

    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            suma[i - j + (TAMANO - 1)] += matriz[i][j];
        }
    }

    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            suma2[i + j] += matriz[i][j];
        }
    }

    printf("Matriz generada:\n");
    imprMatriz(matriz);

    printf("\nDiagonales (i - j):\n");
    for (int d = 0; d < 2 * TAMANO - 1; d++) {
        printf("Diagonal %d (suma = %d): ", d + 1, suma[d]);
        for (int i = 0; i < TAMANO; i++) {
            for (int j = 0; j < TAMANO; j++) {
                if ((i - j + (TAMANO - 1)) == d) {
                    printf("%d ", matriz[i][j]);
                }
            }
        }
        printf("\n");
    }

    printf("\nDiagonales (i + j):\n");
    for (int d = 0; d < 2 * TAMANO - 1; d++) {
        printf("Diagonal %d (suma = %d): ", d + 1, suma2[d]);
        for (int i = 0; i < TAMANO; i++) {
            for (int j = 0; j < TAMANO; j++) {
                if ((i + j) == d) {
                    printf("%d ", matriz[i][j]);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
