#include <iostream>
#include <functional>

enum type {less, greater};

template <typename T, type e>
void insertSort(T arr[], int n){
    int passages = 0;
    std::function<bool(T, T)> predicate;
    switch(e)
    {
        case greater:
            predicate = [] (T x, T y){return x > y ? true:false;};
            break;
            case less:
            predicate = [] (T x, T y){return x < y ? true:false;};
            break;
    }
        // Algorithm
        for(int j = 1; j < n; j++)
        {
            T key = arr[j];
            int i = j - 1;
            while(i >= 0 && predicate(arr[i], key))
            {
                passages++;
                arr[i+1] = arr[i];
                i--;
            }
            arr[++i] = key;
            passages++;
        }

        // Output
        for(int i = 0; i < n; i++)
        {
            std::cout << arr[i] << ", ";
        }
        std::cout << "(" << passages << ")" << std::endl;
}

int main()
{
    {
        int arr[] = {41, 58, 32, 64, 85, 73, 29};
        insertSort<int, greater> (arr, 7);
    }

    {
        int arr[] = {20, 28, 32, 4, 85, 73, 29};
        insertSort<int, greater> (arr, 7);
    }

    {
        int arr[] = {1, 58, 5, 64, 85, 7, 29};
        insertSort<int, greater> (arr, 7);
    }

    {
        int arr[] = {9, 58, 3, 64, 5, 73, 29};
        insertSort<int, greater> (arr, 7);
    }

    return 0;
}