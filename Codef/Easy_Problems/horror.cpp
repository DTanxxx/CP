#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int t;
    cin >> t;
    string dummy;
    getline(cin, dummy);
    vector<vector<int> > speeds;
    for (int i=0; i<t; i++) {
        string s;
        getline(cin, s);
        vector<int> result;
        istringstream iss(s);
        for (string s; iss >> s; ) {
            result.push_back(stoi(s));
        }
        speeds.push_back(result);
    }

    for (int i=0; i<speeds.size(); i++) {
        vector<int> children = speeds[i];
        int max = children[1];
        for (int j=1; j<children.size(); j++) {
            if (children[j] >= max) {
                max = children[j];
            }
        }
        cout << "Case " << to_string(i+1) << ": " << to_string(max) << endl;
    }
    
    return 0;
}