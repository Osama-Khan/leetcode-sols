#include <vector>

using namespace std;

/// <summary>
/// Finds the maximum alternating sum in an array by sorting it and using
/// two indexes to sub first half values and sum second half values alter-
/// natively
/// </summary>
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const size_t n = nums.size();

        // Square the array
        for (size_t i = 0; i < n; i++) {
            nums[i] *= nums[i];
        }

        // Sort
        sort(nums.begin(), nums.end());

        const size_t midPoint = n / 2;

        // Initial value is at the midpoint, the first value in the larger values half
        long long output = nums[midPoint];

        for (size_t i = 0, j = midPoint + 1; i < midPoint; i++, j++) {
            const int toSub = nums[i];
            const int toSum = j < n ? nums[j] : 0;

            output -= toSub;
            output += toSum;
        }

        return output;
    }
};
