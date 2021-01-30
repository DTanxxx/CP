#include <math.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string hour;
string minute;

inline double round(double val) {
    if (val < 0) return ceil(val-0.5);
    return floor(val+0.5);
}

void angle() {
    int hr = stoi(hour);
    int mini;
    if (minute[0] == '0') {
        mini = minute[1]-'0';
    }
    else {
        mini = stoi(minute);
    }

    int big_angle = 360/12 * hr;
    int small_angle = 360/12/5 * mini;
    double offset = (double)(small_angle*30.0/360.0);
    double sum = abs((double)(big_angle-small_angle)+offset);
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(3);
    if (sum > 360/2) {
        sum = (double)360-sum;
    }
    cout << sum << endl;
}

int main() {
    string time;
    while (getline(cin, time)) {
        if (time == "0:00") {
            break;
        }
        string delimiter = ":";
        size_t pos = 0;
        string token;
        while ((pos = time.find(delimiter)) != string::npos) {
            token = time.substr(0, pos);
            hour = token;
            time.erase(0, pos+delimiter.length());
        }
        minute = time;
        angle();
    }
    return 0;
}
