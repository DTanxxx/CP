#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

queue<int> q;
stack<int> s;
priority_queue<int> pq;
bitset<3> b;
int command, x, n;
string ans;

void process() {
    ans = "";
    bool uns = false;
    for (int i=0; i<b.size(); ++i) {
        if (b[i] == 1 && !uns) {
            if (i == 0) {
                ans = "queue";
            }
            else if (i == 1) {
                ans = "stack";
            }
            else {
                ans = "priority queue";
            }
            uns = true;
        }
        else if (b[i] == 1 && uns) {
            cout << "not sure" << endl;
            return;
        }
    }
    if (ans.empty()) {
        cout << "impossible" << endl;
        return;
    }
    cout << ans << endl;
}

void proc() {
    int n1, n2, n3;
    if (q.empty()) {
        b[0] = 0;
    }
    else {
        n1 = q.front();
        q.pop();
    }
    if (s.empty()) {
        b[1] = 0;
    }
    else {
        n2 = s.top();
        s.pop();
    }
    if (pq.empty()) {
        b[2] = 0;
    }
    else {
        n3 = pq.top();
        pq.pop();
    }

    if (n1 != x) {
        b[0] = 0;
    }
    if (n2 != x) {
        b[1] = 0;
    }
    if (n3 != x) {
        b[2] = 0;
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        while (!q.empty()) {q.pop();}
        while (!s.empty()) {s.pop();}
        while (!pq.empty()) { pq.pop();}
        b.set();
        while (n--) {
            cin >> command >> x;
            if (command == 1) {
                // push 
                q.push(x);
                s.push(x);
                pq.push(x);
            }
            else if (command == 2) {
                proc();
            }
        }
        process();
    }
    return 0;
}
