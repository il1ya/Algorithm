#include <iostream>
int main()
{
    char *x = "OneStr";
    char *y = "TwoString";

    x += 2 * (y - x);
    y -= (x - y);
    x -= (x - y) / 2;

    std::cout << x << " " << y;

    return 0;
}