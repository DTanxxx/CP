#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // use long long
    unsigned long long num;
    vector<unsigned long long> nums;
    while (scanf("%lld", &num) != EOF) {
        nums.push_back(num);
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
        int num2 = nums[nums.size()/2];
        
        if (nums.size()%2 == 0) {
            // array size even
            nth_element(nums.begin(), nums.begin()+nums.size()/2-1, nums.end());
            int num1 = nums[nums.size()/2-1];
            cout << to_string((num1+num2)/2) << endl;
            continue;
        }
        cout << to_string(num2) << endl;
    }
    return 0;
}