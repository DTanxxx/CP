#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
use long long to represent snow
n <= 10^6

longest contiguous length of unique integers
make notes on this type of problem
also notes on using nullptr vs using NULL
*/

struct Segment {
    int start;
    int end;
};

int n;
map<long long,int> mapper;
vector<Segment*> segs_start;
vector<Segment*> segs_end;
vector<long long> snows;

void calculate() {
    int max = 0;
    int seg_end_ptr = 0;
    for (int i=0; i<segs_start.size(); ++i) {
        if (segs_start[i] == nullptr) {
            // create segment until n
            Segment *s = new Segment();
            s->start = i;
            s->end = n;
            segs_start[s->start] = s;
            segs_end[s->end] = s;
        }
        else {
            Segment *seg = segs_start[i];
            segs_end[seg->end] = nullptr;
        }

        Segment *seg = segs_start[i];
        int length = 0;
        while (segs_end[seg_end_ptr] == nullptr && seg_end_ptr < n) {
            seg_end_ptr++;
        }
        
        if (segs_end[seg_end_ptr] == nullptr) {
            length = seg->end-seg->start;
        }
        else {
            int end = segs_end[seg_end_ptr]->end;
            // check if this segment is contained in the 'seg' segment
            if (end <= seg->end) {
                // yes
                length = end-seg->start;
            }
            else {
                // no
                length = seg->end-seg->start;
            }   
        }
        if (length > max) {
            max = length;
        }
    }
    cout << to_string(max) << endl;
}

void process() {
    segs_start.resize(n, nullptr);
    segs_end.resize(n+1, nullptr);
    int copy_n = n;
    while (copy_n--) {
        long long snow;
        scanf("%lld", &snow);
        snows.push_back(snow);
    }
    // construct segments
    for (int i=0; i<snows.size(); ++i) {
        // check if current snow already there
        if (mapper.find(snows[i]) == mapper.end()) {
            // not there, add index to it
            mapper[snows[i]] = i;
        }
        else {
            // snow present, construct segment
            Segment *seg = new Segment();
            seg->start = mapper[snows[i]];
            seg->end = i;
            mapper[snows[i]] = i;
            segs_start[seg->start] = seg;
            segs_end[seg->end] = seg;
        }
    }
    // segs_start will be sorted by start
    // segs_end will be sorted by end
    calculate();
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        mapper.clear();
        segs_start.clear();
        segs_end.clear();
        snows.clear();
        scanf("%d", &n);
        process();
    }
    return 0;
}
