#include <vector>

// Uses prefix sum parity to count number of odd sum subarrays
class Solution {
private:
    // Mod value to shrink answer
    static constexpr int MOD = 1000000007;

public:
    int numOfSubarrays(std::vector<int>& arr) {
        // Number of even prefixes encountered. Starts at 1 because the
        // initial empty prefix has a sum of 0 (even).
        int evenPrefixes = 1;
        // Number of odd prefixes encountered.
        int oddPrefixes = 0;
        // Tracks the number of odd-sum subarrays using prefixes.
        int num = 0;
        // Running parity, either 1 or 0.
        short int parity = 0;

        for (size_t i = 0; i < arr.size(); i++) {
            // Update parity using current value
            parity = (parity + arr[i]) % 2;

            if (parity == 0) {
                // Even
                evenPrefixes++;
                num += oddPrefixes;
            } else {
                // Odd
                oddPrefixes++;
                num += evenPrefixes;
            }

            // Mod the current answer
            num %= MOD;
        }

        return num;
    }
};
