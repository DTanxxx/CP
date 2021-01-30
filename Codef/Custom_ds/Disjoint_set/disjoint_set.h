#include <vector>
using namespace std;

typedef vector<int> vi;

class UnionFind {
    private:
    vi p, rank;

    public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i=0; i<N; ++i) {
            p[i] = i;
        }
    }

    int findSet(int i) {
        if (p[i] == i) {
            return i;
        }
        p[i] = findSet(p[i]);
        return p[i];
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        int x = findSet(i);
        int y = findSet(j);
        if (x == y) {
            return;
        }
        if (rank[x] > rank[y]) {
            p[y] = x;
        }
        else {
            p[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    int size() {
        return p.size();
    }
};
