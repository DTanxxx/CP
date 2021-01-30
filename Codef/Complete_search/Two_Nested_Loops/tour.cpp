#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/*
- find max spread between two adjacent drive ratios 
- 2 clusters front and back contain sprockets
- chain connects 2 sprockets (1 from front cluster and 1 from back)
- drive ratio: ratio of angular velocity of pedals to wheels => n/m (n=num teeth on rear sprocket; m =num teeth on front sprocket)
- 2 drive ratios are adjacent (d1 < d2) if no other drive ratio d1 < d3 < d2
- spread for d1 < d2 is d2/d1
*/

int f;
int r;
vector<int> teeth_front;
vector<int> teeth_rear;
vector<double> ratios;

void process() {
    double ans = 0.0;
    // find drive ratios
    ratios.clear();
    for (int i=0; i<teeth_rear.size(); ++i) {
        for (int j=0; j<teeth_front.size(); ++j) {
            ratios.push_back((double)teeth_rear[i] / (double)teeth_front[j]);
            // cout << (double)teeth_rear[i] / (double)teeth_front[j] << endl;
        }
    }
    // nested loop for adjacent drive ratios; if found then find spread
    // cout << "======" << endl;
    for (int i=0; i<ratios.size()-1; ++i) {
        for (int j=i+1; j<ratios.size(); ++j) {
            // check if adjacent
            bool adjacent = true;
            for (int k=0; k<ratios.size(); ++k) {
                if ((ratios[k] < ratios[j] && ratios[k] > ratios[i]) ||
                (ratios[k] > ratios[j] && ratios[k] < ratios[i])) {
                    adjacent = false;
                    break;
                }
            }
            if (adjacent) {
                if (ratios[i] >= ratios[j] && ratios[i] / ratios[j] > ans) {
                    ans = ratios[i] / ratios[j];
                }
                else if (ratios[i] <= ratios[j] && ratios[j] / ratios[i] > ans) {
                    ans = ratios[j] / ratios[i];
                }
            }
        }
    }
    // find max spread to 2 dp
    double val = (int)(ans * 100 + 0.5);
    cout << fixed << setprecision(2) << (double)(val / 100) << endl;
}

int main() {
    while (scanf("%d", &f), f) {
        scanf("%d", &r);
        teeth_front.resize(f, 0);
        teeth_rear.resize(r, 0);
        for (int i=0; i<f; ++i) {
            cin >> teeth_front[i];
        }
        for (int i=0; i<r; ++i) {
            cin >> teeth_rear[i];
        } 
        process();
    }
    return 0;
}
