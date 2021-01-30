#include <iostream>
#include <vector>

using std::vector;

int main() {
    int n;
    std::cin >> n;
    
    vector<int> divisors;
    divisors.push_back(4);
    divisors.push_back(7);
    divisors.push_back(44);
    divisors.push_back(47);
    divisors.push_back(74);
    divisors.push_back(77);
    divisors.push_back(444);
    divisors.push_back(447);
    divisors.push_back(474);
    divisors.push_back(744);
    divisors.push_back(477);
    divisors.push_back(747);
    divisors.push_back(774);
    divisors.push_back(777);

    bool divisible = false;
    for (int i=0; i<divisors.size(); i++) {
        if (n % divisors[i] == 0 && !divisible) {
            divisible = true;
            std::cout << "YES" << std::endl;
        }
    }
    if (!divisible) {
        std::cout << "NO" << std::endl;
    }
    return 0;
}