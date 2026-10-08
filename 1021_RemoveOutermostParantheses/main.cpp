#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Uses a pointer to track start of outer parantheses and remove them
/// </summary>
class Solution1 {
public:
    string removeOuterParentheses(string s) {
        size_t depth = 0;
        size_t outerStart = 0;

        for (size_t i = 0; i < s.size(); i++) {
            const char c = s[i];

            if (c == '(') {
                if (depth == 0) outerStart = i;
                depth++;
            }
            if (c == ')') {
                depth--;
                if (depth == 0) {
                    s.erase(i, 1);
                    s.erase(outerStart, 1);
                    i -= 2;
                }
            }
        }
        return s;
    }
};

/// <summary>
/// Builds a new string by excluding outer parantheses using depth tracking
/// </summary>
class Solution2 {
public:
    string removeOuterParentheses(string s) {
        string newOne = "";
        size_t depth = 1;

        for (size_t i = 1; i < s.size(); i++) {
            const char c = s[i];

            if (c == '(') {
                depth++;
                if (depth == 1) {
                    // prevent adding if went from 0 -> 1
                    continue;
                }
            }
            if (c == ')') {
                depth--;
                if (depth == 0) {
                    // prevent adding to new string
                    continue;
                }
            }

            newOne += c;
        }

        return newOne;
    }
};