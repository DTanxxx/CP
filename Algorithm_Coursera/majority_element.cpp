#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

vector<int> partition3(vector<int> &a, int lower, int upper) {
  int x = a[lower];
  int j = lower;
  int k = lower;

  for (int i = lower + 1; i <= upper; i++) {
    if (a[i] < x) {
      j++;
      k++;
      swap(a[i], a[j]);
      swap(a[j], a[k]);      
    }
    else if (a[i] == x) {
      j++;
      swap(a[i], a[j]);
    }
  }

  swap(a[lower], a[j]);

  std::vector<int> indices;
  indices.push_back(k);
  indices.push_back(j);

  return indices;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  vector<int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0]);
  randomized_quick_sort(a, m[1] + 1, r);
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return 1;
  
  // implement quick sort

  randomized_quick_sort(a, 0, a.size()-1);

  int j = 0;
  for (int i=0; i<a.size(); i++) {
    if (i == 0) { continue; }

    if (a[i] != a[i-1]) {
      j = i;
    }

    if (i-j+1 > (int)(a.size()/2)) {
      return 1;
    }
  }
  return 0;
}

int get_majority_element_naive(vector<int> &a, int left, int right) {
  for (int i=0; i<a.size(); i++) {
    int count = 0;
    for (int j=0; j<a.size(); j++) {
      if (a[j] == a[i]) {
        count ++;
      }
    }
    if (count > (int)(a.size()/2)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1 && get_majority_element(a, 0, a.size()) != 0) << '\n';
}
