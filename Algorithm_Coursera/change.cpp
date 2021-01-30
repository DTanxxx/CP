#include <iostream>

int get_change(int m) {
  int coins;

  int numTens = m/10;
  int remainderTen = m%10;
  
  int numFives = remainderTen/5;
  int remainderFive = remainderTen%5;

  int numOnes = remainderFive;

  coins = numTens + numFives + numOnes;

  return coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
