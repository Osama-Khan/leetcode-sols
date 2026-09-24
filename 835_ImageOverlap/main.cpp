#include <iostream>
#include <vector>

using namespace std;

class Helpers {
	public:
		static void printImage(vector<vector<int>>& img) {
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
};

class Solution {
public:
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
		Helpers::printImage(img1);
		return count;
	}

	void moveI(vector<vector<int>>& img, bool isUpward) const {
		int n = img.size();
		if (n == 1) return;
		for (int i = 0; i < n; i++) {
			// Go from second last to first, replacing the values
			for (int j = 1; j < n; j++) {
				if (isUpward) {
					img[j - 1][i] = img[j][i];
				}
				else {
					img[i][j - 1] = img[i][j];
				}
			}

			// zero out initial as that WILL go out of bounds
			if (isUpward)
			{
				img[n - 1][i] = 0;
			}
			else {
				img[i][n - 1] = 0;
			}
		}
	}

	void move(vector<vector<int>>& img, bool isDownward) const {
		int n = img.size();
		if (n == 1) return;
		for (int i = n - 1; i >= 0; i--) {
			// Go from second last to first, replacing the values
			for (int j = n - 2; j >= 0; j--) {
				if (isDownward) {
					img[j+1][i] = img[j][i];
				}
				else {
					img[i][j+1] = img[i][j];
				}
			}

			// zero out initial as that WILL go out of bounds
			if (isDownward)
			{
				img[0][i] = 0;
			}
			else {
				img[i][0] = 0;
			}
		}
	}

	void moveRight(vector<vector<int>>& img) const {
		move(img, false);
	}

	void moveDown(vector<vector<int>>& img) const {
		move(img, true);
	}

	void moveLeft(vector<vector<int>>& img) const {
		moveI(img, false);
	}

	void moveUp(vector<vector<int>>& img) const {
		moveI(img, true);
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

		vector<vector<int>> imgV = img1;

		vector<vector<char>> combinations = {
			{'r', 'u'},
			{'l', 'u'},
			{'r', 'd'},
			{'l', 'd'},
		};

		for (vector<char> &comb : combinations) {
			for (int i = 0; i < n; i++) {
				vector<vector<int>> imgH = imgV;
				for (int j = 0; j < n - 1; j++) {
					if (comb[0] == 'r') moveRight(imgH);
					else moveLeft(imgH);
					count = getLargerCount(count, imgH, img2);
				}
				if (comb[1] == 'u') moveUp(imgV);
				else moveDown(imgV);
				count = getLargerCount(count, imgV, img2);
			}
			imgV = img1;
		}

		//// Up and left
		//for (int i = 0; i < n; i++) {
		//	vector<vector<int>> imgH = imgV;
		//	for (int j = 0; j < n - 1; j++) {
		//		moveLeft(imgH);
		//		count = getLargerCount(count, imgH, img2);
		//	}
		//	moveUp(imgV);
		//	count = getLargerCount(count, imgV, img2);
		//}

		return count;
	}

	int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
		return getLargestOverlap(img1, img2);
	}
};

int main() {
	Solution sol;

	vector<vector<int>> img1 = {
		{0,0,0,0,1} ,{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}
	};

	vector<vector<int>> img2 = {
		{0,0,0,0,0} ,{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{1,0,0,0,0}
	};

	cout << sol.largestOverlap(img1, img2);

	return 0;
}