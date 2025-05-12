#include <stdio.h>
#include <stdlib.h>


int verfBinCuad(FILE *archivo, int *tamano) {
    rewind(archivo);
    if (fscanf(archivo, "%d", tamano) != 1 || *tamano <= 0) {
        return 0;
    }

    int valor, contador = 0;
    while (fscanf(archivo, "%d", &valor) == 1) {
        if (valor != 0 && valor != 1) return 0;
        contador++;
    }

    return contador == (*tamano) * (*tamano);
}


int encDiagonalLarga(int **matriz, int tamano) {
    int maxCon = 0;

     for (int col = 0; col < tamano; col++) {
        int i = 0, j = col;
        int contador = 0;
        while (i < tamano && j < tamano) {
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

void imprMatriz(int **matriz, int tamano) {
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {

    FILE *archivo = fopen("matriz.txt", "r");
    if (!archivo) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    int tamano;
    if (!verfBinCuad(archivo, &tamano)) {
        printf("El archivo no contiene una matriz binaria y cuadrada válida.\n");
        fclose(archivo);
        return 1;
    }

    rewind(archivo);
    fscanf(archivo, "%d", &tamano);

    int **matriz = malloc(tamano * sizeof(int *));
    for (int i = 0; i < tamano; i++)
        matriz[i] = malloc(tamano * sizeof(int));

    for (int i = 0; i < tamano; i++)
        for (int j = 0; j < tamano; j++)
            fscanf(archivo, "%d", &matriz[i][j]);

    fclose(archivo);


int diagonal_mas_larga = encDiagonalLarga(matriz, tamano);
printf("La secuencia de 1s más grande en dirección paralela a la diagonal secundaria es: %d\n", diagonal_mas_larga);

    return 0;
}