#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  vector<vector<vector<int> > > matrix;
  
  for (int i=0; i<a.size(); i++) {
    vector<vector<int> > plane;
    for (int j=0; j<b.size(); j++) {
      vector<int> row;
      for (int k=0; k<c.size(); k++) {
        row.push_back(0);
      }
      plane.push_back(row);
    }
    matrix.push_back(plane);
  }

  for (int i=0; i<a.size(); i++) {
    for (int j=0; j<b.size(); j++) {
      for (int k=0; k<c.size(); k++) {
        int up;
        int left;
        int out;
        int last_one = -1;
        if (k == 0) {
          left = 0;
          last_one = 0;
        }
        else {
          left = matrix[i][j][k-1];
        }
        if (j == 0) {
          up = 0;
          last_one = 0;
        }
        else {
          up = matrix[i][j-1][k];
        }
        if (i == 0) {
          out = 0;
          last_one = 0;
        }
        else {
          out = matrix[i-1][j][k];
        }

        if (last_one == -1) {
          last_one = matrix[i-1][j-1][k-1];
        }

        int max = std::max(std::max(up, left), out);

        if (a[i] == b[j] && a[i] == c[k]) {
          matrix[i][j][k] = last_one + 1;
        }
        else {
          matrix[i][j][k] = max;
        }
      }
    }
  }
  return matrix[a.size()-1][b.size()-1][c.size()-1];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
