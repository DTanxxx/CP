#include <iostream>
#include <string>
#include <vector>
// #include "disjoint_set.h"
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

/* 
computers are nodes in a disjoint set
answer: whether two computers are in the same disjoint set
INPUT: blank line after tc and between tc
OUTPUT: num of YES and NO for each tc
*/

int TC;
string inp;
int comps;
UnionFind* network;
int s;
int f;

void process() {
    string c1 = "";
    string c2 = "";
    string computers = inp.substr(2, inp.length()-2);

    string delimiter = " ";
    size_t pos = 0;
    string token;
    while ((pos = computers.find(delimiter)) != string::npos) {
        token = computers.substr(0, pos);
        c1 = token;
        computers.erase(0, pos + delimiter.length());
    }
    c2 = computers;

    if (inp[0] == 'c') {
        // union
        // cout << to_string(network->size()) << endl;
        network->unionSet(stoi(c1)-1, stoi(c2)-1);
    }
    else if (inp[0] == 'q') {
        // check if in same set
        if (network->isSameSet(stoi(c1)-1, stoi(c2)-1)) {
            s++;
        }
        else {
            f++;
        }
    }
}

int main() {
    scanf("%d", &TC);
    string dum;
    getline(cin, dum);
    getline(cin, inp);
    while (TC--) {
        s = 0;
        f = 0;
        getline(cin, inp);
        comps = stoi(inp);
        network = new UnionFind(comps);
        getline(cin, inp);
        while (inp.length() > 0) {
            // inp is a command
            // cout << inp << endl;
            process();
            if (cin.eof()) {
                break;
            }
            getline(cin, inp);
        }
        cout << to_string(s) << "," << to_string(f) << endl;
        if (TC != 0) {
            cout << endl;
        }
    }
    return 0;
}
