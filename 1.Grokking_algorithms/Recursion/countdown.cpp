#include <iostream>
// рекурсия
void countdown(int i){
    std::cout << i;
    if(i <= 0){
        return;
    }else{
        countdown(i - 1);
    }
}

int main()
{
    countdown(5);
    return 0;
}