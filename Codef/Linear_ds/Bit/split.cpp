#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

// 31 bits input
/*
turn off last bit (1)
XOR = result
turn off last bit
turn off last bit
XOR = result + prev result
turn off last bit
turn off last bit
...
*/
long long num;

void process() {
    long long temp = num;
    bool toggle = true;
    long long a = 0;

    while (true) {
        long long temp2 = turnOffLastBit(temp);
        long long temp2_copy = temp2;
        if (temp == 0) {
            break;
        }

        if (toggle) {
            toggle = false;
            long long result = (temp2 ^= temp);
            a += result;
        }
        else {
            toggle = true;
        }
        temp = temp2_copy;
    }
    cout << a << " " << to_string(num-a) << endl;
}

int main() {
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }
        process();
    }
    return 0;
}
