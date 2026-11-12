#include <vector>

class Solution {
public:
	int longestMonotonicSubarray(std::vector<int>& nums) {
		short int maxLongest = 1;
		short int curLongest = 1;

		// Direction of current streak (ascending >0, descending <0, equal ==0)
		short int curDir = 0;

		for (size_t i = 1; i < nums.size(); i++) {
			// Dir of this sequence, (ascending >0, descending <0, equal ==0)
			short int dir = 0;
			if (nums[i] > nums[i - 1]) dir = 1;
			if (nums[i] < nums[i - 1]) dir = -1;

			if ((dir == 1 && curDir >= 0) || (dir == -1 && curDir <= 0)) {
				// Streak active, either going up or going down
				curLongest++;
				curDir = dir;
				continue;
			}

			maxLongest = std::max(curLongest, maxLongest);

			// If the current check isnt equal, start counting towards the next streak
			curLongest = dir == 0 ? 1 : 2;
			curDir = dir;
		}

		return std::max(curLongest, maxLongest);
	}
};

int main() {
	std::vector<int> inp = { 24,47,24,23,14,6,9,2,3,19 };
	Solution().longestMonotonicSubarray(inp);
	return 0;
}