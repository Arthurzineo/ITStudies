#include <stdio.h>


void swap(int* a, int* b)
{
     int aux = *a;
     *a = *b;
     *b = aux;    
}


int partition(int arr[], int low, int high)
{
    // escolhendo a ultima posição como pivo
 int pi = arr[high];
 
 // Index do elemento menor e indica a pos correta do pi
 int i = low - 1; 
    int j;
    for(j = low; j <= high - 1; j++)
    {
            // Se o atual elemento for menor que o Pi 
            if(arr[j] < pi)
            {
            // incrmenta o index do menor elemento
               i++;   
               swap(&arr[i], &arr[j]);
            }
    } 
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
     if(low < high)
     {
      // pivot eh é o elemento usado para particionar o arr
      //a chamada da função partition vai colocar o pivot no index correto
      int pivot = partition(arr, low, high);
      
      // chamada recursiva da parte 1 do arr (Parte menor que pivot)
      quickSort(arr, low, pivot - 1);
      // chamada recursiva da parte 2 do arr ( parte maior que o pivot)
      quickSort(arr, pivot + 1, high);
     }    
}


int main()
{
    //declarando o array
    int arr[] = {100, 500, 20, 1, 1120, 50, 40, 1, 2, 5};
    
    //N = numero de elementos no array.
    // sizeoff(arr) = pega o tamanho total em bytes ocupados pelo arr.
    //já sizeof arr no index 0 pega o tamanho de bytes de apenas um idex, fazendo essa divisão
    //chegasse a numero de elementos. 
    // IMPORTANTE ESSE METODO NÃO FUNCIONA COM ALOCAÇÃO DINAMICA!
    int N = sizeof(arr) / sizeof(arr[0]);
    
    
    //Chamada da função 
    quickSort(arr, 0, N - 1);
    
    //print do array ordenado
    int i;
    for(i=0; i < N; i++)
    {
        printf("%d\n",arr[i]);      
    } 
    return 0;
}
