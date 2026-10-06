#include <iostream>
#include <string>
#include <stack>

using namespace std;

/// <summary>
/// Iterates through the provided string, keeping track of unopened closing paras
/// and unclosed opening paras.
/// </summary>
class Solution {
public:
    int minAddToMakeValid(string s) {
        size_t depth = 0;
        size_t extraClosed = 0;

        for (const char c : s) {
            // Depth increase whenever facing '('
            if (c == '(') {
                depth++;
            }
            if (c == ')') {
                // If are at depth 0, all the coming ')'s would be invalid, so
                // we can just increase the score as that would be the number
                // of '('s required to make a VPS.
                if (depth == 0) extraClosed++;
                // Normally reduce depth since we have corresponding '('s
                else depth--;
            }
        }

        // Depth would be representing remaining '('s with no corresponding ')'
        return extraClosed + (depth > 0 ? depth : 0);
    }
};

int main() {
    Solution sol;
    auto inp = "())";
    auto out = sol.minAddToMakeValid(inp);
    cout << out << endl;
    return 0;
}