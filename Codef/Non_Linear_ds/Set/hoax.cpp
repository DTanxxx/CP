#include <set>
#include <iostream>
using namespace std;

int n;
long long answer;
multiset<long long, greater <long long> > bills;

void process() {
    int k;
    cin >> k;
    while (k--) {
        long long bill;
        cin >> bill;
        bills.insert(bill);
    }
    multiset<long long, greater <long long> > :: iterator it;
    it = bills.end();
    it--;
    answer += *bills.begin()-*it;
    bills.erase(bills.begin());
    bills.erase(it);
}

int main() {
    while (scanf("%d", &n), (n)) {
        answer = 0;
        bills.clear();
        while (n--) {
            process();
        }
        cout << answer << endl;
    }
    return 0;
}
