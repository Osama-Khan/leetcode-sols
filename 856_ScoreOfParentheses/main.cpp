#include <iostream>
#include <string>
#include <stack>

using namespace std;

const char SCORE_CHAR = 'S';

/// <summary>
/// Builds a stack based expression using a SCORE_CHAR 'S' to indicate a value along with '(' and ')'.
/// Iteratively resolves that expression until the stack is left with just 'S', which is the answer.
/// Also maintains a stack of score values corresponding to the score chars in the expr stack.
/// </summary>
class Solution {
public:
	int scoreOfParentheses(string s) {

		// Score values stack based on occurences of S in our string
		stack<size_t> scoreValues;
		
		// The stack of our expression
		stack<char> expr;

		for (size_t i = 0; i < s.size(); i++) {
			char const c = s[i];

			if (c == '(') {
				expr.push('(');
			}
			if (c == ')') {
				// In a balanced string, ) would always have a char before it
				if (expr.top() == SCORE_CHAR && expr.size() > 1) {
					// Resolve expression and update score
					const size_t score = scoreValues.top();
					scoreValues.pop();
					scoreValues.push(score * 2);

					// Remove the '(S' part, S is added later through score resolver logic
					expr.pop(); 
					expr.pop(); 
				} else if (expr.top() == '(') {
					expr.pop();

					// New pair, so start with 1 score when resolving previous score chars
					scoreValues.push(1);
				}

				// Score resolver: sum through all preceding score chars to reach a single score
				size_t score = scoreValues.top();
				scoreValues.pop();
				while (!expr.empty() && expr.top() == SCORE_CHAR) {
					score += scoreValues.top();
					scoreValues.pop();
					expr.pop();
				}
				scoreValues.push(score);
				expr.push(SCORE_CHAR);
			}
		}

		return scoreValues.top();
	}
};


int main() {
	Solution sol;
	auto inp = "(()(()))";
	auto out = sol.scoreOfParentheses(inp);
	cout << out << endl;
	return 0;
}