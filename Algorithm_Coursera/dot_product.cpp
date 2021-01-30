#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;
  while (a.size() != 0) {
    int maxA = a[0];
    int maxAIndex = 0;
    for (int i=0; i<a.size(); i++) {
      if (maxA < a[i]) {
        maxA = a[i];
        maxAIndex = i;
      }
    }
    // found max value in a
    a[maxAIndex] = a[a.size()-1];
    a.pop_back();

    // std::cout << maxA << std::endl;

    int maxB = b[0];
    int maxBIndex = 0;
    for (int i=0; i<b.size(); i++) {
      if (maxB < b[i]) {
        maxB = b[i];
        maxBIndex = i;
      }
    }
    // found max value in b
    b[maxBIndex] = b[b.size()-1];
    b.pop_back();

    // std::cout << maxB << std::endl;

    result += (long long)maxA * maxB;
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
