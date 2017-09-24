#include <iostream>
#include <functional>
#include <memory>

enum type {less, greater};

template <typename T, type e>
void mergeSort(T arr[], int n)
{
    std::function<bool(T,T)> predicate;
    switch(e)
    {
        case greater:
            predicate = [] (T x, T y){return x > y ? true:false;};
            break;
            case less:
            predicate = [] (T x, T y){return x < y ? true:false;};
            break;
    }
    //Algorithm
    if(n > 1)
    {
        int const left_size = n / 2;
        int const right_size = n - left_size;

        // Передача диапазонов по ссылке
        mergeSort<T, e>(&arr[0], left_size);
        mergeSort<T, e>(&arr[left_size], right_size);

        /* Индексы:
		 * lidx - индекс в левом массиве
		 * ridx - индекс в правом массиве
         * idx  - индекс во временном массиве*/
         int lidx = 0, ridx = left_size, idx = 0;

         std::unique_ptr<T[]> tmp_arr(new T[n]);
         //Сортировка подмассивов
         while(lidx < left_size || ridx < n)
         {
             // Выбираем наименьший и кладем его во временный массив
             if(predicate(arr[lidx], arr[ridx]))
             {
                 tmp_arr[idx++] = std::move(arr[lidx]);
                 lidx++;
             }else{
                 tmp_arr[idx++] = std::move(arr[ridx]);
                 ridx++;
             }
                //Если подмассив пройден - соединить с соседним подмассивом
                //Затем выйти и заново отсортировать получившийся массив
                if(lidx == left_size)
                {
                    std::copy(std::make_move_iterator(&arr[ridx]), std::make_move_iterator(&arr[n]), &tmp_arr[idx]);
                    break;
                }
                if(ridx == n)
                {
                    std::copy(std::make_move_iterator(&arr[ridx]), std::make_move_iterator(&arr[n]), &tmp_arr[idx]);
                    break;
                }
         }
         //Скопировать отсортированную часть в изначальный массив
         std::copy(&tmp_arr[0], &tmp_arr[n], arr);
    }
    //Output
    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    {
        int arr[] = {41, 58, 32, 64, 85, 73, 29};
        mergeSort<int, greater> (arr, 7);
    }

    {
        int arr[] = {20, 28, 32, 4, 85, 73, 29};
        mergeSort<int, greater> (arr, 7);
    }

    {
        int arr[] = {1, 58, 5, 64, 85, 7, 29};
        mergeSort<int, greater> (arr, 7);
    }

    {
        int arr[] = {9, 58, 3, 64, 5, 73, 29};
        mergeSort<int, greater> (arr, 7);
    }

    return 0;
}