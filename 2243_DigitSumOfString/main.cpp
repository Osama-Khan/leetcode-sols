#include <string>
#include <iostream>

class Solution {
public:
    std::string digitSum(std::string s, int k) {
        // Process until s.size() <= k 
        while (s.size() > k) {
            int l = 0;
            while (l < s.size()) {
                // Sum of 3 length digit pairs
                unsigned int sum = 0;
                for (size_t r = l; r < s.size() && r - l < k; r++) {
                    sum += s[r] - '0';
                }

                // Replace relevant part of s with the sum
                std::string sumStr = std::to_string(sum);
                s.replace(l, k, sumStr);

                // Adjust left pointer for the difference in s length
                l += sumStr.size();
            }
        }

        return s;
    }
};

int main() {
    std::string res = Solution().digitSum("11111222223", 3);
    std::cout << res;
    return 0;
}