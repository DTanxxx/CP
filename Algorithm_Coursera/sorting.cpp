#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort_naive(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  int m = partition2(a, l, r);

  randomized_quick_sort_naive(a, l, m - 1);
  randomized_quick_sort_naive(a, m + 1, r);
}

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

int main() {
  int n;
  // bool going = true;
  // while (going) {
  //   n = rand() % 10 + 1;

  //   std::cout << "size: " << n << std::endl;

  //   vector<int> a(n);
  //   vector<int> b(n);

  //   // std::cout << "HI" << std::endl;

  //   for (int i=0; i<n; i++) {
  //     int num = rand() % 10 + 1;
  //     a[i] = num;
  //     b[i] = num;
  //     std::cout << num << ' ';
  //   }

  //   std::cout << std::endl;

  //   // both arrays filled
  //   randomized_quick_sort(a, 0, a.size()-1);
  //   randomized_quick_sort_naive(b, 0, b.size()-1);

  //   // std::cout << "HI" << std::endl;

  //   for (int i=0; i<a.size(); i++) {
  //     std::cout << a[i] << ' ';
  //   }

  //   std::cout << std::endl;

  //   for (int i=0; i<b.size(); i++) {
  //     std::cout << b[i] << ' ';
  //   }

  //   std::cout << std::endl;

  //   for (int i=0; i<a.size(); i++) {
  //     // std::cout << a[i] << ' ' << b[i] << std::endl;
  //     if (a[i] != b[i]) {
  //       std::cout << a[i] << ' ' << b[i] << std::endl;
  //       going = false;
  //       break;
  //     }
  //   }
  // }

  std::cin >> n;

  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i]; 
  }

  randomized_quick_sort(a, 0, a.size() - 1);
  // randomized_quick_sort_naive(b, 0, b.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
