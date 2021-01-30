#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
// #include "disjoint_set_modified.h"
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

/*
f < 100000
*/

int TC;
int f;
string relation;
UnionFindString* friends;

void process() {
    string name1;
    string name2;
    string delimiter = " ";
    size_t pos = 0;
    string token;
    while ((pos = relation.find(delimiter)) != string::npos) {
        token = relation.substr(0, pos);
        name1 = token;
        relation.erase(0, pos + delimiter.length());
    }
    name2 = relation;

    if (!friends->inSet(name1)) {
        friends->addToSet(name1);
    }
    if (!friends->inSet(name2)) {
        friends->addToSet(name2);
    }
    friends->unionSet(name1, name2);
    cout << to_string(friends->setSize(name1)) << endl;
}

int main() {
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &f);
        string dum;
        getline(cin, dum);
        friends = new UnionFindString();
        while (f--) {
            getline(cin, relation);
            process();
        }
    }
    return 0;
}