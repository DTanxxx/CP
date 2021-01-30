#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b), (a != -1 || b != -1)) {
        int up = 0;
        int down = 0;
        int a1 = a;
        int a2 = a;
        while (true) {
            if (a == b) {
                cout << 0 << endl;
                break;
            }

            up++;
            down++;
            if (a1 == 99) {
                a1 = 0;
            }
            else {
                a1++;
            }
            
            if (a2 == 0) {
                a2 = 99;
            }
            else {
                a2--;
            }

            if (a1 == b) {
                cout << up << endl;
                break;
            }
            if (a2 == b) {
                cout << down << endl;
                break;
            }
        }
    }
    return 0;
}