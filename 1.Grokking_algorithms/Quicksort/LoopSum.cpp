#include <iostream>
#include <vector>
// суммирует все числа и возвращает сумму.
int sum(std::vector<int> arr){
    int total = 0;
    for(int x = 0; x < arr.size(); x++){
        total += arr[x];
    }
    return total;
}

int main()
{
    std::vector<int> arr {1,2,3,4};
    std::cout << sum(arr);
    return 0;
}