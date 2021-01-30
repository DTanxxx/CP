#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

string abbrv(string longString) {
    int count = 0;
    for (int i=1; i<longString.size()-1; i++) {
        count ++;
    }
    return longString[0] + std::to_string(count) + longString[longString.size()-1];
}

int main() {
    int n;
    std::cin >> n;
    vector<string> strings(n);
    for (size_t i=0; i<strings.size(); i++) {
        std::cin >> strings[i];
    }

    for (int i=0; i<strings.size(); i++) {
        if (strings[i].size() > 10) {
            cout << abbrv(strings[i]) << endl;
        }
        else {
            cout << strings[i] << endl;
        }
    }
    return 0;
}