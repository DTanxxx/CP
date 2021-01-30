#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b) {
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

vector<int> merge_sort(vector<int> &a, int lower, int upper) {
  if (lower >= upper) {
    vector<int> result;
    result.push_back(a[lower]);
    return result;
  }

  int mid = (lower + upper) / 2;  
  vector<int> lowerHalf = merge_sort(a, lower, mid);
  vector<int> upperHalf = merge_sort(a, mid+1, upper);
  vector<int> resultArray = merge(lowerHalf, upperHalf);

  return resultArray;
}

pair<int,vector<int> > optimal_weight(int W, const vector<int> &w) {
  // W is the capacity of the bag
  // w is the array of weights of each item
  // find the maximum weights of gold bars that fit into the bag

  vector<vector<int> > value_matrix;
  vector<vector<int> > state_matrix;
  vector<vector<vector<int> > > values_used;

  for (int i=0; i<W; i++) {
    vector<int> value_row;
    vector<int> state_row;
    vector<vector<int> > values_used_row;
    for (int j=0; j<w.size(); j++) {
      value_row.push_back(0);
      state_row.push_back(0);
      vector<int> values;
      values_used_row.push_back(values);
    }
    value_matrix.push_back(value_row);
    state_matrix.push_back(state_row);
    values_used.push_back(values_used_row);
  }

  for (int i=0; i<W; i++) {
    for (int j=0; j<w.size(); j++) {
      int prev_row = i+1-w[j];
      int up;
      int left;
      int up_state;
      int left_state;
      vector<int> up_used_values;
      vector<int> left_used_values;
      if (i == 0) {
        up = 0;
        up_state = 0;
        vector<int> empty;
        up_used_values = empty;
      }
      else {
        up = value_matrix[i-1][j];
        up_state = state_matrix[i-1][j];
        up_used_values = values_used[i-1][j];
      }
      if (j == 0) {
        left = 0;
        left_state = 0;
        vector<int> empty;
        left_used_values = empty;
      }
      else {
        left = value_matrix[i][j-1];
        left_state = state_matrix[i][j-1];
        left_used_values = values_used[i][j-1];
      }

      if (prev_row >= 0) {
        int prev_value;
        int prev_state;
        vector<int> prev_used_values;
        if (prev_row == 0) {
          prev_value = 0;
          prev_state = 0;
          vector<int> empty;
          prev_used_values = empty;
        }
        else {
          prev_value = value_matrix[prev_row-1][j];
          prev_state = state_matrix[prev_row-1][j];
          prev_used_values = values_used[prev_row-1][j];
        }

        if (prev_state == true) {
          if (prev_value > up && prev_value > left) {
            value_matrix[i][j] = prev_value;
            state_matrix[i][j] = prev_state;
            values_used[i][j] = prev_used_values;
          }
          else {
            if (up > left) {
              value_matrix[i][j] = up;
              state_matrix[i][j] = state_matrix[i-1][j];
              values_used[i][j] = up_used_values;
            }
            else if (up < left) {
              value_matrix[i][j] = left;
              state_matrix[i][j] = 0;
              values_used[i][j] = left_used_values;
            }
            else {
              // up value equals to left value
              if (up_state == 0 || left_state == 0) {
                value_matrix[i][j] = up;
                state_matrix[i][j] = 0;
                values_used[i][j] = left_used_values;
              }
              else {
                value_matrix[i][j] = up;
                state_matrix[i][j] = 1;
                values_used[i][j] = up_used_values;
              }
            }
          }
        }
        else {
          int new_value = w[j] + prev_value;
          if (new_value > up && new_value > left) {
            value_matrix[i][j] = new_value;
            state_matrix[i][j] = 1;
            prev_used_values.push_back(w[j]);
            values_used[i][j] = prev_used_values;
          }
          else {
            if (up > left) {
              value_matrix[i][j] = up;
              state_matrix[i][j] = state_matrix[i-1][j];
              values_used[i][j] = up_used_values;
            }
            else if (up < left) {
              value_matrix[i][j] = left;
              state_matrix[i][j] = 0;
              values_used[i][j] = left_used_values;
            }
            else {
              // up value equals to left value
              if (up_state == 0 || left_state == 0) {
                value_matrix[i][j] = up;
                state_matrix[i][j] = 0;
                values_used[i][j] = left_used_values;
              }
              else {
                value_matrix[i][j] = up;
                state_matrix[i][j] = 1;
                values_used[i][j] = up_used_values;
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
          values_used[i][j] = up_used_values;
        }
        else if (up < left) {
          value_matrix[i][j] = left;
          state_matrix[i][j] = 0;
          values_used[i][j] = left_used_values;
        }
        else {
          // up value equals to left value
          if (up_state == 0 || left_state == 0) {
            value_matrix[i][j] = up;
            state_matrix[i][j] = 0;
            values_used[i][j] = left_used_values;
          }
          else {
            value_matrix[i][j] = up;
            state_matrix[i][j] = 1;
            values_used[i][j] = up_used_values;
          }
        }
      }
    }
  }

  pair<int,vector<int> > result;
  result.first = value_matrix[W-1][w.size()-1];
  result.second = values_used[W-1][w.size()-1];
  return result;
}

int partition3(vector<int> &A) {
  vector<int> old_sorted = merge_sort(A, 0, A.size()-1);
  vector<int> sorted;
  for (int i=old_sorted.size()-1; i>=0 ; i--) {
    sorted.push_back(old_sorted[i]);
  }

  int sum = 0;
  for (int i=0; i<sorted.size(); i++) {
    sum += sorted[i];
  }
  if (sum % 3 != 0) {
    return 0;
  }

  // compare the value with sum/3
  // if not equal, then return 0
  // else, use the 'used values' returned and remove those values from the original array
  // then carry out the knapsack again
  // repeat 3 times
  vector<int> new_sorted = sorted;

  for (int k=0; k<3; k++) {
    pair<int,vector<int> > result = optimal_weight(sum/3, new_sorted);
    if (result.first == sum/3) {
      unordered_map<int,int> tracker;
      for (int i=0; i<result.second.size(); i++) {
        tracker[result.second[i]] = 100;
      }
      for (int i=0; i<sorted.size(); i++) {
        if (tracker[sorted[i]] == 100) {
          // reset map value and don't append element to new array
          tracker[sorted[i]] = 0;
        }
        else {
          new_sorted.push_back(sorted[i]);
        }
      }
    }
    else {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
