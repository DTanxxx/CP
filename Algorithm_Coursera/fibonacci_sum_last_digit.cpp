#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
    // sum up the last digit of numbers
    if (n <= 1) {
        return n;
    }

    std::vector<int> lastDigits;
    lastDigits.push_back(0);
    lastDigits.push_back(1);

    for (long long i = 2; i <= 102; i++) {
        lastDigits.push_back((lastDigits[i-2] + lastDigits[i-1] + 1) % 10);
        if (lastDigits[i] == 1 && lastDigits[i-1] == 0) {
            break;
        }
    }

    int recurringLength = lastDigits.size() - 2;
    int nthTerm = n % recurringLength;
    return lastDigits[nthTerm];
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
