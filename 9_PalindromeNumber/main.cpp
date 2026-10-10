#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;

		size_t rev = 0;
		for (size_t curX = x; curX > 0; curX /= 10) 
			rev = (rev * 10) + (curX % 10);

		return rev == x;
	}
};

int main() {
	Solution sol;
	auto const inp = 121;
	auto out = sol.isPalindrome(inp);
	cout << (out ? "YES" : "NO") << endl;
	return 0;
}