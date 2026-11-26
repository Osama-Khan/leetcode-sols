#include <algorithm>
#include <vector>

// Maintains a running maximum along with a pre-computed suffix max array then uses them to
// figure out if an element is larger than elements left or right of it. Assuming 0 and n-1
// are already valid.
class Solution {
private:
  // Generates suffix max array for given array
  std::vector<int> generateSuffixes(const std::vector<int> &nums) {
    const int n = nums.size();
    std::vector<int> suffixes(n, 0);
    suffixes[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suffixes[i] = std::max(suffixes[i + 1], nums[i]);
    }
    return suffixes;
  }

public:
  std::vector<int> findValidElements(std::vector<int> &nums) {
    // Up to two elements are naturally all valid
    if (nums.size() <= 2)
      return nums;

    const int n = nums.size();

    // Output array
    std::vector<int> out;
    // Precomputed suffix maximums
    auto sfx = generateSuffixes(nums);
    // Current maximum as iterating the array from left to right
    int prefixMax = nums[0];

    // Push first element, as its always valid
    out.push_back(nums[0]);

    // Iterate from 1st to 2nd last element, as first and last are always valid
    for (std::size_t i = 1; i < n - 1; i++) {
      // To be valid, an element must be greater than prefixes to the left or
      // suffixes to the right
      bool valid = nums[i] > prefixMax || nums[i] > sfx[i + 1];
      if (valid) {
        out.push_back(nums[i]);
      }
      prefixMax = std::max(nums[i], prefixMax);
    }

    // Push last element, as its always valid
    out.push_back(nums[n - 1]);

    return out;
  }
};
