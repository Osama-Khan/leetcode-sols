#include <bitset>
#include <vector>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        const int n = nums.size();

        for (size_t i = 0; i < n; i++) {
            size_t toPick = i + 1;
            int cnt = 0;
            bitset<101> seen;
            for (size_t j = i; j < n; j++) {
                int const num = nums[j];
                cnt += seen[num] ? 0 : 1;
                seen[num] = 1;
                sum += cnt * cnt;
            }
        }

        return sum;
    }
};
