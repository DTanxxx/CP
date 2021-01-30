#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int S, B;
    while (scanf("%d %d", &S, &B), (B || S)) {
        vector<pair<int,int> > soldiers(S);
        for (int i=0; i<S; ++i) {
            pair<int,int> buddies;
            if (S == 1) {
                buddies.first = -1;
                buddies.second = -1;
            }
            else if (i == 0) {
                 buddies.first = -1;
                 buddies.second = i+1;
            }
            else if (i == S-1) {
                buddies.first = i-1;
                buddies.second = -1;
            }
            else {
                buddies.first = i-1;
                buddies.second = i+1;
            }
            soldiers[i] = buddies;
        }

        int L, R;
        while (B--) {
            cin >> L >> R;
            int leftBuddy = soldiers[L-1].first;
            int rightBuddy = soldiers[R-1].second;

            string result = "";
            if (leftBuddy != -1) {
                soldiers[leftBuddy].second = rightBuddy;
                result += to_string(leftBuddy+1);
                result += " ";
            }
            else {
                result += "* ";
            }

            if (rightBuddy != -1) {
                soldiers[rightBuddy].first = leftBuddy;
                result += to_string(rightBuddy+1);
            }
            else {
                result += "*";
            }
            cout << result << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}