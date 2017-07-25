// Алгоритм нахождения факториала(произведение всех натуральных чисел от 1 до n включительно)
// 5 * 4 * 3 * 2 * 1 = 120;
#include <iostream>
int fact(int x)
{
    if(x == 1)
        return 1;
    return x * fact(x - 1);
}
int main()
{
    std::cout << fact(5) << std::endl;
    return 0;
}