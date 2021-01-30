#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> rotate_matrix(vector<string> small_matrix) {
   vector<string> rotated_matrix;
   for (int j=0; j<small_matrix.size(); ++j) {
       string new_row = "";
       for (int i=small_matrix.size()-1; i>=0; --i) {
           new_row += small_matrix[i][j];
       }
       rotated_matrix.push_back(new_row);
   }
   return rotated_matrix;
}

int main() {
    int N, n;
    while (scanf("%d %d", &N, &n), (N || n)) {
        vector<string> big_matrix;
        int Ncopy = N;
        while (Ncopy--) {
            string row;
            cin >> row;
            big_matrix.push_back(row);
        }
        vector<string> small_matrix;
        int ncopy = n;
        while (ncopy--) {
            string row;
            cin >> row;
            small_matrix.push_back(row);
        }

        int num = 4;
        string answer = "";
        while (num--) {
            vector<pair<int,int> > valid_positions;
            for (int i=0; i<small_matrix.size(); ++i) {
                if (valid_positions.size() == 0) {
                    for (int j=0; j<=big_matrix.size()-n; ++j) {
                        for (int k=0; k<=big_matrix[j].size()-n; ++k) {
                            if (big_matrix[j].substr(k, n) == small_matrix[i]) {
                                pair<int,int> *valid = new pair<int,int>(j,k);
                                valid_positions.push_back(*valid);
                            }
                        }
                    }
                }
                else {
                    vector<pair<int,int> > new_valid_positions;            
                    for (int j=0; j<valid_positions.size(); ++j) {
                        pair<int,int> position = valid_positions[j];
                        string row_to_check = big_matrix[position.first+1];
                        if (row_to_check.substr(position.second, n) == small_matrix[i]) {                           
                            pair<int,int> *valid = new pair<int,int>(position.first+1,position.second);
                            new_valid_positions.push_back(*valid);
                        }
                    }
                    valid_positions = new_valid_positions;
                    new_valid_positions.clear();
                }
            }

            if (answer.size() == 0) {
                answer += to_string(valid_positions.size());
            }
            else {
                answer += " ";
                answer += to_string(valid_positions.size());
            }
            valid_positions.clear();
            small_matrix = rotate_matrix(small_matrix);
        }
        cout << answer << endl;   
    }
    return 0;
}