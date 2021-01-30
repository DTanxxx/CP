#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/// VARIABLES ///
/*
N1 = number of coaches for a train
coaches = array storing the intended coach numbers for a train
to_break = boolean to check for whether this train is finished checking, or whether we have a 0 for coach number
current_coach = the current coach number already added to the station
station = a stack storing arriving coaches of a train
*/
int main() {
    int N1;
    cin >> N1;
    while (N1 != 0) { 
        while (true) {
            vector<int> coaches(N1);
            bool to_break = false;
            for (int i=0; i<N1; ++i) {
                cin >> coaches[i];
                if (coaches[0] == 0) {
                    to_break = true;
                    cout << endl;
                    break;
                }
            }
            if (to_break) {
                break;
            }

            // now we have an array of coaches
            stack<int> station;
            int current_coach = 0;
            for (int i=0; i<N1; ++i) {
                while (station.empty() || coaches[i] != station.top()) {
                    if (!station.empty() && station.top() > coaches[i]) {
                        to_break = true;
                        cout << "No" << endl;
                        break;
                    }
                    current_coach++;
                    station.push(current_coach); 
                }
                if (to_break) {
                    break;
                }
                station.pop();
            }
            if (station.empty()) {
                cout << "Yes" << endl;
            }
        }
        cin >> N1;
    }
    return 0;
}