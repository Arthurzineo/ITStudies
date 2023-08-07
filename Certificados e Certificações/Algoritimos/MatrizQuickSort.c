#include <stdio.h>

void swap(int* a, int* b) 
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int matriz[][4], int low, int high, int linha) 
{
    int pi = matriz[linha][high];
    int i = low - 1;
    int j;
    for (j = low; j <= high - 1; j++) 
    {
        if (matriz[linha][j] < pi) 
        {
            i++;
            swap(&matriz[linha][i], &matriz[linha][j]);
        }
    }
    swap(&matriz[linha][i + 1], &matriz[linha][high]);
    return (i + 1);
}

void quickSort(int matriz[][4], int low, int high, int linha) 
{
    if (low < high) 
    {
        int pivot = partition(matriz, low, high, linha);
        quickSort(matriz, low, pivot - 1, linha);
        quickSort(matriz, pivot + 1, high, linha);
    }
}

void ordenarLinhas(int matriz[][4], int linhas, int colunas) 
{
    if (linhas > 0) 
    {
        quickSort(matriz, 0, colunas - 1, linhas - 1);
        ordenarLinhas(matriz, linhas - 1, colunas);
    }
}

int main() 
{
    int matriz[4][4] = {{4, 3, 1, 7}, {11, 26, 5, 7}, {50, 3, 6, 7}, {11, 26, 5, 7}};
    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);
    ordenarLinhas(matriz, linhas, colunas);
    int i, j;
    for (i = 0; i < linhas; i++) 
    {
        for (j = 0; j < colunas; j++) 
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
