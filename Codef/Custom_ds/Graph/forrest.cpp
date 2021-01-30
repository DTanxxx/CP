#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> AdjList;

/*
input: edges, then **** then nodes
output: "There are x tree(s) and y acorn(s)."
*/
bool t;
int acorn;
int tree;
int TC;
string line;
AdjList forest;
unordered_map<int,int> nodes;
unordered_map<int,int> used;

void recur(int node) {
    if (used[node] == 1) {
        return;
    }
    int count = forest[node].size();
    for (int i=0; i<forest[node].size(); ++i) {
        if (used[forest[node][i]] == 1) {
            // used
            count--;
        }
    }
    if (count == 0) {
        if (!t) {
            tree++;
            t = true;
        }
        used[node] = 1;
        return;
    }

    used[node] = 1;
    for (int i=0; i<forest[node].size(); ++i) {
        if (used[forest[node][i]] != 1) {
            recur(forest[node][i]);
        }
    }
}

void process() {
    for (int i=0; i<26; ++i) {
        if (nodes[i] == 1) {
            t = false;
            if (forest[i].empty()) {
                // acorn + 1
                acorn++;
            }
            else {
                // trace from i to next node to next node to next until node has no more connected node OR node appears in used 
                // make sure the tracing process is repeated recursively so every node's every node is iterated through
                // add all those nodes to used 
                // if a recursive finishes due to no more connected node, tree + 1
                recur(i);
            }
        }
    }
    cout << "There are " << to_string(tree) << " tree(s) and " << to_string(acorn) << " acorn(s)." << endl;
}

int main() {
    scanf("%d", &TC);
    string dummy;
    getline(cin, dummy);
    while (TC--) {
        t = false;
        acorn = 0;
        tree = 0;
        // a forest 
        nodes.clear();
        used.clear();
        forest.clear();
        forest.resize(26, *(new vi()));
        getline(cin, line);
        while (line[0] != '*') {
            // line is an edge
            int row_ind = line[1] - 'A';
            int node_num = line[3] - 'A';
            forest[row_ind].push_back(node_num);
            forest[node_num].push_back(row_ind);
            getline(cin, line);
        }
        getline(cin, line);
        // split the node line 
        string delimiter = ",";
        size_t pos = 0;
        string token;
        while ((pos = line.find(delimiter)) != string::npos) {
            token = line.substr(0, pos);
            nodes[token[0]-'A'] = 1;
            line.erase(0, pos + delimiter.length());
        }
        nodes[line[0]-'A'] = 1;
        process();
    }
    return 0;
}
