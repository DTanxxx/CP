#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int get_change(int m) {
  vector<int> money(m+1);
  money[0] = 0;
  for (int i=1; i<=m; i++) {
    // 1, 3, 4 coins
    int coin1s = m+1;
    int coin3s = m+1;
    int coin4s = m+1;

    if (i >=1 ) {
      coin1s = money[i-1] + 1;
    }
    if (i >= 3) {
      coin3s = money[i-3] + 1;
    }
    if (i >= 4) {
      coin4s = money[i-4] + 1;
    }

    int min = std::min(coin1s, coin3s);
    int minimum = std::min(min, coin4s);
    money[i] = minimum;
  }

  return money[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
