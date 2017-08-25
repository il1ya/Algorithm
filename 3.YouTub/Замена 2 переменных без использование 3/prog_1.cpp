// первый способ
#include <iostream>
int main()
{
    int x = 5;
    int y = 7;

    x = x + y;
    y = x - y;

    x -= y;

    std::cout << x << " " << y;
    
    return 0;
}


// 2 способ с помощью логического оператора ^
#include <iostream>
int main()
{
    int x = 42;
    int y = 38;

    x = x ^ y;
    y = x ^ y;

    x ^= y;

    std::cout << x << " " << y;
    
    return 0;
}
