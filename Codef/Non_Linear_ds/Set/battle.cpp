#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;
/*
blue fights green: greater power wins
power reduces by the dead guy: 50 v 40, 50 wins but reduced to 50-40=10
same power then both die
num battlefields: each battlefield has one guy
assigned from strongest on field 1 to weakest -> both blue & green

each fight, all battlefields filled (may not be enough)
after power reduction, guys return and come back with most powerful on field 1 and so on
ends when both out of guys or one out of guys

OUTPUT:
the winning side and powers of surviving guys
*/
int fields, green_num, blue_num;
multiset<int, greater <int> > greens;
multiset<int, greater <int> > blues;

void process() {
    while (!greens.empty() && !blues.empty()) {
        vector<int> b_surv;
        vector<int> g_surv;
        b_surv.clear();
        g_surv.clear();
        for (int i=1; i<=fields; ++i) {
            // check if one side is out of guys
            // start from strongest
            int g = 0;
            int b = 0;
            if (!greens.empty()) {
                g = *greens.begin();
                greens.erase(greens.begin());
            }
            if (!blues.empty()) {
                b = *blues.begin(); 
                blues.erase(blues.begin());
            }
            
            if (g > b) {
                g -= b;
                g_surv.push_back(g);
            }
            else if (b > g) {
                b -= g;
                b_surv.push_back(b);
            }
        }
        // add survivors back 
        for (int i=0; i<b_surv.size(); ++i) {
            blues.insert(b_surv[i]);
        }
        for (int i=0; i<g_surv.size(); ++i) {
            greens.insert(g_surv[i]);
        }
    }
    // find the winning side and output guys powers
    multiset<int, greater <int> > :: iterator it;
    if (greens.empty() && blues.empty()) {
        cout << "green and blue died" << endl;
    }
    else if (greens.empty()) {
        cout << "blue wins" << endl;
        for (it = blues.begin(); it != blues.end(); ++it) {
            cout << *it << endl;
        }
    }
    else if (blues.empty()) {
        cout << "green wins" << endl;
        for (it = greens.begin(); it != greens.end(); ++it) {
            cout << *it << endl;
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        greens.clear();
        blues.clear();
        cin >> fields >> green_num >> blue_num;
        while (green_num--) {
            int g;
            cin >> g;
            greens.insert(g);
        }
        while (blue_num--) {
            int b;
            cin >> b;
            blues.insert(b);
        }
        process();
        if (tc != 0) {
            cout << endl;
        }
    }
    return 0;
}
