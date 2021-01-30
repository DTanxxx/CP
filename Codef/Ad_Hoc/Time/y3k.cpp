#include <vector>
#include <iostream>

using namespace std;

/*
predict a date N days ahead of given date
N < 1000,000,000
given date is before year 3000
leap year = div 4 but not div 100, except div 400 -> if (div 400); else if (div 4 && not 100)

compute total days up to a given month stored in array
arrays for normal and leap year
find number of days given year has left 
if smaller then easy
else while loop and continue incrementing year until smaller than 365 or 366
*/

vector<int> days_up_to_month_norm;
vector<int> days_up_to_month_leap;
int d, m, y;
long long pred;

bool is_leap(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    else {
        return false;
    }
}

void next_months(long long days_left, int in_month, int in_year, bool leap) {
    int curr_month = in_month+1;
    if (leap) {
        while (days_left > (long long)(days_up_to_month_leap[curr_month]-days_up_to_month_leap[curr_month-1])) {
            days_left -= (long long)(days_up_to_month_leap[curr_month] - days_up_to_month_leap[curr_month-1]);
            curr_month++;
        }
        cout << to_string(days_left) << " " << to_string(curr_month) << " " << to_string(in_year) << endl;
    }
    else {
        while (days_left > (long long)(days_up_to_month_norm[curr_month]-days_up_to_month_norm[curr_month-1])) {
            days_left -= (long long)(days_up_to_month_norm[curr_month] - days_up_to_month_norm[curr_month-1]);
            curr_month++;
        }
        cout << to_string(days_left) << " " << to_string(curr_month) << " " << to_string(in_year) << endl;
    }
}

void next_years(long long days_left, int on_day, int in_month, int in_year) {
    int curr_year = in_year + 1;
    if (is_leap(curr_year)) {
        // leap
        if (366LL < days_left) {
            // next few years
            // NOTE: N is 10^9
            // which is about 10^6 years -> a loop
            while (true) {
                if (is_leap(curr_year)) {
                    days_left -= 366LL;
                    if (days_left <= 366LL) {
                        curr_year++;
                        break;
                    }
                }
                else {
                    days_left -= 365LL;
                    if (days_left <= 365LL) {
                        curr_year++;
                        break;
                    }
                }
                curr_year++;
            }
            // now we have curr_year and days_left
            if (is_leap(curr_year)) {
                // current year
                int target_month = 0;
                for (int i=1; i<days_up_to_month_leap.size(); ++i) {
                    if (days_up_to_month_leap[i] >= days_left) {
                        // found the month
                        target_month = i;
                        break;
                    }
                }
                int target_day = (long long)(days_up_to_month_leap[target_month]-days_up_to_month_leap[target_month-1]-(days_up_to_month_leap[target_month]-days_left));
                cout << to_string(target_day) << " " << to_string(target_month) << " " << to_string(curr_year) << endl;
            }
            else {
                int target_month = 0;
                for (int i=1; i<days_up_to_month_norm.size(); ++i) {
                    if (days_up_to_month_norm[i] >= days_left) {
                        // found the month
                        target_month = i;
                        break;
                    }
                }
                int target_day = (long long)(days_up_to_month_norm[target_month]-days_up_to_month_norm[target_month-1]-(days_up_to_month_norm[target_month]-days_left));
                cout << to_string(target_day) << " " << to_string(target_month) << " " << to_string(curr_year) << endl;
            }
        }
        else {
            // current year
            int target_month = 0;
            for (int i=1; i<days_up_to_month_leap.size(); ++i) {
                if (days_up_to_month_leap[i] >= days_left) {
                    // found the month
                    target_month = i;
                    break;
                }
            }
            int target_day = (long long)(days_up_to_month_leap[target_month]-days_up_to_month_leap[target_month-1]-(days_up_to_month_leap[target_month]-days_left));
            cout << to_string(target_day) << " " << to_string(target_month) << " " << to_string(curr_year) << endl;
        }
    }
    else {
        // norm
        if (365 < days_left) {
            // next few years
            while (true) {
                if (is_leap(curr_year)) {
                    days_left -= 366LL;
                    if (days_left <= 366LL) {
                        curr_year++;
                        break;
                    }
                }
                else {
                    days_left -= 365LL;
                    if (days_left <= 365LL) {
                        curr_year++;
                        break;
                    }
                }
                curr_year++;
            }
            // now we have curr_year and days_left
            if (is_leap(curr_year)) {
                // current year
                int target_month = 0;
                for (int i=1; i<days_up_to_month_leap.size(); ++i) {
                    if (days_up_to_month_leap[i] >= days_left) {
                        // found the month
                        target_month = i;
                        break;
                    }
                }
                int target_day = (long long)(days_up_to_month_leap[target_month]-days_up_to_month_leap[target_month-1]-(days_up_to_month_leap[target_month]-days_left));
                cout << to_string(target_day) << " " << to_string(target_month) << " " << to_string(curr_year) << endl;
            }
            else {
                int target_month = 0;
                for (int i=1; i<days_up_to_month_norm.size(); ++i) {
                    if (days_up_to_month_norm[i] >= days_left) {
                        // found the month
                        target_month = i;
                        break;
                    }
                }
                int target_day = (long long)(days_up_to_month_norm[target_month]-days_up_to_month_norm[target_month-1]-(days_up_to_month_norm[target_month]-days_left));
                cout << to_string(target_day) << " " << to_string(target_month) << " " << to_string(curr_year) << endl;
            }
        }
        else {
            // current year
            int target_month = 0;
            for (int i=1; i<days_up_to_month_norm.size(); ++i) {
                if (days_up_to_month_norm[i] >= days_left) {
                    // found the month
                    target_month = i;
                    break;
                }
            }
            int target_day = (long long)(days_up_to_month_norm[target_month]-days_up_to_month_norm[target_month-1]-(days_up_to_month_norm[target_month]-days_left));
            cout << to_string(target_day) << " " << to_string(target_month) << " " << to_string(curr_year) << endl;
        }
    }
}

