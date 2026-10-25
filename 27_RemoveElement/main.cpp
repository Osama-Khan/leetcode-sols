#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Contains indices that are considered removed
        queue<size_t> freeSlots;
        int k = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            const int num = nums[i];

            // Add index to replacable slots if is to be removed
            if (num == val) {
                freeSlots.push(i);
                continue;
            }

            k++;

            // Add current number to latest available free slot if not to be removed
            if (!freeSlots.empty()) {
                nums[freeSlots.front()] = num;
                freeSlots.pop();
                // Mark this index replaceable as the original value was moved out
                freeSlots.push(i);
            }
        }

        return k;
    }
};
