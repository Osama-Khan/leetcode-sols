#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
	vector<vector<bool>> visited;

	/// <summary>
	/// Navigates an island starting from given location in the grid, returns summed values 
	/// of all cells in the island or 0 for visited cells or water. Updates given score.
	/// </summary>
	/// <param name="grid">The grid containing the islands</param>
	/// <param name="i">Starting col</param>
	/// <param name="j">Starting row</param>
	/// <param name="score">Current score, mutated</param>
	/// <returns></returns>
	void visit(vector<vector<int>>& grid, int i, int j, unsigned long long& score) {
		const size_t m = grid.size();
		const size_t n = grid[0].size();

		// Out of bounds
		if (i < 0 || i >= m || j < 0 || j >= n) return;

		const int value = grid[i][j];

		// Ensure no water / not already visited
		if (value == 0 || visited[i][j]) return;

		visited[i][j] = true;

		score += grid[i][j];

		visit(grid, i + 1, j, score);
		visit(grid, i - 1, j, score);
		visit(grid, i, j + 1, score);
		visit(grid, i, j - 1, score);
	}

public:
	int countIslands(vector<vector<int>>& grid, int k) {
		const size_t m = grid.size();
		const size_t n = grid[0].size();

		// Reset visited when starting
		visited = vector<vector<bool>>(
			m,
			vector<bool>(
				n,
				false
			)
		);

		size_t matched = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				unsigned long long islandScore = 0;
				visit(grid, i, j, islandScore);

				if (islandScore > 0 && islandScore % k == 0) {
					matched++;
				}
			}
		}

		return matched;
	}
};

int main() {
	vector<vector<int>> grid = { {0, 2, 1, 0, 0},{0, 5, 0, 0, 5},{0, 0, 1, 0, 0},{0, 1, 4, 7, 0},{0, 2, 0, 0, 8} };
	int k = 5;

	int matches = Solution().countIslands(grid, k);

	cout << matches;

	return 0;
}