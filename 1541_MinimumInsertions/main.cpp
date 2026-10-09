#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Runs through the given string, predicts insertions using depth where ( is +1 and )) is -1
/// </summary>
class Solution {
public:
    int minInsertions(string s) {
        size_t depth = 0;
        size_t insertions = 0;

        for (size_t i = 0; i < s.size(); i++) {
            const char c = s[i];

            if (c == '(') {
                depth++;
            }

            if (c == ')') {
                if (i < s.size()) {
                    const char nextC = s[i + 1];
                    if (nextC == ')') {
                        if (depth == 0) {
                            // Need a (
                            insertions += 1;
                        }
                        else {
                            depth--;
                        }
                        // Skip next, we know it is )
                        i++;
                    }
                    else {
                        if (depth == 0) {
                            // Need a ( and ) to create ())
                            insertions += 2;
                        }
                        else {
                            // Need a ) to match opening ( with ))
                            insertions++;
                            depth--;
                        }
                    }
                }
                else {
                    // String ends at a single ), so we need another )
                    insertions++;
                }
            }
        }

        // Add 2 * remaining opened parantheses to achieve relevant ))s
        insertions += depth * 2;
        return insertions;
    }
};