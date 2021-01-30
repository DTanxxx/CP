#include <vector>
#include <string>
#include <iostream>
using namespace std;

typedef pair<int,int> ii;

int D;
int L, H;
string M;
int query;
vector<pair<string,ii> > database;

void process() {
    int count = 0;
    string name = "";
    for (int i=0; i<database.size(); ++i) {
        if (database[i].second.first <= query && database[i].second.second >= query) {
            count ++;
            name = database[i].first;
        }
    }

    if (count == 1) {
        cout << name << endl;
    }
    else {
        cout << "UNDETERMINED" << endl;
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        database.clear();
        cin >> D;
        while (D--) {
            cin >> M >> L >> H;
            pair<string,ii> data;
            data.first = M;
            data.second = *(new ii(L, H));
            database.push_back(data);
        }
        int Q;
        cin >> Q;
        while (Q--) {
            cin >> query;
            process();
        } 
        if (tc != 0) {
            cout << endl;
        }
    }
    return 0;
}
