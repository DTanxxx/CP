#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;
using std::cout;
using std::endl;

vector<pair<int,int> > merge(vector<pair<int,int> > a, vector<pair<int,int> > b, bool isX) {
  vector<pair<int,int> > sorted;

  int j = 0;
  int k = 0;
  bool addB = false;
  bool addA = false;
  for (int i=0; i<a.size()+b.size(); i++) {
    if (j == a.size()) {
      // add rest of b from index k to sorted
      addB = true;
      break;
    }
    if (k == b.size()) {
      // add rest of a from index j to sorted
      addA = true;
      break;
    }

    if (isX) {
      if (b[k].first < a[j].first) {
        // element in b is smaller than a 
        sorted.push_back(b[k]);
        k++;
      }
      else {
        sorted.push_back(a[j]);
        j++;
      }
    }
    else if (!isX) {
      // cout << "HI" << endl;
      if (b[k].second < a[j].second) {
        // element in b is smaller than a 
        sorted.push_back(b[k]);
        k++;
      }
      else {
        sorted.push_back(a[j]);
        j++;
      }
    }
   
  }

  if (addB) {
    for (int i=k; i<b.size(); i++) {
      sorted.push_back(b[i]);
    }
  }
  else if (addA) {
    for (int i=j; i<a.size(); i++) {
      sorted.push_back(a[i]);
    }
  }

  return sorted;
}

vector<pair<int,int> > merge_sort(vector<pair<int,int> > &a, int lower, int upper, bool isX) {
  if (lower >= upper) {
    vector<pair<int,int> > result;
    result.push_back(a[lower]);
    return result;
  }

  int mid = (lower + upper) / 2;  
  vector<pair<int,int> > lowerHalf = merge_sort(a, lower, mid, isX);
  vector<pair<int,int> > upperHalf = merge_sort(a, mid+1, upper, isX);
  vector<pair<int,int> > resultArray = merge(lowerHalf, upperHalf, isX);

  return resultArray;
}


double find_sqrt(pair<int,int> pointA, pair<int,int> pointB) {
  return std::sqrt((pointA.first-pointB.first)*(pointA.first-pointB.first)+
    (pointA.second-pointB.second)*(pointA.second-pointB.second));
}


double find_min(vector<pair<int,int> > &points, int lower, int upper, double min_d) {
  vector<pair<int,int> > filtered;
  // filter out the point set -> keep when x to the middle line  (find middle two points and average their x values)
  int mid = (lower+upper)/2;
  double line = (points[mid].first + points[mid+1].first)/2;
  for (int i=lower; i<=upper; i++) {
    if (abs(points[i].first-line) <= min_d) {
      filtered.push_back(points[i]);
    }
  }

  // find in the new filtered set, the minimum distance between any two points
  if (filtered.size() < 2) {
    return min_d;
  }
  
  double min_distance;
  min_distance = find_sqrt(filtered[0], filtered[1]);

  vector<pair<int,int> > sortedFiltered = merge_sort(filtered, 0, filtered.size()-1, false);

  int numIterations;
  if (sortedFiltered.size() > 8) {
    numIterations = 7;
  }
  else {
    numIterations = sortedFiltered.size()-1;
  }

  for (int i=0; i<sortedFiltered.size(); i++) {
    for (int j=i+1; j<numIterations; j++) {
      if (find_sqrt(sortedFiltered[i], sortedFiltered[j]) < min_distance) {
        min_distance = find_sqrt(sortedFiltered[i], sortedFiltered[j]);
      }
    }
  } 

  return min(min_distance, min_d);
}


double find_distance(vector<pair<int,int> > &points, int lower, int upper) {
  if (lower == upper-1) {
    // return the distance between the two points
    return find_sqrt(points[lower], points[upper]);
  }

  int mid = (lower + upper) / 2;  
  double distance_left_section = find_distance(points, lower, mid);
  double distance_right_section = find_distance(points, mid, upper);

  // find min of two sections
  double min_distance = min(distance_left_section, distance_right_section);
  // use lower and upper as the range of points
  // pass in points and lower and upper and min d into new function

  return find_min(points, lower, upper, min_distance);
}

double minimal_distance(vector<int> x, vector<int> y) {
  vector<pair<int,int> > points;
  for (int i=0; i<x.size(); i++) {
    pair<int,int> point;
    point.first = x[i];
    point.second = y[i];
    points.push_back(point);
  }

  vector<pair<int,int> > sortedPoints = merge_sort(points, 0, points.size()-1, true);

  // do a linear scan to detect any repeating points
  for (int i=1; i<sortedPoints.size(); i++) {
    if (sortedPoints[i].first == sortedPoints[i-1].first &&
    sortedPoints[i].second == sortedPoints[i-1].second) {
      return 0.00000000;
    }
  }
  
  return find_distance(sortedPoints, 0, sortedPoints.size()-1);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
