// Reference : https://codility.com/media/train/8-PrimeNumbers.pdf

#include <iostream>

bool isPrime(int n) {
  if (n <= 1) {
    return false;
  }
  if (n % 2 == 0) {
    return n == 2;
  }
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
    int x;
    while (std::cin >> x) {
        std::cout << x << (isPrime(x) ? " is " : " is not ") << "prime."
                  << std::endl;
    }
}
