#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int L;
    while (scanf("%d", &L), (L)) {
        int counter = L-1;
        string currentState = "+x";
        while (counter--) {
            string bend;
            cin >> bend;

            if (currentState == "+x") {
                if (bend == "+y") {
                    currentState = "+y";
                }
                else if (bend == "-y") {
                    currentState = "-y";
                }
                else if (bend == "+z") {
                    currentState = "+z";
                }
                else if (bend == "-z") {
                    currentState = "-z";
                }
            }
            else if (currentState == "-x") {
                if (bend == "+y") {
                    currentState = "-y";
                }
                else if (bend == "-y") {
                    currentState = "+y";
                }
                else if (bend == "+z") {
                    currentState = "-z";
                }
                else if (bend == "-z") {
                    currentState = "+z";
                }
            }
            else if (currentState == "+y") {
                if (bend == "+y") {
                    currentState = "-x";
                }
                else if (bend == "-y") {
                    currentState = "+x";
                }
                else if (bend == "+z") {
                    currentState = "+y";
                }
                else if (bend == "-z") {
                    currentState = "+y";
                }
            }
            else if (currentState == "-y") {
                if (bend == "+y") {
                    currentState = "+x";
                }
                else if (bend == "-y") {
                    currentState = "-x";
                }
                else if (bend == "+z") {
                    currentState = "-y";
                }
                else if (bend == "-z") {
                    currentState = "-y";
                }
            }
            else if (currentState == "+z") {
                if (bend == "+y") {
                    currentState = "+z";
                }
                else if (bend == "-y") {
                    currentState = "+z";
                }
                else if (bend == "+z") {
                    currentState = "-x";
                }
                else if (bend == "-z") {
                    currentState = "+x";
                }
            }
            else if (currentState == "-z") {
                if (bend == "+y") {
                    currentState = "-z";
                }
                else if (bend == "-y") {   
                    currentState = "-z";
                }
                else if (bend == "+z") {
                    currentState = "+x";
                }
                else if (bend == "-z") {   
                    currentState = "-x";
                }
            }
        }
        cout << currentState << endl;
    }     
    return 0;
}