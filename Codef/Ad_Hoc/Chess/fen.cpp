#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cctype>

using namespace std;

/*
starting from top to bottom row
'/' used to separate rows
each row from left to right
white pieces are upper case
black pieces are lower case
empty square is number representing number of contiguous empty squares
sum of letters and numbers for each row = 8
*/

/*
initialised to 1 = occupied or attacked
if occupied by a piece then 2
if free then 0
matrix of chessboard, from top to bottom row
initialised to 1 = occupied or attacked
go through input, if number then 0
if not number, go through entire matrix and 1 for any attacked positions
*/

vector<string> chess_board;

void modify_board(int curr_row, int curr_col, char piece, vector<vector<int> > &states, bool isUpper) {
    if (piece == 'r') {
        // a rook
        for (int i=curr_col-1; i>=0; i--) {
            if (states[curr_row][i] == 2) {
                break;
            }
            states[curr_row][i] = 1;
        }
        for (int i=curr_col+1; i<chess_board.size(); ++i) {
            if (states[curr_row][i] == 2) {
                break;
            }
            states[curr_row][i] = 1;
        }
        for (int i=curr_row-1; i>=0; i--) {
            if (states[i][curr_col] == 2) {
                break;
            }
            states[i][curr_col] = 1;
        }
        for (int i=curr_row+1; i<chess_board.size(); ++i) {
            if (states[i][curr_col] == 2) {
                break;
            }
            states[i][curr_col] = 1;
        }
    }
    else if (piece == 'n') {
        // a knight
        // top 
        if (curr_row >= 1) {
            // right down
            if (curr_col <= 5) {
                if (states[curr_row-1][curr_col+2] == 0) {
                    states[curr_row-1][curr_col+2] = 1;
                }
            }
            // left down
            if (curr_col >= 2) {
                if (states[curr_row-1][curr_col-2] == 0) {
                    states[curr_row-1][curr_col-2] = 1;
                }
            }

            if (curr_row >= 2) {
                // right up
                if (curr_col <= 6) {
                    if (states[curr_row-2][curr_col+1] == 0) {
                        states[curr_row-2][curr_col+1] = 1;
                    }   
                }
                // left up
                if (curr_col >= 1) {
                    if (states[curr_row-2][curr_col-1] == 0) {
                        states[curr_row-2][curr_col-1] = 1;
                    }
                }
            }
        }
        // bottom
        if (curr_row <= 6) {
            // right up
            if (curr_col <= 5) {
                if (states[curr_row+1][curr_col+2] == 0) {
                    states[curr_row+1][curr_col+2] = 1;
                }
            }
            // left up
            if (curr_col >= 2) {
                if (states[curr_row+1][curr_col-2] == 0) {
                    states[curr_row+1][curr_col-2] = 1;
                }
            }

            if (curr_row <= 5) {
                // right down
                if (curr_col <= 6) {
                    if (states[curr_row+2][curr_col+1] == 0) {
                        states[curr_row+2][curr_col+1] = 1;
                    }
                }
                // left down
                if (curr_col >= 1) {
                    if (states[curr_row+2][curr_col-1] == 0) {
                        states[curr_row+2][curr_col-1] = 1;
                    }
                }
            }
        }
    }
    else if (piece == 'b') {
        // a bishop
        int row = curr_row-1;
        // up right
        for (int i=curr_col+1; i<chess_board.size(); ++i) {
            if (row < 0 || states[row][i] == 2) {
                break;
            }
            states[row][i] = 1;
            row--;
        }
        // up left
        row = curr_row-1;
        for (int i=curr_col-1; i>=0; i--) {
            if (row < 0 || states[row][i] == 2) {
                break;
            }
            states[row][i] = 1;
            row--;
        }
        // down right
        row = curr_row+1;
        for (int i=curr_col+1; i<chess_board.size(); ++i) {
            if (row >= chess_board.size() || states[row][i] == 2) {
                break;
            }
            states[row][i] = 1;
            row++;
        }
        // down left
        row = curr_row+1;
        for (int i=curr_col-1; i>=0; i--) {
            if (row >= chess_board.size() || states[row][i] == 2) {
                break;
            }
            states[row][i] = 1;
            row++;
        }
    }
    else if (piece == 'q') {
        // a queen
        int row = curr_row-1;
        // up right
        for (int i=curr_col+1; i<chess_board.size(); ++i) {
            if (row < 0 || states[row][i] == 2) {
                break;
            }
            states[row][i] = 1;
            row--;
        }
        // up left
        row = curr_row-1;
        for (int i=curr_col-1; i>=0; i--) {
            if (row < 0 || states[row][i] == 2) {
                break;
            }
            states[row][i] = 1;
            row--;
        }
        // down right
        row = curr_row+1;
        for (int i=curr_col+1; i<chess_board.size(); ++i) {
            if (row >= chess_board.size() || states[row][i] == 2) {
                break;
            }
            states[row][i] = 1;
            row++;
        }
        // down left
        row = curr_row+1;
        for (int i=curr_col-1; i>=0; i--) {
            if (row >= chess_board.size() || states[row][i] == 2) {
                break;
            }
            states[row][i] = 1;
            row++;
        }

        for (int i=curr_col-1; i>=0; i--) {
            if (states[curr_row][i] == 2) {
                break;
            }
            states[curr_row][i] = 1;
        }
        for (int i=curr_col+1; i<chess_board.size(); ++i) {
            if (states[curr_row][i] == 2) {
                break;
            }
            states[curr_row][i] = 1;
        }
        for (int i=curr_row-1; i>=0; i--) {
            if (states[i][curr_col] == 2) {
                break;
            }
            states[i][curr_col] = 1;
        }
        for (int i=curr_row+1; i<chess_board.size(); ++i) {
            if (states[i][curr_col] == 2) {
                break;
            }
            states[i][curr_col] = 1;
        }
    }
    else if (piece == 'k') {
        // a king
        for (int i=curr_col-1; i<curr_col+2; ++i) {
            if (i < 0 || i >= chess_board.size()) {
                continue;
            }
            if (curr_row > 0) {
                if (states[curr_row-1][i] == 0) {
                    states[curr_row-1][i] = 1;
                }
            }
            if (curr_row < chess_board.size()-1) {
                if (states[curr_row+1][i] == 0) {
                    states[curr_row+1][i] = 1;
                }
            }
            if (states[curr_row][i] == 0) {
                states[curr_row][i] = 1;
            }
        }
    }
    else if (piece == 'p') {
        // a pawn - careful whether white or black
        if (isUpper) {
            // white pawn
            if (curr_col > 0 && curr_row > 0) {
                if (states[curr_row-1][curr_col-1] == 0) {
                    states[curr_row-1][curr_col-1] = 1;
                }
            }
            if (curr_col < chess_board.size()-1 && curr_row > 0) {
                if (states[curr_row-1][curr_col+1] == 0) {
                    states[curr_row-1][curr_col+1] = 1;
                }
            }
        }   
        else {
            // black pawn
            if (curr_col > 0 && curr_row < chess_board.size()-1) {
                if (states[curr_row+1][curr_col-1] == 0) {
                    states[curr_row+1][curr_col-1] = 1;
                }
            }
            if (curr_col < chess_board.size()-1 && curr_row < chess_board.size()-1) {
                if (states[curr_row+1][curr_col+1] == 0) {
                    states[curr_row+1][curr_col+1] = 1;
                }
            }
        }
    }
}

