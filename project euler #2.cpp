#include<iostream>
int main()
{
    // Variables to keep track of Fibonacci numbers
    int previousFibNum1 = 0;
    int currentFibNum = 1;

    int fibNumSum = 0;

    while(currentFibNum <= 4000000)
    {
        // Add even fibonacci numbers
        fibNumSum += (currentFibNum % 2 == 0) ?
            currentFibNum : 0;

        // Update fibonacci numbers
        int previousFibNum2 = previousFibNum1;
        previousFibNum1 = currentFibNum;
        currentFibNum = previousFibNum2 + previousFibNum1;
    }

    std::cout << fibNumSum << "\n";
}
