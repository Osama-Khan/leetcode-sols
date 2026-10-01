#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	/// <summary>
	/// If the given char is an opening bracket
	/// </summary>
	bool isOpening(char c) const {
		return c == '(' || c == '[' || c == '{';
	}

	/// <summary>
	/// Validates that the given characters are matching opening and closing brackets
	/// </summary>
	/// <param name="c1">char 1</param>
	/// <param name="c2">char 2</param>
	/// <returns>Whether the brackets are matching opening and closing brackets</returns>
	bool bracketMatch(char c1, char c2) const {
		return (c1 == '(' && c2 == ')') ||
			(c1 == '{' && c2 == '}') ||
			(c1 == '[' && c2 == ']');
	}

	bool isValid(string s) {
		// If initial char is not valid, whole string not valid
		if (!isOpening(s[0])) {
			return false;
		}

		stack<char> history;

		for (size_t i = 0; i < s.size(); i++) {
			auto const c = s[i];

			if (history.size() == 0) {
				history.push(c);
				continue;
			}

			// If current is opening bracket, push to stack and continue
			if (isOpening(c)) {
				history.push(c);
				continue;
			}

			// Impossible to deal with opened brackets if not enough chars left
			if (history.size() > (s.size() / 2)) return false;

			// Verify bracket order validity, atp we have only closing brackets possible
			auto const p = history.top();
			if (!bracketMatch(p, c)) {
				return false;
			}

			// All valid, we should have a close for the top entry of stack
			history.pop();
		}

		return history.empty();
	}
};

int main() {
	Solution sol;
	string inp = "()";
	auto out = sol.isValid(inp);
	cout << (out ? "YES" : "NO") << endl;
	return 0;
}