void find_safe() {
    vector<vector<int> > states(8, *(new vector<int>(8, 1)));
    for (int i=0; i<chess_board.size(); ++i) {
        string row = chess_board[i];
        int curr_col = 0;
        for (int j=0; j<row.size(); ++j) {
            char piece = row[j];
            if (piece >= '1' && piece <= '8') {
                // it's a number
                for (int k=curr_col; k<(piece-'0'+curr_col); ++k) {
                    states[i][k] = 0;
                }
                curr_col += (piece-'0');
            }
            else {
                // it's a piece
                states[i][curr_col] = 2;
                curr_col++;
            }
        }
    }
    for (int i=0; i<chess_board.size(); ++i) {
        string row = chess_board[i];
        int curr_col = 0;
        for (int j=0; j<row.size(); ++j) {
            char piece = row[j];
            if (piece >= '1' && piece <= '8') {
                curr_col += (piece-'0');
            }
            else {
                // convert to lower case
                if (piece >= 'A' && piece <= 'Z') {
                    piece = tolower(piece);
                    modify_board(i, curr_col, piece, states, true);
                }
                else {
                    modify_board(i, curr_col, piece, states, false);
                }
                curr_col++;
            }
        }
    }

    int answer = 0;
    for (int i=0; i<states.size(); ++i) {
        for (int j=0; j<states[i].size(); ++j) {
            if (states[i][j] == 0) {
                answer++;
            }
        }
    }
    cout << answer << endl;
}

int main() {
    string board;
    while (getline(cin, board)) {
        if (cin.eof() || board == "") {
            break;
        }
        chess_board.clear();
        string delimiter = "/";
        size_t pos = 0;
        string token;
        while ((pos = board.find(delimiter)) != string::npos) {
            token = board.substr(0, pos);
            chess_board.push_back(token);
            board.erase(0, pos+delimiter.length());
        }
        chess_board.push_back(board);
        find_safe();
    }
    return 0;
}
