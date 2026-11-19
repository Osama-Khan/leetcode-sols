#include <algorithm>
#include <vector>

// Sorts the array and calculates score for all 3 valid pair switches between min 2 and max 2 elements.
// Returns the minimum of all scores.
//
// Time Complexity is O(nlogn) due to the sorting step, can be reduced to O(n) by picking the 3 max/min
// elements using a loop.
class Solution {
public:
  int minimizeSum(std::vector<int>& nums) {
        const int n = nums.size();

        // Arrays of size upto 3 can be equalized, thus its always 0.
        if (n <= 3)
          return 0;

        std::sort(nums.begin(), nums.end());

        int score = 0;

        // Case 1: Changing first 2 els to 3rd el.
        //         Min is 0. Max is [n-1] - [2].
        int tmpScore = (0) + (nums[n-1] - nums[2]);
        score = tmpScore;

        // Case 2: Changing last 2 els to 3rd last el.
        //         Min is 0. Max is [n-3]-[0].
        tmpScore = (0) + (nums[n-3] - nums[0]);
        score = std::min(score, tmpScore);

        // Case 3: Changing first and last els to 2nd and 2nd last els respectively.
        //         Min is 0. Max is [n-2]-[1]
        tmpScore = (0) + (nums[n-2] - nums[1]);
        score = std::min(score, tmpScore);

        return score;
    }
};
