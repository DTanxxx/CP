#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> equations;
    
    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        equations.push_back(line);
    }
        
    for (int i=0; i<equations.size(); i++) {
        cout << equations[i] << endl;
    }

    return 0;
}