void process() {
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        // leap
        int days_up_in_year = days_up_to_month_leap[m] - (days_up_to_month_leap[m]-days_up_to_month_leap[m-1]-d);
        int days_left_in_year = 366 - days_up_in_year;
        if (days_left_in_year < pred) {
            // next few years
            next_years(pred-(long long)days_left_in_year, d, m, y);
        }
        else {
            // current year
            if (days_up_to_month_leap[m]-days_up_to_month_leap[m-1]-d < pred) {
                // next few months
                next_months(pred-(long long)(days_up_to_month_leap[m]-days_up_to_month_leap[m-1]-d), m, y, true);
            }
            else {
                // current month
                cout << to_string((long long)d+pred) << " " << to_string(m) << " " << to_string(y) << endl;
            }
        }
    }
    else {
        // norm
        int days_up_in_year = days_up_to_month_norm[m] - (days_up_to_month_norm[m]-days_up_to_month_norm[m-1]-d);
        int days_left_in_year = 365 - days_up_in_year;
        if (days_left_in_year < pred) {
            // next few years
            next_years(pred-(long long)days_left_in_year, d, m, y);
        }
        else {
            // current year
            if (days_up_to_month_norm[m]-days_up_to_month_norm[m-1]-d < pred) {
                // next few months
                next_months(pred-(long long)(days_up_to_month_norm[m]-days_up_to_month_norm[m-1]-d), m, y, true);
            }
            else {
                // current month
                cout << to_string((long long)d+pred) << " " << to_string(m) << " " << to_string(y) << endl;
            }
        }
    }
}

int main() {
    days_up_to_month_norm.resize(13);
    days_up_to_month_leap.resize(13);
    for (int i=0; i<=12; ++i) {
        if (i == 0) {
            days_up_to_month_norm[i] = 0;
            days_up_to_month_leap[i] = 0;
        }
        else if (i == 1) {
            days_up_to_month_norm[i] = 31;
            days_up_to_month_leap[i] = 31;
        }
        else if (i == 2) {
            days_up_to_month_norm[i] = days_up_to_month_norm[i-1] + 28;
            days_up_to_month_leap[i] = days_up_to_month_leap[i-1] + 29;
        }
        else if (i < 8 && i % 2 != 0) {
            days_up_to_month_norm[i] = days_up_to_month_norm[i-1] + 31;
            days_up_to_month_leap[i] = days_up_to_month_leap[i-1] + 31;
        }
        else if (i < 8 && i % 2 == 0) {
            days_up_to_month_norm[i] = days_up_to_month_norm[i-1] + 30;
            days_up_to_month_leap[i] = days_up_to_month_leap[i-1] + 30;
        }
        else if (i >= 8 && i % 2 != 0) {
            days_up_to_month_norm[i] = days_up_to_month_norm[i-1] + 30;
            days_up_to_month_leap[i] = days_up_to_month_leap[i-1] + 30;
        }
        else if (i >= 8 && i % 2 == 0) {
            days_up_to_month_norm[i] = days_up_to_month_norm[i-1] + 31;
            days_up_to_month_leap[i] = days_up_to_month_leap[i-1] + 31;
        }
    }
    
    while (scanf("%lld %d %d %d", &pred, &d, &m, &y), (pred || d || m || y)) {
        process();
    }
    return 0;
}
