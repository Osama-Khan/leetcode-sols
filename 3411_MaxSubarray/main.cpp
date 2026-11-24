#include <algorithm>
#include <numeric>
#include <vector>

// Brute force solution using two pointers
class Solution {
private:
  int gcdArr(std::vector<int>& arr) {
    if (arr.size() == 0) return 0;

    int gcd = arr[0];
    for (int n : arr) {
      gcd = std::gcd(gcd, n);
    }

    return gcd;
  }

  int lcmArr(std::vector<int>& arr) {
    if (arr.size() == 0) return 0;

    int lcm = arr[0];
    for (int n : arr) {
      lcm = std::lcm(lcm, n);
    }

    return lcm;
  }

  unsigned long long prodArr(std::vector<int>& arr) {
    unsigned long long prod = 1;
    for (int n : arr) {
      prod *= n;
      if (prod == 0) return 0;
    }

    return prod;
  }

public:
    int maxLength(std::vector<int>& nums) {
        std::size_t l = 0;
        std::size_t r = 0;

        unsigned short int longestArrSize = 0;

        while (l < nums.size()) {
            std::vector<int> toProcess;
            for (std::size_t i = l; i <= r; i++) {
              toProcess.push_back(nums[i]);
            }
            if (prodArr(toProcess) == lcmArr(toProcess) * gcdArr(toProcess)) {
              longestArrSize = std::max<int>(r+1-l, longestArrSize);
            }

            if (r < nums.size() - 1) {
              // Keep expanding towards right
              r++;
            } else {
              // Shrink towards right from left, and reset right
              l++;
              r = l;
            }
        }

        return longestArrSize;
    }
};
