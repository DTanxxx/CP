#include <unordered_map>
#include <string>
using namespace std;

typedef unordered_map<string,string> us;
typedef unordered_map<string,int> ui;

class UnionFindString {
    private:
    us p;
    ui rank, set_size;

    public:
    UnionFindString() {
    }

    void addToSet(string s) {
        if (!inSet(s)) {
            // add to set
            p[s] = s;
            rank[s] = 0;
            set_size[s] = 1;
        }
    }

    bool inSet(string s) {
        if (p[s].length() > 0) {
            // in set
            return true;
        }
        else {
            return false;
        }
    }

    string findSet(string i) {
        if (p[i] == i) {
            return i;
        }
        p[i] = findSet(p[i]);
        return p[i];
    }

    bool isSameSet(string i, string j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(string i, string j) {
        string x = findSet(i);
        string y = findSet(j);
        if (x == y) {
            return;
        }
        if (rank[x] > rank[y]) {
            p[y] = x;
            set_size[x] += set_size[y];
        }
        else {
            p[x] = y;
            set_size[y] += set_size[x];
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    int setSize(string s) {
        return set_size[findSet(s)];
    }
};
