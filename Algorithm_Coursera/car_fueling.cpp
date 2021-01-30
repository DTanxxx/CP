#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int currStation = 0;
    int numRefills = 0;
    int farthestStation = 0;

    while (currStation < stops.size()) {
        if (stops[currStation] - farthestStation <= tank) {
            currStation ++;
        }
        else {
            if (stops[0] > tank || stops[currStation] - stops[currStation-1] > tank) {
                return -1;
            }
            numRefills ++;
            int stationDist = stops[currStation-1];
            farthestStation = stationDist;
        }
    }

    int remainingDist = dist - farthestStation;
    if (remainingDist > (2*tank)) {
        return -1;
    }
    else if (remainingDist > tank) {
        numRefills ++;
    }

    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
