#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

struct Contestant {
    int num;
    int correct;
    int penalty;
};

bool compareTwoContestants(Contestant a, Contestant b) {
    if (a.correct != b.correct) {
        return a.correct > b.correct;
    }

    if (a.penalty != b.penalty) {
        return a.penalty < b.penalty;
    }

    return (a.num < b.num);
}

int main() {
    string TC;
    getline(cin, TC);
    int tc = stoi(TC);
    int tccopy = tc;
    string blank;
    getline(cin, blank);
    while (tc--) {
        
        string submission;
        getline(cin, submission);

        vector<Contestant> contestants;
        vector<int> contestant_num(101,0);  // used to check which contestants participated
        vector<int> num_correct(101, 0);
        unordered_map<int,vector<pair<int,int> > > accum_pen;  // vector stores all problems, pair stores each problem's penalty time and whether it should be counted
        contestants.clear();
        num_correct.clear();
        accum_pen.clear();

        for (int i=1; i<101; ++i) {
            accum_pen[i] = *(new vector<pair<int,int> >(10));
        }

        while (submission.size() > 0) {
            // split string by space
            vector<string> result;
            istringstream iss(submission);
            for (string s; iss >> s;) {
                result.push_back(s);
            }

            int contestant = stoi(result[0]);
            int problem = stoi(result[1]);
            int time = stoi(result[2]);
            string output = result[3];

            contestant_num[contestant] = 1;

            if (output == "C") {
                if (accum_pen[contestant][problem].second == 0) {
                    num_correct[contestant] += 1;
                    accum_pen[contestant][problem].first += time;
                    accum_pen[contestant][problem].second = 1;
                } 
            }
            else if (output == "I") {
                if (accum_pen[contestant][problem].second == 0) {
                    accum_pen[contestant][problem].first += 20;
                    accum_pen[contestant][problem].second = 0;
                }   
            }

            getline(cin, submission);
        }

        for (int i=0; i<contestant_num.size(); ++i) {
            if (contestant_num[i] == 1) {
                Contestant contestant;
                contestant.num = i;
                contestant.correct = num_correct[i];

                vector<pair<int,int> > problems = accum_pen[i];
                int penalty_total = 0;
                for (int j=0; j<problems.size(); ++j) {
                    if (problems[j].second == 1) {
                        penalty_total += problems[j].first;
                    }
                }
                contestant.penalty = penalty_total;
                contestants.push_back(contestant);
            }
        }
        
        sort(contestants.begin(), contestants.end(), compareTwoContestants);

        if (tccopy - tc > 1) {
            cout << endl;
        }
        for (int i=0; i<contestants.size(); ++i) {
            cout << contestants[i].num << " " << contestants[i].correct << " " << contestants[i].penalty << endl;
        }
    }
    return 0;
}
