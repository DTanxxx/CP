#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::vector;

string adjust_word(string word) {
    string newString;
    for (int i=0; i<word.size(); i++) {
        if (islower(word[i])) {
            newString.push_back(toupper(word[i]));
        }
        else {
            newString.push_back(tolower(word[i]));
        }
    }
    return newString;
}

int main() {
    string word;
    std::cin >> word;

    bool firstCase = true;
    bool secondCase = true;
    
    for (int i=1; i<word.size(); i++) {
        if (islower(word[i])) {
            firstCase = false;
            secondCase = false;
            break;
        }
    }

    if (firstCase && secondCase) {
        if (islower(word[0])) {
            firstCase = false;
        }
        else {
            secondCase = false;
        }
    }

    if (firstCase || secondCase) {
        std::cout << adjust_word(word) << std::endl;
    }
    else {
        std::cout << word << std::endl;
    }
    return 0;
}