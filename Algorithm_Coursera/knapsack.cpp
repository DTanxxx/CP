#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int optimal_weight(int W, const vector<int> &w) {
  // W is the capacity of the bag
  // w is the array of weights of each item
  // find the maximum weights of gold bars that fit into the bag

  vector<vector<int> > value_matrix;
  vector<vector<int> > state_matrix;

  for (int i=0; i<W; i++) {
    vector<int> value_row;
    vector<int> state_row;
    for (int j=0; j<w.size(); j++) {
      value_row.push_back(0);
      state_row.push_back(0);
    }
    value_matrix.push_back(value_row);
    state_matrix.push_back(state_row);
  }

  for (int i=0; i<W; i++) {
    for (int j=0; j<w.size(); j++) {
      int prev_row = i+1-w[j];
      int up;
      int left;
      int up_state;
      int left_state;
      if (i == 0) {
        up = 0;
        up_state = 0;
      }
      else {
        up = value_matrix[i-1][j];
        up_state = state_matrix[i-1][j];
      }
      if (j == 0) {
        left = 0;
        left_state = 0;
      }
      else {
        left = value_matrix[i][j-1];
        left_state = state_matrix[i][j-1];
      }

      if (prev_row >= 0) {
        int prev_value;
        int prev_state;
        if (prev_row == 0) {
          prev_value = 0;
          prev_state = 0;
        }
        else {
          prev_value = value_matrix[prev_row-1][j];
          prev_state = state_matrix[prev_row-1][j];
        }

        if (prev_state == true) {
          if (prev_value > up && prev_value > left) {
            value_matrix[i][j] = prev_value;
            state_matrix[i][j] = prev_state;
          }
          else {
            if (up > left) {
              value_matrix[i][j] = up;
              state_matrix[i][j] = state_matrix[i-1][j];
            }
            else if (up < left) {
              value_matrix[i][j] = left;
              state_matrix[i][j] = 0;
            }
            else {
              // up value equals to left value
              if (up_state == 0 || left_state == 0) {
                value_matrix[i][j] = up;
                state_matrix[i][j] = 0;
              }
              else {
                value_matrix[i][j] = up;
                state_matrix[i][j] = 1;
              }
            }
          }
        }
        else {
          int new_value = w[j] + prev_value;
          if (new_value > up && new_value > left) {
            value_matrix[i][j] = new_value;
            state_matrix[i][j] = 1;
          }
          else {
            if (up > left) {
              value_matrix[i][j] = up;
              state_matrix[i][j] = state_matrix[i-1][j];
            }
            else if (up < left) {
              value_matrix[i][j] = left;
              state_matrix[i][j] = 0;
            }
            else {
              // up value equals to left value
              if (up_state == 0 || left_state == 0) {
                value_matrix[i][j] = up;
                state_matrix[i][j] = 0;
              }
              else {
                value_matrix[i][j] = up;
                state_matrix[i][j] = 1;
              }
            }
          }
        }
      }
      else {
        // unable to fit the weight at current capacity
        if (up > left) {
          value_matrix[i][j] = up;
          state_matrix[i][j] = state_matrix[i-1][j];
        }
        else if (up < left) {
          value_matrix[i][j] = left;
          state_matrix[i][j] = 0;
        }
        else {
          // up value equals to left value
          if (up_state == 0 || left_state == 0) {
            value_matrix[i][j] = up;
            state_matrix[i][j] = 0;
          }
          else {
            value_matrix[i][j] = up;
            state_matrix[i][j] = 1;
          }
        }
      }
    }
  }
  return value_matrix[W-1][w.size()-1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
