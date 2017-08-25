#include <iostream>
// Сортировка выбором (Selection sort) 

void swap(int *xp, int *yp){
    int temp = *xp;
        *xp = *yp;
        *yp = temp;
}

void selectionSort(int arr[], int n){
    int i, j, min_idx;

    for(i = 0; i < n-1; i++){
        min_idx = i;
        for(j = i + 1; j < n; j++)
            if(arr[j] < arr[min_idx])
                min_idx = j;
    swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << std::endl;
}

int main()
{
    int arr[] {65, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    std::cout << "Sorted array: " << std::endl;
    printArray(arr, n);
    return 0;
}