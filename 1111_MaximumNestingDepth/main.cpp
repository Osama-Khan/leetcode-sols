#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/// <summary>
/// Simulates two subsequences using depths, deciding assignments by comparing
/// depths of subsequences and picking the smaller depth as the subsequence to
/// assign to.
/// </summary>
class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {
		size_t d1 = 0;
		size_t d2 = 0;
		// VPS always starts with '('
		vector<int> out = { 0 };
		// and is moved to subseq 1
		d1++;

		for (size_t i = 1; i < seq.size(); i++) {
			auto const c = seq[i];

			if (c == '(') {
				// Add to first subseq
				if (d1 <= d2) {
					d1++;
					out.push_back(0);
				}
				// Add to second subseq
				else {
					d2++;
					out.push_back(1);
				}
			}
			else {
				// Remove from first subseq
				if (d1 > 0 && d1 >= d2) {
					d1--;
					out.push_back(0);
				}
				// Add to second subseq
				else if (d2 > 0) {
					d2--;
					out.push_back(1);
				}
			}
		}

		return out;
	}
};

int main() {
	Solution sol;
	string inp = "(()())";
	auto out = sol.maxDepthAfterSplit(inp);
	cout << endl << "[";
	for (int i = 0; i < inp.size(); i++) {
		cout << (i == 0 ? "" : ",") << out[i];
	}
	cout << "]";
	return 0;
}
