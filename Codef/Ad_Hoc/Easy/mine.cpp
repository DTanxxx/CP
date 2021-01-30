#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<char> > field;
int field_num;

void process() {
    cout << "Field #" << to_string(field_num) << ":" << endl;
    for (int i=0; i<field.size(); ++i) {
        vector<char> row = field[i];
        vector<string> new_row;
        for (int j=0; j<row.size(); ++j) {
            int mines = 0;
            if (row[j] == '*') {
                new_row.push_back("*");
                continue;
            }

            if (j > 0) {
                // left
                if (i > 0) {
                    // top left
                    if (field[i-1][j-1] == '*') {
                        mines++;
                    }
                }
                if (i < field.size()-1) {
                    // bottom left
                    if (field[i+1][j-1] == '*') {
                        mines++;
                    }
                }
                // mid left
                if (row[j-1] == '*') {
                    mines++;
                }
            }
            if (j < row.size()-1) {
                // right
                if (i > 0) {
                    // top right
                    if (field[i-1][j+1] == '*') {
                        mines++;
                    }
                }
                if (i < field.size()-1) {
                    // bottom right
                    if (field[i+1][j+1] == '*') {
                        mines++;
                    }
                }
                // mid right
                if (row[j+1] == '*') {
                    mines++;
                }
            }
            if (i > 0) {
                // mid top
                if (field[i-1][j] == '*') {
                    mines++;
                }
            }
            if (i < field.size()-1) {
                // mid bottom
                if (field[i+1][j] == '*') {
                    mines++;
                }
            }
            new_row.push_back(to_string(mines));
        }
        string s;
        for (int j=0; j<new_row.size(); ++j) {
            s += new_row[j];
        }
        cout << s << endl;
    }
}

int main() {
    int rows, cols;
    while (scanf("%d %d", &rows, &cols), (rows || cols)) {
        field.clear();
        field_num++;
        string dummy;
        getline(cin, dummy);
        for (int i=0; i<rows; ++i) {
            vector<char> r;
            string row;
            getline(cin, row);
            for (int j=0; j<row.size(); ++j) {
                r.push_back(row[j]);
            }
            field.push_back(r);
        }
        if (field_num > 1) {
            cout << endl;
        }
        process();
    }
    return 0;
}
