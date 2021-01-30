#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<int> nums(n);
        for (int i=0; i<n; ++i) {
            cin >> nums[i];
        }   
        if (n == 1) {
            cout << "Jolly" << endl;
            continue;
        }
        vector<int> flags(n-1, 0);
        for (int i=0; i<n-1; ++i) {
            int diff = abs(nums[i+1]-nums[i]);
            if (diff <= n-1 && diff > 0) {
                flags[diff-1] = 1;
            }
        } 
        bool notJolly = false;
        for (int i=0; i<n-1; ++i) {
            if (flags[i] == 0) {
                notJolly = true;
            }
        }
        if (notJolly) {
            cout << "Not jolly" << endl;
        }
        else {
            cout << "Jolly" << endl;
        }
    }
    return 0;
}