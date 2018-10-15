#include<iostream>
int main()
{
    int sumMultiples = 0;
    for (int i = 0; i < 1000; ++i)
    {
        // Add i to sum if it is divisible by 3 or 5
        sumMultiples += ((i % 5 == 0) || (i % 3 == 0)) ?
            i : 0;
    }

    std::cout << sumMultiples << "\n";
}
