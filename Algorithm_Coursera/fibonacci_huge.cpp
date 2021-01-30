#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1) {
        return n;
    }

    std::vector<int> modResults;
    modResults.push_back(0);
    modResults.push_back(1);
    // use a formula to find the nth mod result (add, compare, mod)
    for (int i=2; i<(m*m+2); i++) {
        int value = (modResults[i-2] + modResults[i-1]) % m;
        modResults.push_back(value);
        if (modResults[i] == 1 && modResults[i-1] == 0) {
            break;
        }
    }

    int sequenceLength = modResults.size() - 2;
    int nthTerm = n % sequenceLength;
    return modResults[nthTerm];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
