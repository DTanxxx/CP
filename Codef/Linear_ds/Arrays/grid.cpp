#include <iostream>
#include <vector>

using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        string row;
        vector<string> grid;
        for (int i=0; i<3; ++i) {
            cin >> row;
            grid.push_back(row);
        }

        if (grid[0] == "000" && grid[1] == "000" && grid[2] == "000") {
            cout << to_string(-1) << endl;
            continue;
        }

        int index = 0;
        while (true) {
            index++;
            vector<string> new_grid;
            for (int i=0; i<3; ++i) {
                string new_row = "";
                for (int j=0; j<3; ++j) {
                    int up = 0;
                    int down = 0;
                    int left = 0;
                    int right = 0;
                    if (i>0) {
                        up = grid[i-1][j] - '0';
                    }
                    if (i<2) {
                        down = grid[i+1][j] - '0';
                    }
                    if (j>0) {
                        left = grid[i][j-1] - '0';
                    }
                    if (j<2) {
                        right = grid[i][j+1] - '0';
                    }
                    new_row += to_string((up+down+left+right)%2);
                }
                new_grid.push_back(new_row);
            }          

            if (new_grid[0] == "000" && new_grid[1] == "000" && new_grid[2] == "000") {
                cout << to_string(index-1) << endl;
                break;
            }
            grid = new_grid;
            new_grid.clear();
        }
    }
    return 0;
}