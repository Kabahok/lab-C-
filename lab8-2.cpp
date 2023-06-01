#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {
    string input = "apple banana orange apple grape banana apple";
    string item;
    string res;
    int cntWords = 0;
    
    istringstream iss(input);
    unordered_map<string, int> countWord;
    
    while (iss >> item) {
        countWord[item] += 1;
    }
    
    for (auto& item : countWord) {
        if (item.second > 1) {
            cntWords += 1;
            continue;
        }
        res += item.first + " ";
    }
    
    cout << cntWords << endl;
    cout << res << endl;
    
    return 0;
}
