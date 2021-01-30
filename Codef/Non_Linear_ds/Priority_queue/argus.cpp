#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
/*
output first K query IDs depending on the order they are triggered
if two queries same time triggered, then ascending order ID
use min heap
*/

int k;
priority_queue< vector<int> > pq;  // default max heap, need to negate values to achieve min heap

void process() {
    while (k--) {
        vector<int> query = pq.top();
        cout << to_string(query[1]*-1) << endl;
        query[0] -= query[2];
        pq.pop();
        pq.push(query); 
    }
}

int main() {
    string del;
    cin >> del;
    while (del != "#") {
        vector<int> query(3);
        cin >> query[1] >> query[0];
        query[2] = query[0];
        query[0] *= -1;
        query[1] *= -1;
        pq.push(query);
        cin >> del;
    }
    cin >> k;
    process();
    return 0;
}
