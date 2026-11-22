#include <string>

class Solution {
public:
    bool checkString(std::string s) {
        // Tracks whether a 'b' has been encountered yet.
        bool bFlag = false;

        for (char c : s) {
            // 'b' encountered, set flag to true
            if (c == 'b') bFlag = true;

            // 'a' encountered while bFlag is true, which means
            // 'a' encountered after 'b' so return false.
            if (c == 'a' && bFlag) return false;
        }

        // Loop ended without 'a' after 'b'
        return true;
    }
};
