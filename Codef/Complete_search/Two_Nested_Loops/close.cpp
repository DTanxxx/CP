#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int m;
int query;
int caseNum;
vector<int> arr;

void process() {
    int diff = arr[1] + arr[0] - query;
    for (int i=0; i<arr.size()-1; ++i) {
        for (int j=i+1; j<arr.size(); ++j) {
            if (abs(arr[i] + arr[j] - query) < abs(diff)) {
                diff = arr[i] + arr[j] - query;
            }
        }
    }
    cout << "Closest sum to " << to_string(query) << " is " << to_string(diff + query) << "." << endl;
}

int main() {
    caseNum = 0;
    while (scanf("%d", &n), n) {
        caseNum++;
        arr.resize(n, 0);
        for (int i=0; i<n; ++i) {
            cin >> arr[i];
        }
        scanf("%d", &m);
        cout << "Case " << to_string(caseNum) << ":" << endl;
        while (m--) {
            cin >> query;
            process();
        }
    }
    return 0;
}
