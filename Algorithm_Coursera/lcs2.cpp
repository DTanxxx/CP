#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;
using std::unordered_map;

int lcs2(vector<int> &a, vector<int> &b) {
  // array b acts as template array
  vector<vector<int> > matrix;
  for (int i=0; i<a.size(); i++) {
    vector<int> row;
    for (int j=0; j<b.size(); j++) {
      row.push_back(0);
    }
    matrix.push_back(row);
  }

  unordered_map<int,int> found_rows_and_cols;

  for (int i=0; i<a.size(); i++) {
    for (int j=0; j<b.size(); j++) {
      int maximum;
      int up;
      int left;
      int left_up = -1;
      if (i == 0) { 
        // first row
        up = 0; 
        left_up = 0;
      }
      else {
        up = matrix[i-1][j];
      }
      if (j == 0) {
        left = 0; 
        left_up = 0;
      }
      else {
        left = matrix[i][j-1];
      }

      if (left_up == -1) {
        // find the actual left_up element in matrix
        left_up = matrix[i-1][j-1];
      }

      maximum = std::max(up, left);

      if (a[i] == b[j]) {
        // same number
        if (found_rows_and_cols[j] == 1 || found_rows_and_cols[-i] == 1) {
          // found col or found row is true
          if (left == up && left_up == up) {
            // extend the common subseq length
            matrix[i][j] = maximum + 1;
            found_rows_and_cols[-i] = 1;
            found_rows_and_cols[j] = 1;
          }
          else {
            matrix[i][j] = maximum;
          }
        }
        else {
          matrix[i][j] = maximum + 1;
          found_rows_and_cols[-i] = 1;
          found_rows_and_cols[j] = 1;
        }
      }
      else {
        // not the same number
        matrix[i][j] = maximum;
      }
    }
  }

  return matrix[a.size()-1][b.size()-1];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
