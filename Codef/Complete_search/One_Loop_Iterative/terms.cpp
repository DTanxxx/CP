#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
- array a given, as well as d
- find kth element in new array b
- array b produced by nth element in array a * d to get number of occurrences of that element in array b
*/

int i; // <=20
int d; // <=100000
int k; 
vector<int> coeffs; // ==i+1

void process() {
    int total = 0;
    int n = 0;
    int m = 1;
    while (true) {
        // number of occurrences of kth element
        total += m * d;
        if (total >= k) {
            n = m;
            break;
        }
        m++;
    }
    long long ans = 0;
    for (int m=0; m<coeffs.size(); ++m) {
        ans += (long long)coeffs[m] * (long long)pow(n, m);
    }
    cout << ans << endl;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        coeffs.clear();
        // each tc has 3 lines
        // first line: polynomial for An
        cin >> i;
        coeffs.resize(i+1, 0);
        for (int j=0; j<=i; ++j) {
            cin >> coeffs[j];
        }
        // second line: d; third line: k
        cin >> d >> k;
        process();
    }
    return 0;
}
