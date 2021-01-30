#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<pair<int,string> > sets;
    for (int i=0; i<t; i++) {
        pair<int,string> set;
        cin >> set.first;
        cin >> set.second;
        sets.push_back(set);
    }

    string temp = "abacaba";
    for (int i=0; i<sets.size(); i++) {
        pair<int,string> set = sets[i];
        bool repeats = false;
        bool toNext = false;
        int startAt = -1;

        for (int j=0; j<set.first; j++) {
            bool equal = false;
            
            for (int k=j; k<j+7; k++) {
                // if (k == set.second.size()) {
                //     break;
                // }

                if (set.second[k] == '?') {
                    equal = true;
                }
                else if (set.second[k] == temp[k-j]) {
                    equal = true;
                }
                else if (set.second[k] != temp[k-j]) {
                    equal = false;
                    break;
                }
            }
            
            if (equal) {
                // found a subset
                if (repeats) {
                    cout << "NO" << endl;
                    toNext = true;
                    startAt = -1;
                    break;
                }
                else {
                    startAt = j;
                    repeats = true; 
                }             
            }
        }

        if (!toNext) {
            if (repeats) {
                cout << "YES" << endl;
                string output;
                output.append(set.second.substr(0, startAt));
                for (int i=startAt; i<startAt+7; i++) {
                    if (set.second[i] == '?') {
                        output.push_back(temp[i-startAt]);
                    }
                    else {
                        output.push_back(set.second[i]);
                    }
                }
                output.append(set.second.substr(startAt+7, set.second.size()-startAt-7));
                cout << output << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }




    return 0;
}