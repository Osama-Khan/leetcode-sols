#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Start with longest prefix being the first string
        string longest = strs[0];

        // "" case
        if (longest.size() == 0) return "";

        // Go 1 to array len, finding the matching prefixes
        for (size_t i = 1; i < strs.size(); i++) {
            const string cur = strs[i];

            // "" case
            if (cur.size() == 0) return "";

            // Index tracking the maximum length of prefix match
            size_t j = 0;
            for (; j < longest.size(); j++) {
                // No match
                if (longest[j] != cur[j])
                    break;
            }

            // 0 letters matched, return ""
            if (j == 0) {
                return "";
            }

            // Adjust longest according to the latest match length
            longest = longest.substr(0, j);
        }

        return longest;
    }
};
