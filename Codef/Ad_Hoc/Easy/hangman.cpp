#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

string answer;
string guess;

void process() {
    unordered_map<char,int> letters;
    stack<char> lets;
    for (int i=0; i<answer.size(); ++i) {
        if (letters[answer[i]] == 0) {
            letters[answer[i]] = 1;
            lets.push(answer[i]);
        }
    }

// IF MID WAY YOU WIN, YOU WIN AND EXIT
    int wrong = 0;
    for (int i=0; i<guess.size(); ++i) {
        if (letters[guess[i]] == 1) {
            letters[guess[i]] = 2;
            lets.pop();
        }
        else {
            // wrong guess or already guessed
            if (letters[guess[i]] == 2) {
                continue;
            }
            if (letters[guess[i]] != 3) {
                wrong++;
                letters[guess[i]] = 3;  // already guessed
            }
        }
        if (lets.empty()) {
            // finished guessing
            break;
        }
    }

    if (wrong >= 7) {
        cout << "You lose." << endl;
        return;
    }
    else {
        // either win or chicken out
        for (int i=0; i<answer.size(); ++i) {
            if (letters[answer[i]] < 2) {
                cout << "You chickened out." << endl;
                return;
            }
        }
        cout << "You win." << endl;
        return;
    }
}

int main() {
    int num;
    while (scanf("%d", &num), num != -1) {
        cin >> answer >> guess;
        cout << "Round " << to_string(num) << endl;
        process();
    }
    return 0;
}
