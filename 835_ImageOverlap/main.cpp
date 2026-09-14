#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	void printImage(vector<vector<int>>& img) {
		int n = img.size();
		cout << "---------" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << img[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "---------" << endl;
	}

	int countOverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2) {
		int n = img1.size();
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (img1[i][j] == 1 && img2[i][j] == 1) {
					count++;
				}
			}
		}
		printImage(img1);
		printImage(img2);
		cout << count << endl;
		return count;

	}

	void move(vector<vector<int>>& img, bool isDownward) const {
		int n = img.size();
		if (n == 1) return;
		for (int i = 0; i < n; i++) {
			// Tmp var to hold the last replaced value, starting with initial
			int lastReplaced = isDownward ? img[0][i] : img[i][0];

			// Go from second to last, swapping value with last replaced
			for (int j = 1; j < n; j++) {
				if (isDownward) {
					int tmp = lastReplaced;
					lastReplaced = img[j][i];
					img[j][i] = tmp;
				}
				else {
					int tmp = lastReplaced;
					lastReplaced = img[i][j];
					img[i][j] = tmp;
				}
			}

			// Update first value with last replaced, which should be the last value in sequence
			if (isDownward) {
				img[0][i] = lastReplaced;
			} else {
				img[i][0] = lastReplaced;
			}
		}
	}

	void moveRight(vector<vector<int>>& img) const {
		move(img, false);
	}

	void moveDown(vector<vector<int>>& img) const {
		move(img, true);
	}

	int getLargerCount(int currentCount, vector<vector<int>>& img1, vector<vector<int>>& img2) {
		int countNow = countOverlaps(img1, img2);
		if (countNow > currentCount) {
			return countNow;
		}
		return currentCount;
	}

	int getLargestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
		int n = img1.size();
		int count = getLargerCount(0, img1, img2);;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				moveRight(img1);
				count = getLargerCount(count, img1, img2);
			}
			moveDown(img1);
			count = getLargerCount(count, img1, img2);
		}

		return count;
	}

public:
	int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
		return getLargestOverlap(img1, img2);
	}
};

int main() {
	Solution sol;

	vector<vector<int>> img1 = {
		{0, 1},
		{1, 1}
	};

	vector<vector<int>> img2 = {
		{1, 1},
		{1, 0}
	};

	cout << endl << sol.largestOverlap(img1, img2) << endl;

	return 0;
}