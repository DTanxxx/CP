#include <iostream>
#include <string>

using namespace std;

int row;
int col;

int knights() {
    if (row*col == 1) {
        return 1;
    }
    else if (row*col == 2) {
        return 2;
    }
    else if (row == 2 && col == 2) {
        return 4;
    }
    else if (row == 1 || col == 1) {
        return row*col;
    }
    else {
        if (row == 2) {
            // 2xsomething
            int rows = 0;
            int how_many_4s = col/4;
            int remainder = col%4;
            if (remainder == 1) {
                rows += how_many_4s*2 + 1;
            }
            else if (remainder >= 2) {
                rows += how_many_4s*2 + 2;
            }
            else {
                rows += how_many_4s*2;
            }

            return 2*rows;
        }
        else if (col == 2) {
            // somethingx2
            int cols = 0;
            int how_many_4s = row/4;
            int remainder = row%4;
            if (remainder == 1) {
                cols += how_many_4s*2 + 1;
            }
            else if (remainder >= 2) {
                cols += how_many_4s*2 + 2;
            }
            else {
                cols += how_many_4s*2;
            }

            return 2*cols;
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
            return num * odd_rows + (row-num) * even_rows;
        }
    }
}

int main() {
    while (scanf("%d %d", &row, &col), (row || col)) {
        int num = knights();
        cout << num << " knights may be placed on a " << row << " row " << col << " column board." << endl;
    }
    return 0;
}
