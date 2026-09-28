#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	short int maxDepth(string s) {
		short int max = 0;
		short int depth = 0;
		for (short int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				depth += 1;
			}
			else if (s[i] == ')') {
				max = max >= depth ? max : depth;
				depth -= 1;
			}
		}
		return max;
	}
};

int main() {
	string input = "(1+(2*3)+((8)/4))+1";
	cout << Solution().maxDepth(input) << endl;
	return 0;
}