#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        unsigned short int max = *max_element(nums.begin(), nums.end());

        // Figure out distance from all the elements to the max
        unsigned int totalDistance = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            totalDistance += (max - nums[i]);
        }

        return totalDistance;
    }
};