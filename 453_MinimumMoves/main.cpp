#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// Calculates minMoves required by figuring out how many decrements it would take
/// to bring all array elements to the minimum value.
/// </summary>
class Solution {
public:
    int minMoves(vector<int>& nums) {
        size_t minIndex = 0;
        unsigned int sum = nums[0];

        // Find min index, and calculate sum of all array elements
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            sum += nums[i];
        }
        
        // Subtracting the minimum num * array length from sum gives us the min moves needed.
        const int output = sum - (nums[minIndex] * nums.size());
        return output;
    }
};


int main() {
    vector<int> inp = { 1,2,3 };
    cout << Solution().minMoves(inp);
    return 0;
}