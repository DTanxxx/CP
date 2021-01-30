#include <unordered_map>
#include <iostream>
using namespace std;

int answer;
int N, M;
unordered_map<long long,int> map;

int main() {
    while (scanf("%d %d", &N, &M), (N || M)) {
        answer = 0;
        map.clear();
        while (N--) {
            long long jack;
            cin >> jack;
            map[jack] = 1;
        }
        while (M--) {
            long long jill;
            cin >> jill;
            if (map.find(jill) != map.end()) {
                // CD already present
                answer++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}
