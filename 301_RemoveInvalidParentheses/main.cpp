#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
private:
	size_t minRemovals(string s) {
		size_t depth = 0;
		size_t invalids = 0;

		for (size_t i = 0; i < s.size(); i++) {
			const char c = s[i];
			if (c == '(') {
				depth++;
			}
			if (c == ')') {
				if (depth == 0) invalids++;
				else depth--;
			}
		}

		// extra opens + unopened closes
		return depth + invalids;
	}

	bool isValidVPS(string s) {
		return minRemovals(s) == 0;
	}

	bool isPara(char const c) const {
		return c == '(' || c == ')';
	}

	size_t paraSize(string s) const {
		size_t size = 0;
		for (auto c : s) {
			if (isPara(c)) size++;
		}
		return size;
	}

	set<pair<string, size_t>> visited;

	bool isVisited(string &s, size_t toRemove) {
		return visited.contains({ s, toRemove });
	}

	set<string> getCombinations(string s, size_t toRemove) {
		set<string> out;

		size_t start = 0;
		// Go to first paranthesis
		for (; start < s.size() && !isPara(s[start]); start++);

		size_t const left = paraSize(s.substr(start));
		if (left < toRemove) return {};

		// Generate combinations
		for (size_t i = start; i < s.size(); i++) {
			// Combinations involving alphabet removal should be skipped
			if (!isPara(s[i])) continue;
			if (i > start && s[i] == s[i - 1]) continue;
			// create new string by removing one char from original string
			string finalStr(s);
			finalStr.erase(i, 1);

			if (isVisited(finalStr, toRemove)) continue;
			
			visited.insert({ finalStr, toRemove });

			if (toRemove > 1) {
				auto combinations = getCombinations(finalStr, toRemove - 1);
				for (auto c : combinations) {
					out.insert(c);
				}
			}
			else {
				out.insert(finalStr);
			}
		}

		return out;
	}

public:
	vector<string> removeInvalidParentheses(string s) {
		size_t const n = minRemovals(s);
		if (n == s.size()) {
			return { "" };
		}
		if (n == 0) {
			return { s };
		}

		set<string> combs = getCombinations(s, n);

		vector<string> out;
		// Get valid combinations out
		for (string c : combs) {
			cout << c << endl;
			if (isValidVPS(c)) out.push_back(c);
		}

		return out;
	}
};

int main() {
	Solution sol;
	auto inp = "((((((((((((((((((aaaaa))";
	auto out = sol.removeInvalidParentheses(inp);
	cout << endl << "[";
	for (int i = 0; i < out.size(); i++) {
		cout << (i == 0 ? "" : ",") << out[i];
	}
	cout << "]";
	return 0;
}