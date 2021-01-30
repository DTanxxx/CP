#include <iostream>
#include <vector>
#include <iomanip>

using std::cout;
using std::endl;
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0000;
  int maxIndex = 0;
  int numItems = weights.size();
  std::vector<double> valueDensities; 

  for (int i=0; i<weights.size(); i++) {
    double valuePerWeight = (double)values[i]/weights[i];
    valueDensities.push_back(valuePerWeight);
  }

  double maxDensity = 0;
  for (int i=0; i<valueDensities.size(); i++) {
    if (valueDensities[i] > maxDensity) {
      maxDensity = valueDensities[i];
      maxIndex = i;
    }
  }

  if (capacity < weights[maxIndex]) {
    return maxDensity * capacity;
  }

  while (capacity > 0 && numItems > 0) {
    maxDensity = 0;
    for (int i=0; i<valueDensities.size(); i++) {
      if (valueDensities[i] > maxDensity) {
        maxDensity = valueDensities[i];
        maxIndex = i;
      }
    }




    
    if (capacity < weights[maxIndex]) {
      value += ((double)capacity * valueDensities[maxIndex]);
    }
    else {
      value += ((double)values[maxIndex]);
      valueDensities[maxIndex] = 0;
    }
    capacity -= weights[maxIndex];  

    numItems --; 
  }
  
  return (double)value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout << std::fixed;
  std::cout << std::setprecision(4);
  // std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
