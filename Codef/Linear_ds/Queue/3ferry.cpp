#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/*
INPUT:
test case tc
each test case has n (capacity), t (timer), m (num cars)
for m lines, each has arrival timer and start position

OUTPUT:
each car cout destination timer
blank line after one tc
*/

int capacity;
int time_to_travel;
int num_cars;
queue<pair<long long, int> > left_cars;
queue<pair<long long, int> > right_cars;
vector<int> finish_times;
unordered_map<long long, long long> map;

void ferry() {
    // start at L = 0; R = 1
    int pos = 0;
    long long timer = 0;
    while (!left_cars.empty() || !right_cars.empty()) {
        queue<pair<long long, int> > fer;
        bool idle = true;
        if (pos == 0) {
            while (!left_cars.empty() && left_cars.front().first <= timer && fer.size() < capacity) {
                // add car to ferry
                fer.push(left_cars.front());
                left_cars.pop();
                idle = false;
            }
            if (fer.empty()) {
                if (right_cars.empty()) {
                    timer = left_cars.front().first;
                    idle = true;
                }
                else {
                    long long other_side = right_cars.front().first;
                    if (left_cars.empty() || other_side < left_cars.front().first) {
                        // move to the other side to pick up
                        idle = false;
                        if (timer < other_side) { timer = other_side; }
                    }
                    else {
                        // stay at this side
                        timer = left_cars.front().first;
                        idle = true;
                    }
                } 
            }
        }
        else if (pos == 1) {
            while (!right_cars.empty() && right_cars.front().first <= timer && fer.size() < capacity) {
                // add car to ferry
                fer.push(right_cars.front());
                right_cars.pop();
                idle = false;
            }
            if (fer.empty()) {
                if (left_cars.empty()) {
                    timer = right_cars.front().first;
                    idle = true;
                }
                else {
                    long long other_side = left_cars.front().first;
                    if (right_cars.empty() || other_side < right_cars.front().first) {
                        // move to the other side to pick up
                        idle = false;
                        if (timer < other_side) { timer = other_side; }
                    }
                    else {
                        // stay at this side
                        timer = right_cars.front().first;
                        idle = true;
                    }
                } 
            }
        }

        if (idle) { continue; }
        // move ferry
        pos = abs(pos-1);
        timer += time_to_travel;
        while (!fer.empty()) {
            map[fer.front().second] = timer;
            fer.pop();
        } 
    }
    
    for (int i=0; i<finish_times.size(); ++i) {
        cout << map[finish_times[i]] << endl;
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        cin >> capacity >> time_to_travel >> num_cars;
        finish_times.clear();
        map.clear();
        while (!left_cars.empty()) { left_cars.pop(); }
        while (!right_cars.empty()) { right_cars.pop(); }
        
        int marker = 0;
        while (num_cars--) {
            pair<long long,int> c;
            c.second = marker;
            string pos;
            cin >> c.first >> pos;
            finish_times.push_back(marker);

            if (pos == "left") {
                left_cars.push(c);
            }
            else if (pos == "right") {
                right_cars.push(c);
            }
            marker++;
        }

        ferry();
        if (tc > 0) {
            cout << endl;
        }
    }
    return 0;
}
