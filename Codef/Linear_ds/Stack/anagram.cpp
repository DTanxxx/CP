#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <istream>
#include <algorithm>

using namespace std;

string source;
string target;
vector<vector<string> > solutions;

bool compareTwoOperations(vector<string> a, vector<string> b) {
    string astr = "";
    string bstr = "";
    for (int i=0; i<a.size(); ++i) {
        astr += a[i];
        bstr += b[i];
    }
    int res = astr.compare(bstr);
    if (res < 0) {
        // a > b
        return true;
    }
    else {
        return false;
    }
}

void build_branch(vector<string> currentOps, stack<char> currentStack, 
                int sourceInd, int targetInd, 
                string op, int iCount, int oCount) {
    if (op == "o" && (currentStack.empty() || oCount == source.size() || targetInd >= target.size())) { return; }
    if (op == "i" && (iCount == source.size() || sourceInd >= source.size())) { return; }

    if (op == "i") {
        // push onto stack
        currentStack.push(source[sourceInd]);
        currentOps.push_back("i");
        sourceInd++;
        iCount++;
    }
    else if (op == "o") {
        // pop from stack
        if (currentStack.top() != target[targetInd]) { return; }
        currentStack.pop();
        currentOps.push_back("o");
        targetInd++;
        oCount++;
    }

    if (currentOps.size() == source.size()*2) {
        solutions.push_back(currentOps);
        return;
    }

    build_branch(currentOps, currentStack, sourceInd, targetInd, "i", iCount, oCount);
    build_branch(currentOps, currentStack, sourceInd, targetInd, "o", iCount, oCount);
}

void anagram() {
    solutions.clear();
    if (source.size() == 0 || target.size() == 0 || source.size() != target.size()) {
        // cout empty solutions with brackets
        cout << "[" << endl;
        cout << "]" << endl;
        return;
    }

    build_branch(*(new vector<string>()), *(new stack<char>()), 0, 0, "i", 0, 0);
    sort(solutions.begin(), solutions.end(), compareTwoOperations);

    cout << "[" << endl;
    for (int i=0; i<solutions.size(); ++i) {
        for (int j=0; j<solutions[i].size(); ++j) {
            if (j != 0) {
                cout << " " << solutions[i][j];
            }
            else {
                cout << solutions[i][j];
            }
        }
        cout << endl;
    }
    cout << "]" << endl;
}

int main() {
    while (getline(cin, source)) {
        if (cin.eof()) {
            break;
        }
        getline(cin, target);
        anagram();
    }
    return 0;
}
