#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        cin >> n;
        string dummy;
        getline(cin, dummy);

        vector<string> insts(n);
        for (int i=0; i<n; ++i) {
            getline(cin, insts[i]);
        }

        int position = 0;
        vector<string> whattodo(n);
        for (int i=0; i<n; ++i) {
            string move = insts[i];
            if (move[0] == 'L') {
                position--;
                whattodo[i] = "L";
            }
            else if (move[0] == 'R') {
                position++;
                whattodo[i] = "R";
            }
            else {
                vector<string> result;
                istringstream iss(move);
                for (string s; iss >> s; ) {
                    result.push_back(s);
                }

                int num = stoi(result[result.size()-1]);
                string prev = whattodo[num-1];
                if (prev == "L") {
                    position--;
                    whattodo[i] = "L";
                }
                else if (prev == "R") {
                    position++;
                    whattodo[i] = "R";
                }
            }
        }
        cout << position << endl;
    }
    return 0;
}
