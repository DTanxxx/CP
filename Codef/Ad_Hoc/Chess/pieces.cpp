#include <string>
#include <iostream>

using namespace std;

string piece;
int row;
int col;

void max_pieces() {
    if (piece == "r") {
        cout << to_string(min(row, col)) << endl;
    }
    else if (piece == "K") {
        int rows = row/2;
        if (row%2!=0) {
            rows++;
        }
        int cols = col/2;
        if (col%2!=0) {
            cols++;
        }
        cout << to_string(rows*cols) << endl;
    }
    else if (piece == "Q") {
        if (row == col) {
            if (row == 1) {
                cout << to_string(1) << endl;
            }
            else if (row == 5) {
                cout << to_string(5) << endl;
            }
            else if (row <= 6) {
                cout << to_string(row-1) << endl;
            }
            else {
                cout << to_string(row) << endl;
            }
        }
        else {
            cout << to_string(min(row, col)) << endl;
        }
    }
    else if (piece == "k") {
        if (row*col == 1) {
            cout << to_string(1) << endl;
        }
        else if (row*col == 2) {
            cout << to_string(2) << endl;
        }
        else if (row == 2 && col == 2) {
            cout << to_string(4) << endl;
        }
        else {
            if (row == 2) {
                // 2xsomething
                int odd_rows = col/2;
                if (col%2 != 0) {
                    odd_rows++;
                }
                cout << to_string(2*odd_rows) << endl;
            }
            else if (col == 2) {
                // somethingx2
                int odd_cols = row/2;
                if (row%2 != 0) {
                    odd_cols++;
                }
                cout << to_string(2*odd_cols) << endl;
            }
            else {
                int odd_rows = col/2;
                if (col%2 != 0) {
                    odd_rows++;
                }
                int col_odd = col-1;
                int even_rows = col_odd/2;
                if (col_odd%2 != 0) {
                    even_rows++;
                }
                int num = row/2;
                if (row%2 != 0) {
                    num++;
                }
                cout << to_string(num * odd_rows + (row-num) * even_rows) << endl;
            }
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        cin >> piece >> row >> col;
        max_pieces();
    }
    return 0;
}
