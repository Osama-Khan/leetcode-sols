#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t l = 0;
        size_t r = nums.size();

        while (l < r) {
            size_t mid = (l + r) / 2;

            if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        // Left would be the target, or the index where target fits in
        return l;
    }
};