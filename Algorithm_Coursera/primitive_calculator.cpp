#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  sequence.push_back(n);

  vector<int> operators;
  operators.push_back(-1);

  vector<int> nums(n+1);
  nums[0] = 0;
  nums[1] = 0;

  for (int i=2; i<=n; i++) {
    int add1 = n+1;
    int times2 = n+1;
    int times3 = n+1;

    if (i > 1) {
      // try +1
      add1 = nums[i-1] + 1;
    }
    if (i % 2 == 0) {
      times2 = nums[i/2] + 1;
    }
    if (i % 3 == 0) {
      times3 = nums[i/3] + 1;
    }

    int min = std::min(add1, times2);
    int minimum = std::min(min, times3);
    nums[i] = minimum;

    if (add1 == minimum) {
      operators.push_back(1);
    }
    else if (times2 == minimum) {
      operators.push_back(2);
    }
    else if (times3 == minimum) {
      operators.push_back(3);
    }
  }

  int currentValue = n;
  int i = operators.size()-1;
  for (i; i>0; i--) {
    if (operators[i] == 1) {
      currentValue = currentValue - 1;
      sequence.push_back(currentValue);
    }
    else if (operators[i] == 2) {
      currentValue = currentValue / 2;
      sequence.push_back(currentValue);
      i = currentValue;
    }
    else if (operators[i] == 3) {
      currentValue = currentValue / 3;
      sequence.push_back(currentValue);
      i = currentValue;
    }
  }
  
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
