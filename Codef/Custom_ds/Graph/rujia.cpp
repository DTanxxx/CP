#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

vector<vector<int> > num_pos;

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        num_pos.clear();
        num_pos.resize(1000001, *(new vector<int>()));
        int n_copy = n;
        while (n_copy--) {
            int i;
            cin >> i;
            num_pos[i].push_back(n-n_copy-1);
        }
        while (m--) {
            int k, num;
            cin >> k >> num;
            if (k > num_pos[num].size()) {
                cout << 0 << endl;
            }
            else {
                cout << num_pos[num][k-1]+1 << endl;
            }
        }
    }
    return 0;
}
