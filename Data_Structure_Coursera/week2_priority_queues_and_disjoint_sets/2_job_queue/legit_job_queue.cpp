#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <typeinfo>
#include <random>

using namespace std;

class JobQueue {
 private:
  int num_workers_;
  vector<long long> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;
  vector<vector<long long> > min_heap_;
  int heap_size_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    min_heap_.resize(num_workers_);
    assigned_workers_.resize(m);
    start_times_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void SiftUp(int jobIndex) {
    if (jobIndex == 0) {
      return;
    }

    int parentIndex = (jobIndex-1) / 2;
    if (min_heap_[parentIndex][0] > min_heap_[jobIndex][0]) {
      vector<long long> temp = min_heap_[parentIndex];
      min_heap_[parentIndex] = min_heap_[jobIndex];
      min_heap_[jobIndex] = temp;
      SiftUp(parentIndex);
    }
  }

  void SiftDown(int jobIndex) {
    vector<long long> job = min_heap_[jobIndex];
    long long jobTime = min_heap_[jobIndex][0];
    long long leftChildFinishTime = LLONG_MAX;
    if (2*jobIndex+1 < heap_size_) {
      leftChildFinishTime = min_heap_[2*jobIndex+1][0];
    }
    long long rightChildFinishTime = LLONG_MAX;
    if (2*jobIndex+2 < heap_size_) {
      rightChildFinishTime = min_heap_[2*jobIndex+2][0];
    } 

    if (jobTime >= leftChildFinishTime && jobTime >= rightChildFinishTime) {
      if (leftChildFinishTime == rightChildFinishTime && jobTime == leftChildFinishTime) {
        if (min_heap_[2*jobIndex+1][1] < min_heap_[2*jobIndex+2][1] && min_heap_[jobIndex][1] > min_heap_[2*jobIndex+1][1]) {
          // swap with left
          min_heap_[jobIndex] = min_heap_[2*jobIndex+1];
          min_heap_[2*jobIndex+1] = job;
          SiftDown(2*jobIndex+1);
        }
        else if (min_heap_[2*jobIndex+1][1] > min_heap_[2*jobIndex+2][1] && min_heap_[jobIndex][1] > min_heap_[2*jobIndex+2][1]) {
          // swap with right
          min_heap_[jobIndex] = min_heap_[2*jobIndex+2];
          min_heap_[2*jobIndex+2] = job;
          SiftDown(2*jobIndex+2);
        }
      }
      else if (leftChildFinishTime == rightChildFinishTime && jobTime > leftChildFinishTime) {
        if (min_heap_[2*jobIndex+1][1] < min_heap_[2*jobIndex+2][1]) {
          // swap with left
          min_heap_[jobIndex] = min_heap_[2*jobIndex+1];
          min_heap_[2*jobIndex+1] = job;
          SiftDown(2*jobIndex+1);
        }
        else if (min_heap_[2*jobIndex+1][1] > min_heap_[2*jobIndex+2][1]) {
          // swap with right
          min_heap_[jobIndex] = min_heap_[2*jobIndex+2];
          min_heap_[2*jobIndex+2] = job;
          SiftDown(2*jobIndex+2);
        }
      }
      else if (leftChildFinishTime < rightChildFinishTime) {
        // swap with left child
        min_heap_[jobIndex] = min_heap_[2*jobIndex+1];
        min_heap_[2*jobIndex+1] = job;
        SiftDown(2*jobIndex+1);
      }
      else if (leftChildFinishTime > rightChildFinishTime) {
        // swap with right child
        min_heap_[jobIndex] = min_heap_[2*jobIndex+2];
        min_heap_[2*jobIndex+2] = job;
        SiftDown(2*jobIndex+2);
      }
    }
    else if (jobTime >= leftChildFinishTime) {
      if (jobTime == leftChildFinishTime) {
        if (min_heap_[jobIndex][1] > min_heap_[2*jobIndex+1][1]) {
           // swap with left child
          min_heap_[jobIndex] = min_heap_[2*jobIndex+1];
          min_heap_[2*jobIndex+1] = job;
          SiftDown(2*jobIndex+1);
        }
      }  
      else if (jobTime > leftChildFinishTime) {
        // swap with left child
        min_heap_[jobIndex] = min_heap_[2*jobIndex+1];
        min_heap_[2*jobIndex+1] = job;
        SiftDown(2*jobIndex+1);
      }
    }
    else if (jobTime >= rightChildFinishTime) {
      if (jobTime == rightChildFinishTime) {
        if (min_heap_[jobIndex][1] > min_heap_[2*jobIndex+2][1]) {
          // swap with right child
          min_heap_[jobIndex] = min_heap_[2*jobIndex+2];
          min_heap_[2*jobIndex+2] = job;
          SiftDown(2*jobIndex+2);
        }
      }
      else if (jobTime > rightChildFinishTime) {
        // swap with right child
        min_heap_[jobIndex] = min_heap_[2*jobIndex+2];
        min_heap_[2*jobIndex+2] = job;
        SiftDown(2*jobIndex+2);
      }
    }
  }

  void Insert(vector<long long> jobTime) {
    if (heap_size_ == min_heap_.size()) {
      cout << "Heap already full; cannot insert" << endl;
      return;
    }

    min_heap_[heap_size_] = jobTime;
    SiftUp(heap_size_);
    heap_size_++;
  }

  vector<long long> ExtractMin() {
    vector<long long> minimum = min_heap_[0];
    min_heap_[0] = min_heap_[heap_size_-1];
    heap_size_--;

    if (heap_size_ == 0) {
      return minimum;
    }

    SiftDown(0);
    return minimum;
  }

  void AssignJobs() {
    heap_size_ = 0;
    long long timer = 0;
    for (int i=0; i<min(min_heap_.size(), jobs_.size()); ++i) {
      vector<long long> job(4);
      job[0] = jobs_[i];
      job[1] = i;
      job[2] = jobs_[i];
      job[3] = i;
      Insert(job);
    }

    // min_heap is implemented correctly

    int jobProc = heap_size_;
    while (jobProc < jobs_.size()) {
      timer = min_heap_[0][0];
      while (min_heap_[0][0] - timer <= 0 && jobProc < jobs_.size()) {
        vector<long long> minimum = ExtractMin();
        assigned_workers_[minimum[3]] = minimum[1];
        start_times_[minimum[3]] = minimum[0] - minimum[2];
        
        vector<long long> jobToInsert(4);
        jobToInsert[0] = timer+jobs_[jobProc];
        jobToInsert[1] = minimum[1];
        jobToInsert[2] = jobs_[jobProc];
        jobToInsert[3] = jobProc;
        Insert(jobToInsert);
        jobProc++;
      }
    }

    while (heap_size_ > 0) {
      vector<long long> minimum = ExtractMin();
      assigned_workers_[minimum[3]] = minimum[1];
      start_times_[minimum[3]] = minimum[0] - minimum[2];
      jobProc++;
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
