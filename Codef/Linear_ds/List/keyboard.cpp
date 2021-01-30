#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main() {
    string text;
    while (getline(cin, text)) {
        if (cin.eof()) break;
        
        list<char> output;
        list<char>::iterator it = output.begin();

        for (int i=0; i<text.size(); ++i) {
            if (text[i] == '[') {
                it = output.begin();
            }
            else if (text[i] == ']') {
                it = output.end();
            }
            else {
                output.insert(it, text[i]);
            }
        }

        string answer = "";
        for (it = output.begin(); it != output.end(); ++it) {
            answer += *it;
        }
        cout << answer << endl;
    }
    return 0;
}