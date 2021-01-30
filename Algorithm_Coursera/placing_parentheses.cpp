#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <math.h>

using std::vector;
using std::string;
using std::pair;
using std::max;
using std::min;
using std::cout;
using std::endl;
using std::stoi;
using std::to_string;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

pair<long long,long long> min_and_max(int i, int j, vector<vector<long long> > &mins, vector<vector<long long> > &maxs, vector<char> ops) {
  long long mini = INFINITY;
  long long maxi = -1 * mini;  // DISGUSTING!! -> cannot do -1 * INFINITY, has to do -1 * variable that holds INFINITY as its value

  for (int k=i; k<j; ++k) {
    long long a = eval(maxs[i-1][k-1], maxs[k][j-1], ops[k-1]);
    long long b = eval(maxs[i-1][k-1], mins[k][j-1], ops[k-1]);
    long long c = eval(mins[i-1][k-1], maxs[k][j-1], ops[k-1]);
    long long d = eval(mins[i-1][k-1], mins[k][j-1], ops[k-1]);
    mini = min(min(min(mini, a), min(b, c)), d); 
    maxi = max(max(max(maxi, a), max(b, c)), d);
  }

  pair<long long, long long> result;
  result.first = mini;
  result.second = maxi;
  return result;
} 

string conversion(char c) {
  string s;
  s.append(1, c);
  return s;
}

long long get_maximum_value(string &exp) {
  vector<string> nums;  // has one more element than ops
  vector<char> ops;
  for (int i=1; i<exp.size(); i+=2) {
    nums.push_back(conversion(exp[i-1]));
    ops.push_back(exp[i]);
  }
  nums.push_back(conversion(exp[exp.size()-1]));

  vector<vector<long long> > minimums(nums.size());
  vector<vector<long long> > maximums(nums.size());
  for (int i=0; i<nums.size(); ++i) {
    vector<long long> row(nums.size(), 0);
    minimums[i] = row;
    maximums[i] = row;
  }

  for (int i=0; i<nums.size(); ++i) {
    minimums[i][i] = stoi(nums[i]);
    maximums[i][i] = stoi(nums[i]);
  }

  for (int s=1; s<nums.size(); ++s) {
    for (int i=1; i<nums.size()-s+1; ++i) {
      int j = i + s;
      pair<long long, long long> min_max = min_and_max(i, j, minimums, maximums, ops);
      minimums[i-1][j-1] = min_max.first;
      maximums[i-1][j-1] = min_max.second;
    }
  }
  return maximums[0][nums.size()-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
