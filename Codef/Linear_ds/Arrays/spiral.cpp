#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int SZ, P;
    while (scanf("%d %d", &SZ, &P), (SZ || P)) {
        for (int i=1; i<=SZ; i+=2) {
            if (i*i >= P) {
                // it is an i by i grid
                int upper_right_coord = (i-1)/2 + SZ/2 + 1;
                int current_X = upper_right_coord;
                int current_Y = upper_right_coord;
                int current_value = i*i;
                bool to_break = false;

                if (current_value == P) {
                    cout << "Line = " << to_string(current_Y) << ", column = " << to_string(current_X) << "." << endl;
                    break;
                }

                for (int down=1; down<i; ++down) {
                    current_Y--;
                    current_value--;
                    if (current_value == P) {
                        cout << "Line = " << to_string(current_Y) << ", column = " << to_string(current_X) << "." << endl;
                        to_break = true;
                        break;
                    }
                }
                
                for (int left=1; left<i; ++left) {
                    current_X--;
                    current_value--;
                    if (current_value == P) {
                        cout << "Line = " << to_string(current_Y) << ", column = " << to_string(current_X) << "." << endl;
                        to_break = true;
                        break;
                    }
                }

                for (int up=1; up<i; ++up) {
                    current_Y++;
                    current_value--;
                    if (current_value == P) {
                        cout << "Line = " << to_string(current_Y) << ", column = " << to_string(current_X) << "." << endl;
                        to_break = true;
                        break;
                    }
                }

                for (int right=1; right<i; ++right) {
                    current_X++;
                    current_value--;
                    if (current_value == P) {
                        cout << "Line = " << to_string(current_Y) << ", column = " << to_string(current_X) << "." << endl;
                        to_break = true;
                        break;
                    }
                }

                if (to_break) {
                    break;
                }
            }
        }
    }
    return 0;
}
