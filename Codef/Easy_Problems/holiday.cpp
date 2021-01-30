#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > boxes(n);
    for (int i=0; i<n; i++) {
        vector<int> dimensions(3);
        cin >> dimensions[0] >> dimensions[1] >> dimensions[2];
        boxes[i] = dimensions;
    }

    for (int i=0; i<n; i++) {
        vector<int> dim = boxes[i];
        if (dim[0] <= 20 && dim[1] <= 20 && dim[2] <= 20) {
            cout << "Case " << to_string(i+1) << ": good" << endl;
        }
        else {
            cout << "Case " << to_string(i+1) << ": bad" << endl;
        }
    }
    return 0;
}