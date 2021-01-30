#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void SiftDown(int nodeIndex) {
    int node = data_[nodeIndex];
    double leftChild = std::numeric_limits<double>::infinity();
    if (2*nodeIndex+1 < data_.size()) {
      leftChild = (int)data_[2*nodeIndex+1];
    }
    double rightChild = std::numeric_limits<double>::infinity();
    if (2*nodeIndex+2 < data_.size()) {
      rightChild = (int)data_[2*nodeIndex+2];
    } 

    if (node > leftChild && node > rightChild) {
        if (leftChild < rightChild) {
          // swap with left child
          data_[nodeIndex] = leftChild;
          data_[2*nodeIndex+1] = node;
          pair<int,int> swap;
          swap.first = nodeIndex;
          swap.second = 2*nodeIndex+1;
          swaps_.push_back(swap);
          SiftDown(2*nodeIndex+1);
        }
        else {
          // swap with right child
          data_[nodeIndex] = rightChild;
          data_[2*nodeIndex+2] = node;
          pair<int,int> swap;
          swap.first = nodeIndex;
          swap.second = 2*nodeIndex+2;
          swaps_.push_back(swap);
          SiftDown(2*nodeIndex+2);
        }
      }
      else if (node > leftChild) {
        // swap with left child
        data_[nodeIndex] = leftChild;
        data_[2*nodeIndex+1] = node;
        pair<int,int> swap;
          swap.first = nodeIndex;
          swap.second = 2*nodeIndex+1;
          swaps_.push_back(swap);
        SiftDown(2*nodeIndex+1);
      }
      else if (node > rightChild) {
        // swap with right child
          data_[nodeIndex] = rightChild;
          data_[2*nodeIndex+2] = node;
          pair<int,int> swap;
          swap.first = nodeIndex;
          swap.second = 2*nodeIndex+2;
          swaps_.push_back(swap);
          SiftDown(2*nodeIndex+2);
      }
  }

  void GenerateSwaps() {
    swaps_.clear();
    for (int i=(data_.size()-2)/2; i>=0; --i) {
      SiftDown(i);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
