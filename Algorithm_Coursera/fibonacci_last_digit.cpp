#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    std::vector<int> sequence(n+1);
    if (n<=1) { return n; }

    for (int i=0; i<=n; i++) {
        if (i == 0 || i == 1) {
            sequence[i] = i;
            continue;
        }

        sequence[i] = (sequence[i-2] + sequence[i-1]) % 10;
    }
    
    return sequence[n];
}

int main() {
    int n;
    std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
