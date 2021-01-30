#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long int lcm_fast(long long int a, long long int b, long long int originalA, long long int originalB) {
  if (a > b) {
    // a larger than b
    if (a % b == 0) {
      return a;
    }
    else {
      return lcm_fast(a + originalA, b, originalA, originalB);
    }
  }
  else {
    if (b % a == 0) {
      return b;
    }
    else {
      return lcm_fast(a, b + originalB, originalA, originalB);
    }
  }
}

int main() {
  long long int a, b;
  std::cin >> a >> b;
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b, a, b) << std::endl;
  return 0;
}
