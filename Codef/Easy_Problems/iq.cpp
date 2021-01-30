#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::vector;
using std::unordered_map;
using std::to_string;

int find_odd(vector<int> &nums) {
    unordered_map<int,int> counts;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] % 2 == 0) {
            // even 
            counts[0]++;
        }
        else {
            // odd
            counts[1]++;
        }
    }

    if (counts[0] > 1) {
        // odd number unique
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                return i+1;
            }
        }
    }
    else if (counts[1] > 1) {
        // even number unique
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                return i+1;
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        std::cin >> nums[i];
    }

    std::cout << to_string(find_odd(nums)) << std::endl;

    return 0;
}