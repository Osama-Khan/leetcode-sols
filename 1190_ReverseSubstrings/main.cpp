/// 1190. Reverse Substrings Between Each Pair of Parentheses

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string reverseParentheses(string s) {
		size_t i = 0;

		while (i < s.size()) {
			if (s[i] == '(') {
				if (s[i + 1] == ')') {
					s.replace(i, 2, "");
					continue;
				}
				string const reversed = reverseParentheses(s.substr(i + 1));
				s.replace(i, s.size() - i, reversed);
				continue;
			}
			if (s[i] == ')') {
				string reversed = s.substr(0, i);
				reverse(reversed.begin(), reversed.end());
				s.replace(0, i + 1, reversed);
				return s;
			}
			i++;
		}
		return s;
	}
};

int main() {
	Solution sol;
	string str = "a(b(ce))d";
	string out = sol.reverseParentheses(str);
	string exp = "acebd";
	cout << endl << out << endl << (exp == out ? "YES" : "NO") << endl;
	return 0;
}
