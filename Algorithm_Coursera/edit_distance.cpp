#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int edit_distance(const string &str1, const string &str2) {
  vector<vector<int> > matrix(str1.size()+1);

  for (int i=0; i<matrix.size(); i++) {
    matrix[i] = vector<int>(str2.size()+1);
  }

  // matrix constructed
  // progress through matrix row first
  for (int row=0; row<matrix.size(); row++) {
    for (int col=0; col<matrix[row].size(); col++) {
      if (row == 0 && col == 0) { 
        matrix[row][col] = 0;
        continue;
      }

      if (row == 0) {
        matrix[row][col] = matrix[row][col-1] + 1;
        continue;
      }

      if (col == 0) {
        matrix[row][col] = matrix[row-1][col] + 1;
        continue;
      }

      // horizontal move
      int insertion = matrix[row][col-1] + 1;
      // vertical move
      int deletion = matrix[row-1][col] + 1;
      // diagonal move
      int diagonal;
      if (str1[row-1] == str2[col-1]) {
        diagonal = matrix[row-1][col-1];
      }
      else {
        diagonal = matrix[row-1][col-1] + 1;
      }

      int min = std::min(insertion, deletion);
      int minimum = std::min(min, diagonal);
      matrix[row][col] = minimum;
    }
  }

  return matrix[str1.size()][str2.size()];

}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
