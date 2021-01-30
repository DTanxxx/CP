#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x, int lower, int upper) {
  // find element x in a

  if (lower > upper) {
    return -1;
  }

  // find the middle index
  int midIndex = (lower+upper)/2;
  if (a[midIndex] == x) { return midIndex; }

  if (a[midIndex] < x) {
    // middle value smaller than x, search upper half
    return binary_search(a, x, midIndex+1, upper);
  }
  else {
    // middle value larger than x, search lower half
    return binary_search(a, x, lower, midIndex-1);
  }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i], 0, a.size()-1) << ' ';
  }
}
