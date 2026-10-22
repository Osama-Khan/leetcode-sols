#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        short int letterCount = 0;

        for (short int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ' && letterCount > 0) {
                break;
            }
            if (s[i] != ' ') letterCount++;
        }

        return letterCount;
    }
};

int main() {
    cout << Solution().lengthOfLastWord("Hi");
    return 0;
}