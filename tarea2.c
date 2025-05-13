#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(int arr[], int m) {
    for (int i = 0; i < m-1; i++)
        for (int j = 0; j < m-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}


void selectionSort(int arr[], int m) {
    int indice;
    for (int i = 0; i < m-1; i++) {
        indice = i;
        for (int j = i+1; j < m; j++)
            if (arr[j] < arr[indice])
                indice = j;
        swap(&arr[indice], &arr[i]);
    }
}


void crearArreglo(int arr[], int m) {
    for (int i = 0; i < m; i++)
        arr[i] = rand() % 10000; 
}


void copiarArreglo(int source[], int dest[], int m) {
    for (int i = 0; i < m; i++)
        dest[i] = source[i];
}

int main() {
    int m;
    printf("Tamaño del arreglo: ");
    scanf("%d", &m);

    int *arreglo1 = (int *)malloc(m * sizeof(int));
    int *arreglo2 = (int *)malloc(m * sizeof(int));

    srand(time(NULL));
    crearArreglo(arreglo1, m);
    copiarArreglo(arreglo1, arreglo2, m);

    clock_t inicio, final;
    double tiempoRend;

    printf("Arreglo original:\n");
    for (int i = 0; i < m; i++)
        printf("%d ", arreglo1[i]);
    printf("\n");
    printf("Arreglo copiado:\n");
    for (int i = 0; i < m; i++)
        printf("%d ", arreglo2[i]);
    printf("\n");

    inicio = clock();
    bubbleSort(arreglo1, m);
    final = clock();
    tiempoRend = ((double) (final - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de rendimiento Bubble Sort: %.5f segundos\n", tiempoRend);

    
    inicio = clock();
    selectionSort(arreglo2, m);
    final = clock();
    tiempoRend = ((double) (final - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de rendimiento Selection Sort: %.5f segundos\n", tiempoRend);

    free(arreglo1);
    free(arreglo2);

    return 0;
}