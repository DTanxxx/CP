#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <bitset>
#include <string>
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

bitset<1000001> bs;
bool noConf;

void process(int start, int end, int interval=0) {
    if (interval == 0) {
        // reg event
        for (int i=start; i<end; ++i) {
            if (bs[i] == 1) {
                noConf = false;
                break;
            }
            else {
                bs[i] = 1;
            }
        }
    }
    else {
        // rep event
        int curr_ind = start;
        bool to_break = false;
        while (curr_ind < bs.size()-1) {
            for (int i=curr_ind; i<curr_ind+end-start; ++i) {
                if (bs[i] == 1) {
                    noConf = false;
                    to_break = true;
                    break;
                }
                else {
                    bs[i] = 1;
                }
            }
            if (to_break) {
                break;
            }
            curr_ind += interval;
        }
    }
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m), (n || m)) {
        bs.reset();
        noConf = true;
        while (n--) {
            int start, end;
            cin >> start >> end;
            process(start, end);
        }
        while (m--) {
            int start, end, interval;
            cin >> start >> end >> interval;
            process(start, end, interval);
        }
        if (noConf) {
            cout << "NO CONFLICT" << endl;
        }
        else {
            cout << "CONFLICT" << endl;
        }
    }
    return 0;
}
