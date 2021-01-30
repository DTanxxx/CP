#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int N, K, M;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        unordered_map<int, int> chars;
        char character;
        int value;
        while (K--) {
            cin >> character >> value;
            chars[(int)((unsigned char)character)] = value;
        }

        scanf("%d", &M);
        string dummy;
        getline(cin, dummy);
        unsigned long long payment = 0;
        while (M--) {
            string line;
            getline(cin, line);
            for (int i=0; i<line.size(); ++i) {
                if (line[i] == '\n') {
                    continue;
                }
                if (chars[(int)((unsigned char)line[i])] > 0) {
                    payment += chars[(int)((unsigned char)line[i])];
                }
            }
        }
        printf("%.2lf$\n", payment / 100.0);
    }
    return 0;
}