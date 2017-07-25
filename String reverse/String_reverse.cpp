// Алгоритм переворота строки (String reverse)
#include <iostream>
#include <cstring>   // strlen()
int main()
{
    char string[] = "Hello, world";
    int lenght = strlen(string);
    int temp, i, j;
    
    for(i = 0, j = lenght - 1; i < j; i++, j--)
    {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
    std::cout << string << std::endl;
    return 0;
}