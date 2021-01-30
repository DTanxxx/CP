#include <queue>
#include <iostream>
using namespace std;

priority_queue<long long> pq;  // default max heap

void process() {
    long long ans = 0LL;
    while (pq.size() > 1) {
        // add 2 min numbers from pq
        long long n1 = pq.top()*-1LL;
        pq.pop();
        long long n2 = pq.top()*-1LL;
        pq.pop();
        long long sum = n1+n2;
        ans += sum;
        pq.push(sum*-1LL);
    }
    cout << ans << endl;
}

int main() {
    int n;
    while (scanf("%d", &n), (n)) {
        while (!pq.empty()) {pq.pop();}
        while (n--) {
            long long num;
            cin >> num;
            pq.push(num*-1LL);
        }
        process();
    }
    return 0;
}
