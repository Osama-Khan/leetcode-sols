#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        unsigned int k = 0;
        bool kSet = false;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                if (kSet) {
                    k = k & nums[i];
                }
                else {
                    k = nums[i];
                    kSet = true;
                }
            }
        }

        return k;
    }
};