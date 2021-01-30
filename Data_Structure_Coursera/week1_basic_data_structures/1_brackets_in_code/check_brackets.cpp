#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next, position+1));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty()) {
                cout << position+1 << endl;
                return 0;
            }

            Bracket closing = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            if (closing.Matchc(next)) {
                continue;
            }
            else {
                cout << position+1 << endl;
                return 0;
            }
        }
    }

    if (opening_brackets_stack.empty()) {
        cout << "Success" << endl;
    }
    else {
        Bracket last = opening_brackets_stack.top();
        while (!opening_brackets_stack.empty()) {
            last = opening_brackets_stack.top();
            opening_brackets_stack.pop();
        }
        cout << last.position << endl;
    }

    return 0;
}
