#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool is_better(string a, int b) {

  string stringB = std::to_string(b);
  string originalA = a;
  string originalB = std::to_string(b);

  int greaterDigitNums = std::max(a.size(), stringB.size());

  int digitNumDifference = abs((int)(a.size() - stringB.size()));
  if (a.size() < stringB.size()) {
    // the number has less digits
    for (int i=0; i<digitNumDifference; i++) {
      a += a[a.size()-1];
    }
  }
  else {
    // the maxNumber has less digits
    for (int i=0; i<digitNumDifference; i++) {
      stringB += stringB[stringB.size()-1];
    }
  }



  if (std::stoi(a) > std::stoi(stringB)) {
    if ((originalA.size() == 2) && (originalB.size() == 3)) {
      if ((originalA[0] == originalB[0]) && (originalA[1] == originalB[1])) {
        if (originalB[2] > originalA[0]) {
          return false;
        }
      }     
    }
    else if ((originalA.size() == 3) && (originalB.size() == 2)) {
      if ((originalA[0] == originalB[0]) && (originalA[1] == originalB[1])) {
        if (originalA[2] < originalB[0]) {
          return false;
        }
        else {
          return true;
        }
      }
    }
    return true;
  }
  else {
    if (std::stoi(a) == std::stoi(stringB)) {
      if (originalA.size() > originalB.size()) {
        // b is shorter
        if ((originalA.size() == 3) && (originalB.size() == 2)) {
          if (((int)originalB[1]) > ((int)originalB[0])) {
            return true;
          }
          else {
            return false;
          }
        }
        return false;
      }
      else {
        // a is shorter
        if ((originalA.size() == 2) && (originalB.size() == 3)) {
          if (((int)originalA[1]) > ((int)originalA[0])) {
            return false;
          }
          else {
            return true;
          }
        }
        return true;
      }
    }

    // a<b
    // check if last digit of a is larger than first digit of b
    // if so return true
    if ((originalA.size() == 3) && (originalB.size() == 2)) {
      if ((originalA[0] == originalB[0]) && (originalA[1] == originalB[1])) {
        if (originalA[2] > originalB[0]) {
          return true;
        }
      }
    }
    else if ((originalA.size() == 2) && (originalB.size() == 3)) {
      if ((originalA[0] == originalB[0]) && (originalA[1] == originalB[1])) {

        // std::cout << originalA << ' ' << originalB << std::endl;

        if (originalB[2] < originalA[0]) {
          return true;
        }
        else {
          return false;
        }
      }
    }
    return false;
  }

  return true;
}

string largest_number(vector<string> a) {
  std::stringstream ret;

  while (a.size() != 0) {
    int maxNumber = std::stoi(a[0]);
    int maxNumberIndex = 0;

    for (int i=0; i<a.size(); i++) {
      if (is_better(a[i], maxNumber)) {
        maxNumber = std::stoi(a[i]);
        // std::cout << maxNumber << std::endl;
        maxNumberIndex = i;
      }
    }
    ret << maxNumber;
    a[maxNumberIndex] = a[a.size()-1];
    a.pop_back();
  }

  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
