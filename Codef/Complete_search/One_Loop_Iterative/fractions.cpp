#include <vector>
#include <string>
#include <iostream>
using namespace std;

// (x+y)/(x*y) = 1/k
// x = y/(y/k-1)
// x = y*k/(y-k)
// iterate y from k+1, check if x is integer

int k;
vector<pair<int,int> > valids;

void process() {
    int y = k+1;
    int x = 0;
    while (true) {
        if ((y*k)%(y-k) == 0) {
            // valid x and y
            x = y*k/(y-k);
            valids.push_back(*(new pair<int,int>(x, y)));// cout instead
        } 
        if (y == x) {
            break; 
        }
        y++;
    }
    cout << to_string(valids.size()) << endl;
    for (int i=0; i<valids.size(); ++i) {
        cout << "1/" << to_string(k) << " = 1/" << to_string(valids[i].first) << " + 1/" << to_string(valids[i].second) << endl;
    }
}

int main() {
    while (scanf("%d", &k) != EOF) {
        valids.clear();
        process();
    }
    return 0;
}
