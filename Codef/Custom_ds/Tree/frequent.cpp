/*
segment tree
each node stores occurrence of the mode in a range

INPUT:
n, q <= 10^5
n = number of integers in non-decreasing values
followed by q lines containing a query each (range i..j)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
// typedef vector<ii> vii;

/*
ISSUE: need to adjust occurrences of different numbers after finding out the 
max occurrence between the two ranges
*/

class SegmentTree {
    private: 
    vi tree;
    vi A;
    vi occurrences;
    int n;
    int left(int i) { return i << 1; }
    int right(int i) { return (i << 1) + 1; }

    void initialise() {
        for (int i=0; i<A.size(); ++i) {
            if (i==0) {
                occurrences[i] = 1;
            }
            else {
                if (A[i-1] == A[i]) {
                    // same values
                    occurrences[i] = occurrences[i-1] + 1;
                }
                else {
                    // different
                    occurrences[i] = 1;
                }
            }
        }
    }

    void build(int i, int L, int R) {
        if (L == R) {
            tree[i] = L;
        }
        else {
            build(left(i), L, (L+R)/2);
            build(right(i), (L+R)/2+1, R);
            int ind1 = tree[left(i)];
            int ind2 = tree[right(i)];
            // int occurrence1 = tree[left(i)].second;
            // int occurrence2 = tree[right(i)].second;
            
            // check if values at ind1 and ind2 are the same
            // if (A[ind1] == A[ind2]) {
            //     tree[i] = *(new ii(ind1, occurrence1+occurrence2));
            // }
            // else {
            tree[i] = (occurrences[ind1] >= occurrences[ind2]) ? ind1 : ind2;
            // }
        }
    }

    int query(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return -1;
        if (L >= i && R <= j) return tree[p];

        int ind1 = query(left(p), L, (L+R)/2, i, j);
        int ind2 = query(right(p), (L+R)/2+1, R, i, j);

        if (ind1 == -1) return ind2;
        if (ind2 == -1) return ind1;
        return occurrences[ind1] >= occurrences[ind2] ? ind1 : ind2;
    }

    public:
    SegmentTree(const vi &_A) {
        if (_A.empty()) {
            return;
        }
        A = _A; 
        n = (int)A.size();
        tree.assign(4*n, 0);
        occurrences.assign(n, 0);
        initialise();
        build(1, 0, n-1);
    }

    int query(int i, int j) {
        return occurrences[query(1, 0, n-1, i, j)];
    }
};

int n, q;
int i, j;
vi A;
SegmentTree st(*(new vi()));

void process() {
    cout << to_string(st.query(i-1, j-1)) << endl;
}

int main() {
    while(scanf("%d", &n), n) {
        A.clear();
        A.resize(n, 0);
        // scanf q
        scanf("%d", &q);
        while (n--) {
            cin >> A[A.size()-n-1];
        }

        st = *(new SegmentTree(A));
        while (q--) {
            scanf("%d %d", &i, &j);
            process();
        }
    }
    return 0;
}
