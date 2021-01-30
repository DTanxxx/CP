#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> merge(vector<int> a, vector<int> b, long long &numInversions) {
  // a is supposed to be smaller than b
  // every element in b that is smaller, we add one to the number of inversions
  vector<int> sorted;

  int j = 0;
  int k = 0;
  bool addB = false;
  bool addA = false;
  for (int i=0; i<a.size()+b.size(); i++) {
    if (j == a.size()) {
      // add rest of b from index k to sorted
      addB = true;
      break;
    }
    if (k == b.size()) {
      // add rest of a from index j to sorted
      addA = true;
      break;
    }

    if (b[k] < a[j]) {
      // element in b is smaller than a 
      sorted.push_back(b[k]);
      numInversions += (a.size()-j);
      k++;
    }
    else {
      sorted.push_back(a[j]);
      j++;
    }
  }

  if (addB) {
    for (int i=k; i<b.size(); i++) {
      sorted.push_back(b[i]);
    }
  }
  else if (addA) {
    for (int i=j; i<a.size(); i++) {
      sorted.push_back(a[i]);
    }
  }

  return sorted;
}

vector<int> merge_sort(vector<int> &a, int lower, int upper, long long &numInversions) {
  if (lower >= upper) {
    vector<int> result;
    result.push_back(a[lower]);
    return result;
  }

  int mid = (lower + upper) / 2;  
  vector<int> lowerHalf = merge_sort(a, lower, mid, numInversions);
  vector<int> upperHalf = merge_sort(a, mid+1, upper, numInversions);
  vector<int> resultArray = merge(lowerHalf, upperHalf, numInversions);

  return resultArray;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;

  vector<int> sorted = merge_sort(a, left, right, number_of_inversions);

  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
