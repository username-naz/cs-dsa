#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     
 
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
 

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
 void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        swap(&arr[min_idx], &arr[i]);
    }
}
    
int main()
{
    int inputSize;
    scanf("%d", &inputSize);
    int input[inputSize];
    for(int i=0; i<inputSize;i++)
        input[i] = rand()%10000;
    
    clock_t start, end;
    long int t;
    start=clock();
    selectionSort(input, inputSize);
    end=clock();
    t=end-start;
    printf("Total elapsed time for selection sort: %f\n", (double)t/(double)CLOCKS_PER_SEC);
    
    start=clock();
    selectionSort(input, inputSize);
    end=clock();
    t=end-start;
    printf("Total elapsed time for selection sort(already sorted): %f\n", (double)t/(double)CLOCKS_PER_SEC);
    
    
    
    for(int i=0; i<inputSize;i++)
        input[i] = rand()%10000;

    start=clock();
    bubbleSort(input, inputSize);
    end=clock();
    t=end-start;
    printf("Total elapsed time for bubble sort sort: %f\n", (double)t/(double)CLOCKS_PER_SEC);
    
    start=clock();
    bubbleSort(input, inputSize);
    end=clock();
    t=end-start;
    printf("Total elapsed time for bubble sort(already sorted): %f\n", (double)t/(double)CLOCKS_PER_SEC);
    

    return 0;
}