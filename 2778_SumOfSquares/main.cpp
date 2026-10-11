#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0;
        size_t const n = nums.size();

        for (size_t i = 0; i < n; i++) {
            size_t const divisor = i + 1;
            int const el = nums[i];

            if (n % divisor == 0) {
                sum += el * el;
            }
        }

        return sum;
    }
};