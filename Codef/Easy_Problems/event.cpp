#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    vector<vector<int> > genInfo;
    vector<pair<int,vector<int> > > hotelInfos; 
    string s;
    while (getline(cin, s)) {
        if (s.empty()) { break; }

        vector<int> result;
        istringstream iss(s);
        for (string s; iss >> s; ) {
            result.push_back(stoi(s));
        }

        genInfo.push_back(result);

        for (int i=0; i<result[2]; i++) {
            int price;
            vector<int> beds;
            cin >> price;
            string dummy;
            string s;
            getline(cin, dummy);
            getline(cin, s);
            istringstream iss(s);
            for (string s; iss >> s; ) {
                beds.push_back(stoi(s));
            }
            pair<int,vector<int> > hotel;
            hotel.first = price;
            hotel.second = beds;
            hotelInfos.push_back(hotel);
        }
    }

    int hotelTracker = 0;
    for (int i=0; i<genInfo.size(); i++) {
        int hotelNum = genInfo[i][2];
        int people = genInfo[i][0];
        int budget = genInfo[i][1];
        int minCost = -1;

        for (int j=hotelTracker; j<hotelNum+hotelTracker; j++) {
            pair<int,vector<int> > hotel = hotelInfos[j];
            for (int k=0; k<hotel.second.size(); k++) {
                if (hotel.second[k] >= people) {
                    if (hotel.first*people <= minCost || minCost == -1) {
                        minCost = hotel.first * people;
                    }
                }
            }
        }

        if (minCost == -1 || minCost > budget) {
            cout << "stay home" << endl;
        }
        else {
            cout << to_string(minCost) << endl;
        }
        
        hotelTracker += hotelNum;
    }
    return 0;
}