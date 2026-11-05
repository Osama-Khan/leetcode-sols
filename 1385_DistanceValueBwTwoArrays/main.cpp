#include <vector>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        const size_t n = arr1.size();
        const size_t m = arr2.size();

        unsigned int totalValid = 0;

        for (size_t i = 0; i < n; i++) {
            bool valid = true;
            for (size_t j = 0; j < m; j++) {
                const int distance = abs(arr1[i] - arr2[j]);

                if (distance <= d) {
                    valid = false;
                    break;
                }
            }
            if (valid) totalValid++;
        }

        return totalValid;
    }
};