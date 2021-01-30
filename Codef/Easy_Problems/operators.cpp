#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int main() {
    int t;
    std::cin >> t;
    vector<pair<int,int> > nums(t);
    for (int i=0; i<t; i++) {
        int a;
        int b;
        std::cin >> a >> b;
        pair<int,int> num;
        num.first = a;
        num.second = b;
        nums[i] = num;
    }

    for (int i=0; i<nums.size(); i++) {
        pair<int,int> p = nums[i];
        if (p.first > p.second) {
            std::cout << ">" << std::endl;
        }
        else if (p.first < p.second) {
            std::cout << "<" << std::endl;
        }
        else if (p.first == p.second) {
            std::cout << "=" << std::endl;
        }
    }
    return 0;
}