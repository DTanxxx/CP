#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::max;

void max_sliding_window(vector<int> const & A, int w) {
    vector<vector<int> > suffixes;
    vector<vector<int> > prefixes;

    for (int i=0; i<(A.size()/w + 1); ++i) {
        int max = 0;
        vector<int> pre;
        for (int j=0; j<w; ++j) {
            int index = (i*w)+j;
            if (index >= A.size()) {
                break;
            }
            if (A[index] > max) {
                max = A[index];
            }
            pre.push_back(max);
        }
        prefixes.push_back(pre);

        max = 0;
        vector<int> suf;
        for (int j=w-1; j>=0; --j) {
            int index = (i*w)+j;
            if (index >= A.size()) {
                continue;
            }
            if (A[index] > max) {
                max = A[index];
            }
            suf.push_back(max);
        }
        std::reverse(std::begin(suf), std::end(suf));
        suffixes.push_back(suf);
    }

    for (int i=0; i<A.size()-w+1; ++i) {
        int prefixBlock = i/w + 1;
        int suffixBlock = i/w;

        int suffix = i%w;
        int prefix = -1;
        if (suffix == 0) {
            // no prefix 
            cout << suffixes[suffixBlock][suffix] << " ";
            continue;
        }
        else {
            prefix = suffix - 1;
        }

        if (suffixes[suffixBlock][suffix] > prefixes[prefixBlock][prefix]) {
            cout << suffixes[suffixBlock][suffix] << " ";   
        }
        else {
            cout << prefixes[prefixBlock][prefix] << " ";
        }
    }
    return;
}

int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
