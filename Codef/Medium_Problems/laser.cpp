#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, C;
    while (scanf("%d %d", &A, &C), (A || C)) {
        vector<int> heights;
        heights.push_back(A);
        int total = 0;
        for (int i=0; i<C; ++i) {
            int height;
            cin >> height;
            heights.push_back(height);
            
            if (height < heights[i]) {
                int gap = heights[i] - height;
                total += gap;
            }
        }
        cout << total << endl;   
    }
    return 0;
}
