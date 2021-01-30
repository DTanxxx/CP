#include <vector>
#include <iostream>
using namespace std;

int k;
int first_case = true;
vector<int> s;

void process() {
    for (int i=0; i<s.size()-5; ++i) {
        for (int j=i+1; j<s.size(); ++j) {
            for (int k=j+1; k<s.size(); ++k) {
                for (int l=k+1; l<s.size(); ++l) {
                    for (int m=l+1; m<s.size(); ++m) {
                        for (int n=m+1; n<s.size(); ++n) {
                            cout << s[i] << " " << s[j] << " " << s[k] << " " << s[l] << " " << s[m] << " " << s[n] << endl;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    while (scanf("%d", &k), k) {
        if (first_case) {
            first_case = false;            
        }
        else {
            cout << endl;
        }

        s.resize(k, 0);
        for (int i=0; i<k; ++i) {
            cin >> s[i];
        }
        process();
    }
    return 0;
}
