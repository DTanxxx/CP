#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

int main() {
    int reqs, props;
    int propNum = 1;
    while (scanf("%d %d", &reqs, &props), (reqs || props)) {
        unordered_map<string, int> requirements;

        string dummy;
        getline(cin, dummy);
        int counter = reqs;
        while (counter--) {
            string req;
            getline(cin, req);
            requirements[req] = 1;
        }

        pair<double, string> bestPropComp;
        double bestPropPrice = numeric_limits<double>::infinity();
        bestPropComp.first = -1;
        
        int index = 1;
        int counter2 = props;
        while (counter2--) {
            string name;
            getline(cin, name);
            double price, reqsMet;
            cin >> price >> reqsMet;

            string dummy;
            getline(cin, dummy);
            int counter3 = reqsMet;
            while (counter3--) {
                string placeholder;
                getline(cin, placeholder);
            }

            double comp = (double)(reqsMet/(double)reqs);
            if (comp > bestPropComp.first) {
                bestPropComp.first = comp;
                bestPropComp.second = name;
                bestPropPrice = price;
            }
            else if (comp == bestPropComp.first) {
                if (price < bestPropPrice) {
                    bestPropComp.second = name;
                    bestPropPrice = price;
                }
            }
            index++;
        }

        if (propNum > 1) {
            cout << endl;
        }
        cout << "RFP #" << to_string(propNum) << endl;
        cout << bestPropComp.second << endl;
        propNum++;
    }
    return 0;
}
