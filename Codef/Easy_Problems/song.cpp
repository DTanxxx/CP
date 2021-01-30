#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {    
    int tc;
    string s;
    scanf("%d", &tc);
    vector<string> names;
    while (tc--) {
        cin >> s;
        names.push_back(s);
    }

    string song = "Happy birthday to you Happy birthday to you Happy birthday to Rujia Happy birthday to you";
    vector<string> result;
    istringstream iss(song);
    for (string s; iss >> s; ) {
        result.push_back(s);
    }

    if (names.size() <= 16) {
        for (int i=0; i<result.size(); ++i) {
            string person = names[i % names.size()];
            string word = result[i];
            cout << person << ": " << word << endl;
        }
    }
    else {
        int indexInSong = 0;
        for (int i=0; i<names.size(); ++i) {
            string person = names[i];
            string word = result[i % result.size()];
            indexInSong = i % result.size();
            cout << person << ": " << word << endl;
        }
        for (int i=indexInSong+1; i<result.size(); ++i) {
            string person = names[i-indexInSong-1];
            string word = result[i];
            cout << person << ": " << word << endl;
        }
    }
    return 0;
}