#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int matchLevel = 0;
        size_t i = 0;
        for (i = 0; i < haystack.size(); i++) {
            // Matching in progress
            if (matchLevel < needle.size() && haystack[i] == needle[matchLevel]) {
                matchLevel++;
                continue;
            }
            // Found
            if (matchLevel == needle.size()) break;

            // Match broke, reset index to start of current match test
            i = i - matchLevel;
            matchLevel = 0;
        }

        // Loop ended with partial match
        if (matchLevel == needle.size()) return i - matchLevel;
        return -1;
    }
};
