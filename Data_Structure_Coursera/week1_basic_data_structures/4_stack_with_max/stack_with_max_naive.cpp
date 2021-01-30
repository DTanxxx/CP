#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::max_element;

class StackWithMax {
    vector<int> stack;
    vector<int> maxVals;
    int readFromIndex = -1;

  public:

    void Push(int value) {
        stack.push_back(value);

        if (maxVals.empty()) {
            maxVals.push_back(value);
        }
        else {
            if (value > maxVals[readFromIndex]) {
                maxVals.push_back(value);
            }
            else {
                maxVals.push_back(maxVals[readFromIndex]);
            }
        }
        readFromIndex++;
    }

    void Pop() {
        assert(stack.size());
        stack.pop_back();
        readFromIndex--;
    }

    int Max() const {
        assert(stack.size());
        return maxVals[readFromIndex];
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}