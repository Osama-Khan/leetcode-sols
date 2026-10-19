#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const size_t n = nums.size();
        vector<int> indices;

        for (int i = 0; i < n; i++) {
            const int el = nums[i];

            if (el == target) {
                indices.push_back(i);
            }
        }

        return indices;
    }
};