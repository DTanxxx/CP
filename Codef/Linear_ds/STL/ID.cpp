#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string in;

void process_string() {
    if (next_permutation(in.begin(), in.end())) {
        cout << in << endl;
    }
    else {
        cout << "No Successor" << endl;
    }
}

int main() {    
    while (getline(cin, in) && in != "#") {
        process_string();
    }
    return 0;
}
