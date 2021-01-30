#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

/*
each country unique ID from 1 to n
each cargo has tag naming destination country ID

each country has cargo station identified by country ID -> 2 platforms:
A = cargo to country
B = cargo to other countries = queue
circular arrangement stations

cargo carriers are stacks of cargo
carrier moves from stations to stations following ring arrangement so 1 to 2 to 3 to n to 1
2 min per station movement (so per pair)

carrier put cargo on station
each station, pop stack to check if cargo ID equal country ID
if so then add to A; otherwise checks whether B has vacant positions
if so add to B's queue
repeat until stack empty or B's full 
each unload = 1 minute

then load: take B's front queue element and add to stack
until stack full or queue empty
one load = 1minute

finally, next station
*/

/*
empty carrier so empty stack
from station 1 onwards until all cargoes have been distributed so every B empty
find how long it takes
*/

/*
INPUT:
SET = number of sets of inputs
followed by SET of inputs

N S Q
N = stations
S = stack size
Q = queue size for B
N lines
*/
int N, S, Q;
vector<queue<int> > stations;

void process() {
    int curr_station = 0;
    stack<int> carrier = *(new stack<int>());
    int time = 0;

    int n = 5;
    while (true) {
        queue<int> *station = &(stations[curr_station]);

        while ((!carrier.empty() && station->size() < Q) || (!carrier.empty() && carrier.top() == curr_station+1)) {
            time += 1;
            if (carrier.top() == curr_station+1) {
                // curr_station index based
                // found station
                carrier.pop();
            }
            else {
                // not correct station
                station->push(carrier.top());
                carrier.pop();
            }
        }
        // unload complete
        while (!station->empty() && carrier.size() < S) {
            time += 1;
            carrier.push(station->front());
            station->pop();
        }
        // load complete
        bool done = true;
        for (int i=0; i<stations.size(); ++i) {
            if (!stations[i].empty() || !carrier.empty()) {
                done = false;
            }
        }
        if (done) {
            break;
        }
        curr_station++;
        curr_station = curr_station%N;
        time += 2;
    }
    cout << time << endl;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        cin >> N >> S >> Q;
        stations.clear();
        for (int i=0; i<N; ++i) {
            int num_cargoes;
            cin >> num_cargoes;
            queue<int> B = *(new queue<int>());
            while (num_cargoes--) {
                int cargo;
                cin >> cargo;
                B.push(cargo);
            }
            stations.push_back(B);
        }
        process();
    }
    return 0;
}
