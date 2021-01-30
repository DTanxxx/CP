#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::pair;

int main() {
    vector<int> counts;
    vector<pair<int,int> > dividers;
    vector<pair<int,int> > points;

    while (true) {
        // read input
        int k, n, m;
        std::cin >> k;
        if (k == 0) {
            break;
        }
        counts.push_back(k);
        std::cin >> n >> m;
        pair<int,int> divider;
        divider.first = n;
        divider.second = m;
        dividers.push_back(divider);

        for (int i=0; i<k; i++) {
            pair<int,int> point;
            int x;
            int y;
            std::cin >> x >> y;
            point.first = x;
            point.second = y;
            points.push_back(point);
        }
    }

    int pointIndex = 0;
    for (int i=0; i<counts.size(); i++) {
        pair<int,int> divider = dividers[i];
        int count = counts[i];
        int amount = count+pointIndex;
        for (int j=pointIndex; j<amount; j++) {
            pair<int,int> point = points[j];
            if (point.first < divider.first) {
                if (point.second > divider.second) {
                    // first quad
                    cout << "NO" << endl;
                }
                else if (point.second < divider.second) {
                    // third quad
                    cout << "SO" << endl;
                }
                else {
                    cout << "divisa" << endl;
                }
            }
            else if (point.first > divider.first) {
                if (point.second > divider.second) {
                    // second quad
                    cout << "NE" << endl;
                }
                else if (point.second < divider.second) {
                    // fourth quad
                    cout << "SE" << endl;
                }
                else {
                    cout << "divisa" << endl;
                }
            }
            else {
                cout << "divisa" << endl;
            }
            pointIndex++;
        }   
    }
    return 0;
}