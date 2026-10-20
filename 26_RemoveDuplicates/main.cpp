#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/// <summary>
/// Uses two-pointer solution to find distinct elements in a sorted array and move them to the start.
/// </summary>
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		size_t left = 0, right = 1;
		bool hasDupes = false;

		for (; left < nums.size(); left++) {
			// Adjust right, needed when arrays are sorted so left exceeds right
			if (right <= left) right = left + 1;

			// Advance right until dupes are finished
			for (;right < nums.size() && nums[left] == nums[right]; right++) {}
			
			// Found dupes
			if (right != left + 1) {
				hasDupes = true;
				if (right == nums.size()) {
					// Ending at a dupe, ignore
					break;
				}
				nums[left + 1] = nums[right];
			}
		}

		// `left` is at the correct 0-indexed position. left + 1 represents the unique subset.
		// In case of no dupes, nums.size() is the right value for k.
		return hasDupes ? left + 1 : nums.size();
	}
};

int main() {
	vector<int> nums = { 1, 1, 2, 3 };
	int k = Solution().removeDuplicates(nums);
	cout << k << endl;
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	return 0;
}