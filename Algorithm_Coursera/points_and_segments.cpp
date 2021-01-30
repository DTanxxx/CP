#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::pair;
using std::unordered_map;

vector<int> merge(vector<int> a, vector<int> b) {
  vector<int> sorted;

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

    if (b[k] < a[j]) {
      // element in b is smaller than a 
      sorted.push_back(b[k]);
       k++;
    }
    else {
      sorted.push_back(a[j]);
      j++;
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

vector<int> merge_sort(vector<int> &a, int lower, int upper) {
  if (lower >= upper) {
    vector<int> result;
    result.push_back(a[lower]);
    return result;
  }

  int mid = (lower + upper) / 2;  
  vector<int> lowerHalf = merge_sort(a, lower, mid);
  vector<int> upperHalf = merge_sort(a, mid+1, upper);
  vector<int> resultArray = merge(lowerHalf, upperHalf);

  return resultArray;
}

vector<pair<int,char> > merge_segments_start(vector<pair<int,char> > a, vector<pair<int,char> > b) {
  vector<pair<int,char> > sorted;

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

    if (b[k].first < a[j].first) {
      // element in b is smaller than a 
      sorted.push_back(b[k]);
      k++;
    }
    else if (b[k].first > a[j].first) {
      sorted.push_back(a[j]);
      j++;
    }
    else {
      // both first element equal, append the one with 'S' first, or 'P'
      if (b[k].second == 'S') {
        sorted.push_back(b[k]);
        // sorted.push_back(a[j]);
        // j++;
        k++;
      }
      else if (a[j].second == 'S') {
        sorted.push_back(a[j]);
        // sorted.push_back(b[k]);
        // k++;
        j++;
      }
      else if (b[k].second == 'P') {
        sorted.push_back(b[k]);
        // sorted.push_back(a[j]);
        // j++;
        k++;
      }
      else if (a[j].second == 'P') {
        sorted.push_back(a[j]);
        // sorted.push_back(b[k]);
        // k++;
        j++;
      }
      else {
        // both 'E'
        sorted.push_back(b[k]);
        sorted.push_back(a[j]);
        j++;
        k++;
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

vector<pair<int,char> > merge_sort_segments_start(vector<pair<int,char> > &a, int lower, int upper) {
  if (lower >= upper) {
    vector<pair<int,char> > result;
    result.push_back(a[lower]);
    return result;
  }

  int mid = (lower + upper) / 2;  
  vector<pair<int,char> > lowerHalf = merge_sort_segments_start(a, lower, mid);
  vector<pair<int,char> > upperHalf = merge_sort_segments_start(a, mid+1, upper);
  vector<pair<int,char> > resultArray = merge_segments_start(lowerHalf, upperHalf);

  return resultArray;
}

vector<pair<int,int> > merge_segments_end(vector<pair<int,int> > a, vector<pair<int,int> > b) {
  vector<pair<int,int> > sorted;

  int j = 0;
  int k = 0;
  bool addB = false;
  bool addA = false;
  for (int i=0; i<a.size()+b.size()-1; i++) {
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

vector<pair<int,int> > merge_sort_segments_end(vector<pair<int,int> > &a, int lower, int upper) {
  if (lower >= upper) {
    vector<pair<int,int> > result;
    result.push_back(a[lower]);
    return result;
  }

  int mid = (lower + upper) / 2;  
  vector<pair<int,int> > lowerHalf = merge_sort_segments_end(a, lower, mid);
  vector<pair<int,int> > upperHalf = merge_sort_segments_end(a, mid+1, upper);
  vector<pair<int,int> > resultArray = merge_segments_end(lowerHalf, upperHalf);

  return resultArray;
}



int binary_search_end(vector<pair<int,int> > segments, int point, int lower, int upper, bool returnLower) {
  if (lower > upper) {
    if (returnLower) {
      return lower-1;  // maybe -1     
    }
    else {
      return upper;
    }
  }
  
  int mid = (lower+upper)/2;

  if (segments[mid].second < point) {
    return binary_search_end(segments, point, mid+1, upper, false);
  }
  else {
    return binary_search_end(segments, point, lower, mid-1, true);
  }  
}

int binary_search_start(vector<pair<int,int> > segments, int point, int lower, int upper, bool returnUpper) {
  if (lower > upper) {
    if (returnUpper) {
      return upper+1;  // maybe segments.size()   
    }
    else {
      return lower;
    }
  }

  int mid = (lower+upper)/2;

  if (segments[mid].first > point) {
    return binary_search_start(segments, point, lower, mid-1, false);
  }
  else {
    return binary_search_start(segments, point, mid+1, upper, true);
  } 
}

int binary_search(vector<int> points, int targetPoint, int lower, int upper) {
  if (lower >= upper) {
    return lower;
  }

  int mid = (lower+upper)/2;

  if (points[mid] == targetPoint) {
    // found it
    return mid;
  }

  if (points[mid] > targetPoint) {
    return binary_search(points, targetPoint, lower, mid-1);
  }
  else {
    return binary_search(points, targetPoint, mid+1, upper);
  }
}


vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());

  // sort the points
  vector<int> sortedPoints = merge_sort(points, 0, points.size()-1);

  // sort segments by starts
  vector<pair<int,char> > segmentEnds;
  for (int i=0; i<starts.size(); i++) {
    pair<int,char> pointInfo;
    pointInfo.first = starts[i];
    pointInfo.second = 'S';
    segmentEnds.push_back(pointInfo);
    pair<int,char> point2Info;
    point2Info.first = ends[i];
    point2Info.second = 'E';
    segmentEnds.push_back(point2Info);
  }
  for (int i=0; i<points.size(); i++) {
    pair<int,char> pointInfo;
    pointInfo.first = points[i];
    pointInfo.second = 'P';
    segmentEnds.push_back(pointInfo);
  }

  vector<pair<int,char> > sortedInfos = merge_sort_segments_start(segmentEnds, 0, segmentEnds.size()-1);
  // vector<int> counts(50000);
  unordered_map<int, int> dict;

  int counter = 0;

  for (int i=0; i<sortedInfos.size(); i++) {
    if (sortedInfos[i].second == 'S') {
      counter ++;
    }
    else if (sortedInfos[i].second == 'E') {
      counter --;
    }
    else if (sortedInfos[i].second == 'P') {
      dict[sortedInfos[i].first] = counter;
    }
  }

  // array of counts for sorted array of points
  for (int i=0; i<points.size(); i++) {
    // TODO: DON'T FUCKING DO A BINARY SEARCH INSIDE A LOOP!!!
    // USE A BLOODY HASHMAP!!!!!
    cnt[i] = dict[points[i]];
  }

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }

  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
