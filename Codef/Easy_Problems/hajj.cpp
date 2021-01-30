#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> names;
    string name;
    while (true) {
        cin >> name;
        if (name == "*") {
            break;
        }
        names.push_back(name);
    }

    for (int i=0; i<names.size(); i++) {
        if (names[i] == "Hajj") {
            cout << "Case " << to_string(i+1) << ": Hajj-e-Akbar" << endl;
        }
        else {
            cout << "Case " << to_string(i+1) << ": Hajj-e-Asghar" << endl;
        }
    }
    return 0;
}