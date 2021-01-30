#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <vector>
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

/*
N dimensions cube
corner has weight = +ve integer < 256
neighbor corners if common edge
potency = weights of all neighboring corners

find two neighbor corners that have max sum of potencies and output the sum

INPUT: 
2^N corners
each corner's weight = 1 line
eg corners: (0,0,0), (0,0,1), (0,1,0), (0,1,1) etc
so binaries that increases by 1

each corner is an index of an array
index points to weight of that corner
number of edges per corner is N
each neighbor corner has binary 1 bit different from current corner

calculate potency of each corner by index -> binary, then for each bit in binary toggle 
new index is neighbour, sum up the weights and put in new array the potency
for each potency, find neighbors and for each pair calculate potency sum; find max potency for that point out of all neighbors
output sum
*/

int N;
vector<int> weights;
vector<int> potencies;

vector<int> neighbors(int corner) {
    vector<int> neighs;
    for (int i=0; i<N; ++i) {
        int copy_again = corner;
        // toggle bit at position i
        toggleBit(copy_again, i);
        // append to array
        neighs.push_back(copy_again);
    }
    return neighs;
}

void process() {
    int max = 0;
    for (int i=0; i<weights.size(); ++i) {
        vector<int> ns = neighbors(i);
        int potency = 0;
        for (int j=0; j<ns.size(); ++j) {
            potency += weights[ns[j]];
        }
        // potency for this corner
        potencies[i] = potency;
    }
    for (int i=0; i<potencies.size(); ++i) {
        vector<int> ns = neighbors(i);
        for (int j=0; j<ns.size(); ++j) {
            if (potencies[ns[j]]+potencies[i] > max) {
                max = potencies[ns[j]]+potencies[i];
            }
        }
    }
    cout << to_string(max) << endl;
}

int main() {
    while (scanf("%d", &N) != EOF) {
        weights.clear();
        potencies.clear();
        int num = pow(2, N);
        weights.resize(num);
        potencies.resize(num, 0);
        for (int i=0; i<num; ++i) {
            cin >> weights[i];
        }
        process();
    }
    return 0;
}
