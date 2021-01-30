#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<string> inst;
    
    while (t--) {
        string oper;
        int amount;
        cin >> oper;
        if (oper == "donate") {
            cin >> amount;
            inst.push_back(to_string(amount));
        }
        else {
            inst.push_back("report");
        }
    }

    int money = 0;
    for (int i=0; i<inst.size(); i++) {
        if (inst[i] == "report") {
            cout << to_string(money) << endl;
        }
        else {
            int amount = stoi(inst[i]);
            money += amount;
        }
    }
    return 0;
}