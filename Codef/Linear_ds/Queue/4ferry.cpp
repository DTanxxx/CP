#include <queue>
#include <iostream>

using namespace std;

int l;
queue<int> left_cars;
queue<int> right_cars;

void process_cars() {
    int crosses = 0;
    int curr_side = 0;  // left
    while (!left_cars.empty() || !right_cars.empty()) {
        if (curr_side == 0) {
            int cars_length_entering = 0;
            while (!left_cars.empty()) {
                // fill left cars
                cars_length_entering += left_cars.front();
                if (cars_length_entering > l) {
                    // too many cars
                    break;
                }
                left_cars.pop();
            }
            crosses ++;
            curr_side = 1;
        }
        else if (curr_side == 1) {
            int cars_length_entering = 0;
            while (!right_cars.empty()) {
                // fill right cars
                cars_length_entering += right_cars.front();
                if (cars_length_entering > l) {
                    // too many cars
                    break;
                }
                right_cars.pop();
            }
            crosses ++;
            curr_side = 0;
        }
    }

    cout << crosses << endl;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        while (!left_cars.empty()) {
            left_cars.pop();
        }
        while (!right_cars.empty()) {
            right_cars.pop();
        }
        int m;
        cin >> l >> m;
        l *= 100;
        int car;
        string side;
        while (m--) {
            cin >> car >> side;
            if (side == "left") {
                left_cars.push(car);
            }
            else if (side == "right") {
                right_cars.push(car);
            }
        }
        process_cars();
    }
    return 0;
}