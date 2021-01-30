#include <vector>
#include <iostream>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

int row, col;
AdjList eles;  // represents columns of non-zero elements

void process() {
    cout << col << " " << row << endl;
    for (int i=1; i<eles.size(); ++i) {
        if (eles[i].empty()) {
            // all zeros
            cout << 0 << endl;
            cout << endl;
            continue;
        }
        cout << eles[i].size();
        for (int j=0; j<eles[i].size(); ++j) {
            cout << " " << eles[i][j].second;
        }
        cout << endl;
        cout << eles[i][0].first;
        for (int j=1; j<eles[i].size(); ++j) {
            cout << " " << eles[i][j].first;
        }
        cout << endl;
    }
}

int main() {
    while (scanf("%d %d", &row, &col) != EOF) {
        eles.clear();
        eles.resize(col+1, *(new vii()));
        int row_c = row;
        while (row_c--) {
            // two lines
            int r;
            cin >> r;
            vector<int> col_inds;
            col_inds.clear();
            while (r--) {
                int i;
                cin >> i;
                col_inds.push_back(i);
            }
            for (int i=0; i<col_inds.size(); ++i) {
                int j;
                cin >> j;
                eles[col_inds[i]].push_back(*(new ii(j, row-row_c)));
            }
        }
        process();
    }
    return 0;
}
