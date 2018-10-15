#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    long long int number = 600851475143LL;
    long long int highestPrimeFactor = 0LL;
    long long int currentFactor = 2LL;
    while (number > highestPrimeFactor)
    {
        if (
            (number % currentFactor == 0) &&
            (currentFactor > highestPrimeFactor)
        )   // If the number we are on is a factor of the number and larger than previous factors
        {
            highestPrimeFactor = currentFactor;
            number /= currentFactor; // Make the number smaller, so it is easier to work with
        }
        else
        {
            ++currentFactor; // Increase the factor
        }
    }

    std::cout << highestPrimeFactor << "\n";
}
