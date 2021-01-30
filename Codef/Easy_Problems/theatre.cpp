#include <iostream>

int main() {
    int a;
    int b;
    int c;
    std::cin >> a >> b >> c;
    
    int length;
    int width;
    if (a % c == 0) {
        length = a/c;
    }
    else {
        length = a/c + 1;
    }
    if (b % c == 0) {
        width = b/c;
    }
    else {
        width = b/c + 1;
    }

    std::cout << ((long long)length*width) << std::endl;

    return 0;
}