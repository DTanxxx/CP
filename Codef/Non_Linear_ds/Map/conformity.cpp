#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

/*
use map
number of frosh <= 10^4
course number 100 to 499
5 courses each frosh

sort course numbers
concat numbers to a string
as key to map
value = frequency of each combination
10^4 nodes in tree at most, so linear scan largest freq
*/

int n;
map<string,int> mapper;

string concat(vector<int> vec) {
    ostringstream oss;
    if (!vec.empty()) {
        copy(vec.begin(), vec.end()-1, ostream_iterator<int>(oss, ","));
        oss << vec.back();
    }
    return oss.str();
}

void process() {
    int max = 1;
    for (map<string,int>::iterator it = mapper.begin(); it != mapper.end(); ++it) {
        if ((int)it->second > max) {
            max = (int)it->second;
        }
    }
    int answer = 0;
    for (map<string,int>::iterator it = mapper.begin(); it != mapper.end(); ++it) {
        if ((int)it->second == max) {
            answer += max;
        }
    }
    cout << to_string(answer) << endl;
}

int main() {
    while (scanf("%d", &n), (n)) {
        mapper.clear();
        while (n--) {
            vector<int> courses(5);
            for (int i=0; i<5; ++i) {
                cin >> courses[i];
            }
            sort(courses.begin(), courses.end());
            // courses sorted
            // now concat
            string cs = concat(courses);
            if (mapper.find(cs) == mapper.end()) {
                mapper[cs] = 1;
            }
            else {
                mapper[cs] += 1;
            }
        }
        process();
    }

    return 0;
}
