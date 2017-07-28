// быстрая сортировка

#include <iostream>
#include <stdlib.h> // qsort

int values[] = { 40, 10, 1000, 982, 3545, 29, 1};

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int main()
{
    qsort(values, 6, sizeof(int), compare);
    for(int i = 0; i < 6; i++)
        std::cout << values[i] << ' ';
    return 0;
}





/*
#include <iostream>
void quickSort(int arr[], int left, int right){
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while(i <= j){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <= j){
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if(left < j)
        quickSort(arr, left, j);
    if(i < right)
        quickSort(arr, i, right);
}

int main()
{
    int arr[10] {100, 20, 30, 600, 984};
    int arra = quickSort(arr, 5, 5);
    std::cout << arra;
    return 0;
}
*/


/*
#include <iostream>
#include <algorithm>

void print(int *a, int n)
{
    int i = 0;
    while(i < n){
        std::cout << a[i] << ",";
        i++;
    }
    std::cout << "\n";
}

int partition(int *arr, const int left, const int right) {
    const int mid = left + (right - left) / 2;
    const int pivot = arr[mid];
    // move the mid point value to the front.
    std::swap(arr[mid],arr[left]);
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while(i <= j && arr[i] <= pivot) {
            i++;
        }

        while(i <= j && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i - 1],arr[left]);
    return i - 1;
}

void quicksort(int *arr, const int left, const int right, const int sz){

    if (left >= right) {
        return;
    }


    int part = partition(arr, left, right);
    std::cout << "QSC:" << left << "," << right << " part=" << part << "\n";
    print (arr, sz);

    quicksort(arr, left, part - 1, sz);
    quicksort(arr, part + 1, right, sz);
}

int main() {
    int arr[8] = {110, 5, 10,3 ,22, 100, 1, 23};
    int sz = sizeof(arr)/sizeof(arr[0]);
    print(arr, sz);
    quicksort(arr, 0, sz - 1, sz);
    print(arr, sz);
    return 0;
}
*/