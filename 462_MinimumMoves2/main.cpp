#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        const size_t n = nums.size();

        // Sort arr
        sort(nums.begin(), nums.end());

        // Median of the array elements
        int median = nums[n / 2];

        int sum = 0;
        // Calculate moves by summing distances of each element from median of the array
        for (const int el : nums) {
            const int diff = abs(el - median);
            sum += diff;
        }

        return sum;
    }
};