#include <iostream>
#include <cmath>

// note: isTriangular and isPentagonal based on Euler problems 42 and 44

bool isTriangular(unsigned long long x)
{
  unsigned long long n = sqrt(2*x);

  // if n is actually the right answer then t(n) = x
  unsigned long long check = n * (n + 1) / 2;
  return (x == check);
}

bool isPentagonal(unsigned long long x)
{
  unsigned long long n = (1 + sqrt(24*x + 1)) / 6;

  // if x was indeed a pentagonal number then our assumption P(n) = x must be true
  auto p_n = n * (3 * n - 1) / 2;
  return p_n == x;
}

int main()
{
//#define ORIGINAL
#ifdef ORIGINAL
  // 143 is the first number which is triangular, pentagonal and hexagonal
  for (unsigned int i = 144; ; i++)
  {
    unsigned int hexagonal = i * (2*i - 1);
    if (isPentagonal(hexagonal))
    {
      // found it !
      std::cout << hexagonal << std::endl;
      return 0;
    }
  }

#else

  // hexagonal numbers grow the fastest, triangular the slowest
  unsigned long long limit;
  unsigned int a, b;
  std::cin >> limit >> a >> b;

  // triangular and pentagonal at the same time
  if (a == 3 && b == 5)
  {
    // let's generate the sequence of all pentagonal numbers, check if triangular, too
    for (unsigned long long i = 1; ; i++)
    {
      auto pentagonal = i * (3*i - 1) / 2;
      if (pentagonal >= limit)
        break;

      if (isTriangular(pentagonal))
        std::cout << pentagonal << std::endl;
    }
  }
  // same idea for pentagonal and hexagonal numbers
  if (a == 5 && b == 6)
  {
    // let's generate the sequence of all hexagonal numbers, check if pentagonal, too
    for (unsigned long long i = 1; ; i++)
    {
      auto hexagonal = i * (2*i - 1);
      if (hexagonal >= limit)
        break;

      if (isPentagonal(hexagonal))
        std::cout << hexagonal << std::endl;
    }
  }

#endif
  return 0;
}
