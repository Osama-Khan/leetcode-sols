#include <vector>

// Traverses the given arrays in reverse order, placing the largest encountered elements
// in 0 slots
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        // Left pointer for nums1 array
        int l = m-1,
        // Right pointer for nums1 array
            r = m+n-1,
        // Pointer for nums2 array progress
            ptr = n-1;

        // Reverse traverse
        while (r >= 0 && l >= 0 && ptr >= 0) {
          if (nums1[l] > nums2[ptr]) {
            nums1[r] = nums1[l];
            l--;
          } else {
            nums1[r] = nums2[ptr];
            ptr--;
          }

          r--;
        }

        // Handle leftover values in nums2
        while (ptr >= 0) {
            nums1[r] = nums2[ptr];
            r--;
            ptr--;
        }
    }
};
