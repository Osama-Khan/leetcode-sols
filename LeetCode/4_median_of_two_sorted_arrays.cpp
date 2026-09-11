#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArray(vector<int>& nums) {
		int len = nums.size();
		// Simple cases
		if (len == 0) return 0;
		if (len == 1) return nums[0];


		// Even size
		if (len % 2 == 0) {
			// get left by subtracting 1 for zero indexing, size is 1 indexed
			int l = nums[(len / 2) - 1];
			int r = nums[(len / 2)];
			return (l + r) / (double) 2;
		}

		// Odd size
		return nums[len / (double) 2];
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();

		// First array is empty
		if (m == 0) {
			// If first array has an element return that
			if (n == 1) return nums2[0];
			// If no element, return 0
			if (n == 0) return 0;
			// If has multiple, return median of it
			return findMedianSortedArray(nums2);
		}
		// Second array is empty
		if (n == 0) {
			// If first array has an element return that
			if (m == 1) return nums1[0];
			// If no element, return 0
			if (m == 0) return 0;
			// If has multiple, return median of it
			return findMedianSortedArray(nums1);
		}

		int higherIndex = m > n ? m : n;

		int mark1 = 0, mark2 = 0;

		vector<int> resultArr;
		resultArr.reserve(m + n);

		// Aggregate until higherIndex reached
		while (mark1 < higherIndex || mark2 < higherIndex) {
			// Handle a mark reaching end of arr case	

			int el1 = nums1[mark1];
			int el2 = nums2[mark2];

			if (el1 == el2) {
				// Matching elements, both go into array and markers move.
				resultArr.push_back(el1);
				resultArr.push_back(el2);
				mark1++; 
				mark2++;
			} else if (el1 < el2) {
				// 1 is less than 2, add el1 to array and mark1 should move ahead
				resultArr.push_back(el1);
				mark1++;
			} else if (el2 < el1) {
				// 2 is less than 1, add el2 to array and mark2 should move ahead
				resultArr.push_back(el2);
				mark2++;
			}

			// If both arrays ended, break
			if (mark1 >= m && mark2 >= n) break;

			// Mark out of bounds case
			if (mark1 >= m) {
				// mark1 exceeded arr length, concat nums2 to resultArr
				resultArr.insert(resultArr.end(), nums2.begin() + (mark2), nums2.end());
				break;
			}
			if (mark2 >= n) {
				// mark2 exceeded arr length, concat nums1 to resultArr
				resultArr.insert(resultArr.end(), nums1.begin() + (mark1), nums1.end());
				break;
			}
		}

		return findMedianSortedArray(resultArr);
	}
};

int main() {
	Solution sol;
	vector<int> arr1 = {
		
	};
	vector<int> arr2 = {
		2,3
	};
	cout << endl << sol.findMedianSortedArrays(arr1, arr2) << endl;
	return 0;
}
