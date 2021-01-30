#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
INPUTS: 
num players, num tools, num rolls
start, finish of a tool (snake or ladder)
rolls

find final positions of players
1 million players, so use a vector of size 1 million to store positions

*/

vector<int> players;  // initialised to 1s = positions
vector<int> tools;  // 100 tools; initialised to 0; index = start; value = finish
vector<int> rolls;

void process() {
    int curr_player = 0;
    for (int i=0; i<rolls.size(); ++i) {
        int curr_pos = players[curr_player] + rolls[i];
        if (curr_pos >= 100) {
            // output each player's position
            players[curr_player] = 100;
            for (int j=0; j<players.size(); ++j) {
                cout << "Position of player " << to_string(j+1) << " is " << to_string(players[j]) << "." << endl;
            }
            return;
        }
        if (tools[curr_pos] != 0) {
            // there is a tool
            curr_pos = tools[curr_pos];
            if (curr_pos >= 100) {
                // output each player's position
                players[curr_player] = 100;
                for (int j=0; j<players.size(); ++j) {
                    cout << "Position of player " << to_string(j+1) << " is " << to_string(players[j]) << "." << endl;
                }
                return;
            }
        }

        players[curr_player] = curr_pos;
        // cycles through player for each roll
        curr_player++;
        curr_player = curr_player%players.size();
    }
    for (int i=0; i<players.size(); ++i) {
        cout << "Position of player " << to_string(i+1) << " is " << to_string(players[i]) << "." << endl;
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int players_num;
        int tools_num;
        int rolls_num;
        cin >> players_num >> tools_num >> rolls_num;
        players.clear();
        players.resize(players_num, 1);
        tools.clear();
        tools.resize(100, 0);
        rolls.clear();
        rolls.resize(rolls_num);
        for (int i=0; i<tools_num; ++i) {
            int start, finish;
            cin >> start >> finish;
            tools[start] = finish;
        }
        for (int i=0; i<rolls_num; ++i) {
            cin >> rolls[i];
        }
        process();
    }
    return 0;
}
