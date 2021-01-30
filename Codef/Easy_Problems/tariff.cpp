#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<vector<int> > calls;
    while (t > 0) {
        int n;
        cin >> n;
        vector<int> call(n);
        for (int i=0; i<n; ++i) {
            cin >> call[i];
        }
        calls.push_back(call);
        t--;
    }

    for (int i=0; i<calls.size(); ++i) {
        vector<int> call = calls[i];

        int fullJ = 0;
        int fullM = 0;
        for (int j=0; j<call.size(); ++j) {
            int sumM = 10;
            int sumJ = 15;
            sumM += call[j] / 30 * 10;
            sumJ += call[j] / 60 * 15;
            fullJ += sumJ;
            fullM += sumM;
        }

        if (fullJ < fullM) {
            cout << "Case " << to_string(i+1) << ": Juice " << to_string(fullJ) << endl;
        }
        else if (fullM < fullJ) {
            cout << "Case " << to_string(i+1) << ": Mile " << to_string(fullM) << endl;
        }
        else {
            cout << "Case " << to_string(i+1) << ": Mile Juice " << to_string(fullJ) << endl;
        }
    }
    return 0;
}