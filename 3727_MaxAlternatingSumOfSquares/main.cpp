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
        // Sort the array
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i; j < n; j++) {
                // Abs comparisons cuz squaring would nullify negs
                if (abs(nums[i]) > abs(nums[j])) {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }

        // Initial value
        const size_t midPoint = n/2;
        long long output = pow(nums[midPoint], 2);

        for (size_t i = 0, j = midPoint + 1; i < midPoint; i++, j++) {
            const int toSub = pow(nums[i], 2);
            const int toSum = j < n ? pow(nums[j], 2) : 0;

            output -= toSub;
            output += toSum;
        }

        return output;
    }
};
