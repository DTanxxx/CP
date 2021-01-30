#include <iostream>
#include <vector>
using namespace std;

/*
- list A given
- list B first element correspond to second element of list A
*/

vector<int> A;
vector<long long> B;

void process() {
    int ans = 0;
    for (int i=1; i<A.size(); ++i) {
        int ele1 = A[i];
        int ele2 = 0;
        for (int j=i-1; j>=0; --j) {
            if (A[j] <= ele1) {
                ele2++;
            }
        }
        ans += ele2;
    }    
    cout << ans << endl;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int size;
        cin >> size;
        A.resize(size, 0);
        for (int i=0; i<size; ++i) {
            cin >> A[i];
        }
        process();
    }
    return 0;
}
