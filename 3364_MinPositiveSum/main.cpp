#include <vector>

// Max possible value + 1 based on given constraints
constexpr int INITIAL = 100001;

class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int curMin = INITIAL;
        // Using l as index representing currently tracked length
        // of subarrays, find minimum sums of all subarrays
        for (; l <= r; l++) {
            // Loop tracking starting index of cur subarray
            for (size_t i = 0; i < nums.size(); i++) {
                int thisSum = 0;
                // Loop summing values of cur subarray
                for (size_t j = i; j < i + l && i + l <= nums.size(); j++) {
                    thisSum += nums[j];
                }
                curMin = thisSum > 0 && thisSum < curMin ? thisSum : curMin;
            }
        }

        return curMin == INITIAL ? -1 : curMin;
    }
};
