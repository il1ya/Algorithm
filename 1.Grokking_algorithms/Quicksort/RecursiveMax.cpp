#include <iostream>
#include <vector>
int max(std::vector<int> arr){
    if(arr.size() == 2){
        return arr[0] > arr[1] ? arr[] : arr[1];
    }
    int subMax = max((arr, 1, arr.size()));
    return arr[0] > subMax ? arr[0] : subMax;
}

int main()
{
    std::vector<int> arr {1, 5, 10, 25, 16, 1};
}