#include <map>
#include <iostream>
#include <string>
#include <cstdio>
#include <math.h>

using namespace std;

/*
use map
stores tree name to number
find total number
iterate tree and calculate % to 4dp (not rounded??)
*/

map<string, int> mapper;
int total;

inline double round( double val )
{
    if( val < 0 ) return ceil(val - 0.5);
    return floor(val + 0.5);
}

void process() {
    for (map<string,int>::iterator it = mapper.begin(); it != mapper.end(); ++it) {
        // calculate %
        double percentage = (it->second) * 1.0 / (total * 1.0) * 100.0;
        double value = round(percentage * 10000.0) / 10000.0;
        printf("%s %.4f\n", ((string)it->first).c_str(), value);
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    string dummy;
    getline(cin, dummy);
    getline(cin, dummy);
    while (tc--) {
        mapper.clear();
        total = 0;
        string tree;
        while (true) {
            getline(cin, tree);
            if (tree.empty() || cin.eof()) {
                break;
            }
            total++;
            if (mapper.find(tree) == mapper.end()) {
                // no key exists yet
                mapper[tree] = 1;
            }
            else {
                mapper[tree] += 1;
            }
        }
        process();
        if (tc != 0) {
            printf("\n");
        }
    }
    return 0;
}
