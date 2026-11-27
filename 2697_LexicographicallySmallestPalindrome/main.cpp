#include <string>

class Solution {
public:
  std::string makeSmallestPalindrome(std::string s) {
    // Loop from left to right
    for (size_t l = 0; l < s.size(); l++) {
      // Figure out the right pointer based on left pointer (len - i - 1)
      size_t r = s.size() - l - 1;
      if (s[l] > s[r]) {
        // Right is lexicographically smaller, so change left to right
        s[l] = s[r];
      } else if (s[l] < s[r]) {
        // Left is lexicographically smaller, so change right to left
        s[r] = s[l];
      }
      // Equality case means already palindrome
    }
    return s;
  }
};
