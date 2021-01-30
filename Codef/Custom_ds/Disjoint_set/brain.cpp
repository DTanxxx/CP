#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
blank line between two test cases -> use scanf as it ignores blank lines
*/

int slept;
int connections;
int years;
string awakes;
string connection;
vector<vector<int> > slepts;  // 1 = slept; 2 = awake
vector<int> awake_from_slept;  // store the ones awake(1) and ones slept(-1)

void process() {
    years = 0;
    slept -= 3;
    int slept_copy = slept;
    while (slept_copy > 0) {
        // iterate slepts and for each, check if it has >= 3 awakes
        bool incre_years = false;
        vector<int> temp = *(new vector<int>());
        int slept_before = slept_copy;

        for (int i=0; i<26; ++i) {
            if (awake_from_slept[i] == -1) {
                // one of slept areas
                for (int j=0; j<26; ++j) {
                    if (awake_from_slept[j] == 1 && slepts[i][j] == 1) {
                        slepts[i][j] = 2;
                    }
                }

                int awake_count = 0;
                for (int j=0; j<26; ++j) {
                    if (slepts[i][j] == 2) {
                        awake_count++;
                    }
                }
                if (awake_count >= 3) {
                    incre_years = true;
                    temp.push_back(i);
                    slept_copy--;
                }
            }
        }
        if (slept_before == slept_copy) {
            cout << "THIS BRAIN NEVER WAKES UP" << endl;
            return;
        }
        
        for (int i=0; i<temp.size(); ++i) {
            awake_from_slept[temp[i]] = 1;
        }
        if (incre_years) {
            years++;
        }
    }
    cout << "WAKE UP IN, " << to_string(years) << ", YEARS" << endl;
}

void inp() {
    scanf("%d", &connections);
    string dum;
    getline(cin, dum);
    getline(cin, awakes);
    awake_from_slept[awakes[0]-'A'] = 1;
    awake_from_slept[awakes[1]-'A'] = 1;
    awake_from_slept[awakes[2]-'A'] = 1; 

    while (connections--) {
        getline(cin, connection);
        if (awake_from_slept[connection[0]-'A'] != 1) {
            // area not awake nor slept, make it slept
            awake_from_slept[connection[0]-'A'] = -1;
        }
        if (awake_from_slept[connection[1]-'A'] != 1) {
            // area not awake nor slept, make it slept
            awake_from_slept[connection[1]-'A'] = -1;
        }
        // fill up slepts
        bool first = false;
        bool second = false;
        for (int i = 0; i < awakes.length(); ++i) {
            if (connection[0] == awakes[i]) {
                first = true;
            }
            if (connection[1] == awakes[i]) {
                second = true;
            }
        }
        if (!first) {
            // first area is slept
            if (!second) {
                // second area is slept
                slepts[connection[0] - 'A'][connection[1] - 'A'] = 1;
                slepts[connection[1] - 'A'][connection[0] - 'A'] = 1;
            }
            else {
                // second area is awake
                slepts[connection[0] - 'A'][connection[1] - 'A'] = 2;
            }
        }
        if (!second) {
            if (first) {
                // second area is awake
                slepts[connection[1] - 'A'][connection[0] - 'A'] = 2;
            }
        }
    }
}

int main() {
    slept = 0;
    // if first case
    while (scanf("%d", &slept) != EOF) {
        slepts.clear();
        awake_from_slept.clear();
        awake_from_slept.resize(26);
        slepts.resize(26, *(new vector<int>(26)));
        inp();  
        process();  
    }
    return 0;
}
