#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string evaluate(string s, vector<vector<string>>& knowledge) {
		// Create knowledge cache
		unordered_map<string, string> knowledgeMap;
		knowledgeMap.reserve(knowledge.size());
		for (vector<string>& item : knowledge) {
			knowledgeMap.insert({item[0], item[1]});
		}

		string builtString = "";
		for (size_t i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				size_t const initial = ++i;
				while (s[i] != ')') i++;
				string const currentKey = s.substr(initial, i - initial);
				auto const knowledgeVal = knowledgeMap.find(currentKey);
				builtString += knowledgeVal == knowledgeMap.end() ? "?" : knowledgeVal->second;
				continue;
			}
			builtString += s[i];
		}
		return builtString;
	}
};

int main() {
	Solution sol;
	string str = "(name)is(age)yearsold";
	vector<vector<string>> knowledge = {
		{"name", "osama"},
		{"age", "20"}
	};
	cout << endl << sol.evaluate(str, knowledge) << endl;
	return 0;
}
