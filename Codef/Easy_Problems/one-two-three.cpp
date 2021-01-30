#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {   
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i=0; i<n; i++) {
        cin >> words[i];
    }

    for (int i=0; i<n; i++) {
        string word = words[i];
        if (word.size() == 3) {
            // one or two
            if ((word[0] == 't' && word[2] == 'o')
            || (word[1] == 'w' && word[2] == 'o') 
            || (word[0] == 't' && word[1] == 'w')) {
                cout << to_string(2) << endl;
            }
            else {
                cout << to_string(1) << endl;
            }
        }
        else {
            cout << to_string(3) << endl;
        }
    }
    return 0;
}