#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<vector<int> > salaries(t);
    for (int i=0; i<t; i++) {
        vector<int> employees(3);
        cin >> employees[0] >> employees[1] >> employees[2];
        salaries[i] = employees;
    }

    for (int i=0; i<t; i++) {
        vector<int> moneys = salaries[i];
        if ((moneys[0] > moneys[1] && moneys[0] < moneys[2]) || (moneys[0] < moneys[1] && moneys[0] > moneys[2])) {
            // first money 
            cout << "Case " << to_string(i+1) << ": " << to_string(moneys[0]) << endl;
        }
        else if ((moneys[1] > moneys[0] && moneys[1] < moneys[2]) || (moneys[1] < moneys[0] && moneys[1] > moneys[2])) {
            // second money
            cout << "Case " << to_string(i+1) << ": " << to_string(moneys[1]) << endl;
        }
        else if ((moneys[2] > moneys[1] && moneys[2] < moneys[0]) || (moneys[2] < moneys[1] && moneys[2] > moneys[0])) {
            // third money
            cout << "Case " << to_string(i+1) << ": " << to_string(moneys[2]) << endl;
        }
    }
    return 0;
}

