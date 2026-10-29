#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const size_t n = digits.size();

        // Tracks sum carry
        bool carry = false;

        for (size_t i = n - 1; ; i--) {
            const int v = digits[i];

            // Set to 0 with a carry if 9
            if (v == 9) {
                digits[i] = 0;
                carry = true;

                // Force break as size_t index would not go below 0
                if (i == 0) break;
                continue;
            };

            // Reset carry and sum the current digit
            digits[i] = digits[i] + 1;
            carry = false;
            break;
        }

        // Carry exists, meaning digits arr contained only 9s
        if (carry) {
            // Add 1 at start, rest will be 0
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main() {
    Solution sol;
    vector<int> input = { 8,9 };
    input = sol.plusOne(input);
    for (int d : input) {
        cout << d;
    }
    cout << endl;
    return 0;
}