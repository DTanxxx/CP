#include <iostream>

int main() {
    long long weight;
    std::cin >> weight;
    
    if (weight >= 4) {
        if (weight % 2 == 0) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
    else {
        std::cout << "NO"  << std::endl;
    }
    return 0;
}