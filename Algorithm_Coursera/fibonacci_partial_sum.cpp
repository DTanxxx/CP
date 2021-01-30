#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {

    std::vector<int> wholeLastDigits;
    wholeLastDigits.push_back(0);
    wholeLastDigits.push_back(1);

    for (long long i = 2; i <= 100*100+2; i++) {
        wholeLastDigits.push_back((wholeLastDigits[i-2] + wholeLastDigits[i-1] + 1) % 100);
        if (wholeLastDigits[i] == 1 && wholeLastDigits[i-1] == 0) {
            break;
        }
    }

    int recurringLength = wholeLastDigits.size() - 2;
    int nthTermLast = to % recurringLength;
    int nthTermFirst = 0;
    if (from == 0) {
        nthTermFirst = 0 % recurringLength;
    }
    else {
        nthTermFirst = (from-1) % recurringLength;
    }
    int final = wholeLastDigits[nthTermLast];
    int initial = wholeLastDigits[nthTermFirst];

    if (final > initial) {
        return (final - initial) % 10;
    }
    else if (final == initial) {
        return final % 10;
    }
    else {
        // check for negatives
        int negValue = final - initial;
        int actualValue = 10 - abs(negValue % 10);
        return actualValue;
    }
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
