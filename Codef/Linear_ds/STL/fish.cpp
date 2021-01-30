#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

int main() {
    string username;
    while (getline(cin, username)) {
        string copy = username;
        vector<string> perms(21);
        vector<vector<string> > table(26, vector<string>());
        
        for (int i=0; i<21; ++i) {
            if (i <= 10) {
                perms[10-i] = username;
                prev_permutation(username.begin(), username.end());
            }
            else {
                next_permutation(copy.begin(), copy.end());
                perms[i] = copy;
            }
        }
        
        int largest = 0;
        for (int i=0; i<21; ++i) {
            int min_diff = INT32_MAX;
            for (int j=0; j<perms[i].size()-1; ++j) {
                int diff = abs(perms[i][j+1] - perms[i][j]);
                if (diff < min_diff) {
                    min_diff = diff;
                }
            }
            if (min_diff > largest) {
                largest = min_diff;
                table[largest].push_back(perms[i]);
            }
        }
        cout << table[largest][0] << to_string(largest) << endl;
    }
    return 0;
}