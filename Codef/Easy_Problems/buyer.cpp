#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> duration;
    vector<pair<double,double> > loans;
    vector<vector<pair<int,double> > > deps;
    while (true) {
        int d;
        double pay;
        double owe;
        int n;
        cin >> d >> pay >> owe >> n;
        if (d < 0) {
            break;
        }
        duration.push_back(d);
        pair<double,double> loan;
        loan.first = pay;
        loan.second = owe;
        loans.push_back(loan);
        
        vector<pair<int,double> > dep(n);
        for (int i=0; i<n; i++) {
            pair<int,double> monthly;
            cin >> monthly.first >> monthly.second;
            dep[i] = monthly;
        }
        deps.push_back(dep);
    }

    for (int i=0; i<deps.size(); i++) {
        vector<pair<int,double> > loadPay = deps[i];
        pair<double,double> loan = loans[i];
        // double startVal = loan.second * (1 - loadPay[0].second);
        double owing = loan.second;
        double worth = (loan.second+loan.first) * (1-loadPay[0].second);
        int currMonth = 1;
        
        if (owing < worth) {
            cout << to_string(0) << " months" << endl;
            continue;
        }

        for (int j=1; j<duration[i]; j++) {
            owing -= (loan.second/duration[i]);
            if (j == loadPay.size()) {
                worth *= (1 - loadPay[j-1].second);
                j--;
            }
            else if (loadPay[j].first == currMonth) {
                worth *= (1 - loadPay[j].second);
            }
            else {
                worth *= (1 - loadPay[j-1].second);
                j--;
            }
            
            if (owing < worth) {
                if (currMonth > 1) {
                    cout << to_string(currMonth) << " months" << endl;
                }
                else {
                    cout << to_string(currMonth) << " month" << endl;
                }
                break;
            }
            currMonth++;
        }
    }
}