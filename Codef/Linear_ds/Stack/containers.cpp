#include <stack>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string line;
int case_num = 1;

void arrange_cargo() {
    vector<int> letters(100, 0);
    int unique_letters = 0;
    for (int i=0; i<line.size(); ++i) {
        if (letters[(int)line[i]] == 0) {
            unique_letters++;
            letters[(int)line[i]] = 1;
        }
    }

    vector<stack<char> > stacks;
    for (int i=0; i<line.size(); ++i) {
        if (stacks.empty()) {
            stack<char> *st = new stack<char>();
            st->push(line[i]);
            stacks.push_back(*st);
            continue;
        }

        bool to_continue = false;
        for (int j=0; j<stacks.size(); ++j) {
            if ((int)line[i] <= (int)(stacks[j].top())) {
                stacks[j].push(line[i]);
                to_continue = true;
                break;
            }
        }
        if (to_continue) {
            continue;
        }

        // if still here, then create new stack
        stack<char> *st = new stack<char>();
        st->push(line[i]);
        stacks.push_back(*st);
    }
    cout << "Case " << to_string(case_num) << ": " << to_string(min(unique_letters, static_cast<int>(stacks.size()))) << endl;
}

int main() {
    getline(cin, line);
    while (line != "end") {
        arrange_cargo();
        case_num++;
        getline(cin, line);
    }
    return 0;
}

/*
VARIABLES:
- simple enough

INPUT:
- each line = one test case
- terminated by "end"
- each case = order of arrival of containers
- each letter shows the ship to load the container to 
- everything is stacked before loading

OUTPUT:
- each test case print case number "Case #: " and minimum number of stacks required before loading 
*/

/*
IDEAS:
- create 2 scenarios, 1 looking for number of different letters
- other one do a streamline check 
- for each letter, check all the prev stack's top(); if smaller or equal to, than add to that stack; return, otherwise create a new stack
*/

