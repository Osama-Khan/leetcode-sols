#include <string>

using namespace std;

/// <summary>
/// Uses a loop to incrementally generate integer value from given roman numeral
/// </summary>
class Solution {
private:
    /// <summary>
    /// Gets the relevant value for given roman numeral
    /// </summary>
    int getValue(char c) const {
        switch (c) {
            case 'M': return 1000;
            case 'D': return 500;
            case 'C': return 100;
            case 'L': return 50;
            case 'X': return 10;
            case 'V': return 5;
            default: return 1;
        }
    }

public:
    int romanToInt(string s) {
        int value = 0;

        for (size_t i = 0; i < s.size(); i++) {
            const char c = s[i];
            const char prevC = i > 0 ? s[i - 1] : ' ';
            const int curVal = getValue(c);
            const int prevVal = prevC == ' ' ? 0 : getValue(prevC);

            // Add current numeral's value, this is later deducted in 9 situation if needed
            value += curVal;

            // 9 situation: IV IX CM etc.
            if (prevVal < curVal) {
                // Subtract for the addition we did earlier, and for the decrement now
                value -= prevVal * 2;
            }
        }

        return value;
    }
};
