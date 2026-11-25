#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> findValidElements(std::vector<int>& nums) {
        // List of indexes that have invalid elements
        std::vector<std::size_t> invalidIndexes;

        for (std::size_t i = 1; i + 1 < nums.size(); i++) {
            bool flagLeft = false;

            // Check left
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] <= nums[j]) {
                    flagLeft = true;
                    break;
                }
            }

            // Left satisfied
            if (!flagLeft) continue;

            // Check right
            for (std::size_t j = i + 1; j < nums.size(); j++) {
                if (nums[i] <= nums[j]) {
                    invalidIndexes.push_back(i);
                    break;
                }
            }
        }

        if (invalidIndexes.empty()) return nums;

        std::vector<int> out;
        for(std::size_t i = 0; i < nums.size(); i++) {
            auto found = std::find(invalidIndexes.begin(), invalidIndexes.end(), i);
            if (found == invalidIndexes.end()) {
              out.push_back(nums[i]);
            }
        }

        return out;
    }
};
