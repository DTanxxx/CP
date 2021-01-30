#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;

  if (n == 0) {
    summands.push_back(0);
    return summands;
  }

  int numToSubtract = 1;
  while (true) {
    n -= numToSubtract;

    if (n == 0) {
      summands.push_back(numToSubtract);
      return summands;
    }

    if (n <= numToSubtract) {
      n += numToSubtract;
      numToSubtract++;
      continue;
    }

    summands.push_back(numToSubtract);
    numToSubtract++;
  }


}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
