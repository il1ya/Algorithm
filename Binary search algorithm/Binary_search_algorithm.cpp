#include <iostream>
#include <vector>
#include <cmath> // pow()

// бинарный поиск.
int _bsearch(std::vector<int> numbers, int value)
{
    int size = numbers.size();
    int low = 0;
    int high = size - 1;

    while(low <= high)
    {
        int mid  = (low + high) / 2;
        if(value == numbers[mid])
        {
            std::cout << "Value " << value << " is loczted at index of " << mid << std::endl;
            return 0;
        }
        else if(value > numbers[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 1;
}

// поиск квадратного корня.
void square_brute_force(double a)
{
    double epicilon = 0.01;
    int numGuesses = 0;
    double ans = 0.0;
    while(abs(pow(ans, 2) - a) >= epicilon)
    {
        ans += 0.00001;
        numGuesses += 1;
    }
    if(abs(pow(ans, 2) - a) >= epicilon)
    {
        std::cout << "failed..." << numGuesses << std::endl;
    }
    else
    {
        std::cout << ans << " close to square root of " << a << " with " << numGuesses << " number of guesses" << std::endl;
    }
}

// бинарный поиск квадратного корня.
void square_bsearch(double a)
{
    double epicilon = 0.01;
    double low = 0.0;
    double high = a;
    int guesses = 0;
    double guess = (high + low) / 2.0;

    while(abs(pow(guess, 2) - a) >= epicilon)
    {
        if(pow(guess, 2) < a)
        {
            low = guess;
        }
        else
        {
            high = guess;
        }
        guess = (high + low) / 2.0;
        guesses += 1;
    }
    std::cout << guess << " is close enough to square root of " << a << ". Guesses: " << guesses << std::endl;
}
int main()
{
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // _bsearch(numbers, 3);
    // square_brute_force(41.12345678901);
     square_bsearch(41.12345678901);
    return 0;
}