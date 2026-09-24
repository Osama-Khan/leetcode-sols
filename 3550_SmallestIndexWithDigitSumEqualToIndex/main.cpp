#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int smallestIndex(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			short int sum = 0;
			while (nums[i] > 0) {
				sum += nums[i] % 10;
				nums[i] /= 10;
			}
			if (sum == i) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	Solution sol;

	vector<int> nums = { 223,120,2 };

	cout << sol.smallestIndex(nums);

	return 0;
}