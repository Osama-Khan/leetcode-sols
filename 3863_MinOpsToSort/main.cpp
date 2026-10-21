#include <string>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        size_t n = s.size();
        if (n < 2)
            return 0;
        if (n == 2) {
            // If already sorted, 0 ops
            if (s[0] <= s[1])
                return 0;
            return -1;
        }

        char minc = 'z', maxc = 'a';

        bool isSorted = true;

        for (size_t i = 0; i < s.size(); i++) {
            const char c = s[i];
            if (i + 1 < s.size() && s[i + 1] < s[i]) {
                isSorted = false;
            }
            minc = min(c, minc);
            maxc = max(c, maxc);
        }

        if (isSorted) return 0;

        if (s[0] == minc || s[n - 1] == maxc) {
            return 1;
        }

        if (s[0] == maxc && s[n - 1] == minc) {
            // If there are extremes in the inner section, we get 2 ops
            // helps for duplicates like jgg, caa etc.
            for (int i = 1; i < n - 1; i++) {
                if (s[i] == minc || s[i] == maxc)
                    return 2;
            }
            return 3;
        } else {
            return 2;
        }
    }
};
