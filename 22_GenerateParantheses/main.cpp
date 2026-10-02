#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// <summary>
/// Uses recursion to find all the valid parantheses for the given length of pairs.
/// </summary>
class Solution {
public:
	vector<string> result;
	size_t n = 0;

	void generate(string& curStr, size_t open, size_t closed) {
		// Reached max required length
		if (n * 2 == curStr.size()) {
			result.push_back(curStr);
			return;
		}

		if (open < n) {
			curStr += "(";
			generate(curStr, open + 1, closed);
			curStr.pop_back();
		}

		if (open > closed) {
			curStr += ")";
			generate(curStr, open, closed + 1);
			curStr.pop_back();
		}
	}

	vector<string> generateParenthesis(size_t n) {
		// Leetcode sometimes reuses the same Solution object, we should reset members
		this->n = n;
		result.clear();

		string curStr = "";
		// Cur str can't possible exceed n*2
		curStr.reserve(n * 2);

		generate(curStr, 0, 0);
		return result;
	}
};

int main() {
	Solution sol;
	int inp = 4;
	auto out = sol.generateParenthesis(inp);
	cout << endl << "[";
	for (int i = 0; i < out.size(); i++) {
		cout << (i == 0 ? "" : ",") << out[i];
	}
	cout << "]";
	return 0;
	return 0;
}