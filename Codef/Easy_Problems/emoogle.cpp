#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    vector<vector<int> > tcases;
    while (true) {       
        cin >> t;
        if (t == 0) {
            break;
        }
        vector<int> cases(t);
        for (int i=0; i<t; i++) {
            cin >> cases[i];
        }
        tcases.push_back(cases);
    }

    for (int i=0; i<tcases.size(); i++) {
        vector<int> cases = tcases[i];
        int score = 0;
        for (int j=0; j<cases.size(); j++) {
            if (cases[j] > 0) {
                score++;
            }
            else {
                score--;
            }
        }
        cout << "Case " << to_string(i+1) << ": " << score << endl;
    }
    return 0;   
}