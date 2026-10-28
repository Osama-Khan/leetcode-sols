#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // Current minimum across all traversals
    int minXor = INT_MAX;

    // Tracks already visited cells
    vector<vector<unordered_set<int>>> seen;
    
    // Recursively explores cells in a given grid in right / down direction
    // Updates minXor at end of each path
    void traverse(vector<vector<int>>& grid, size_t x, size_t y, int curscore) {
        const size_t m = grid.size();
        const size_t n = grid[0].size();

        // Already found min, cancels all running paths
        if (minXor == 0) return;

        if (x == 0 && y == 0) {
            // Starting out
            curscore = grid[0][0];
        }
        else {
            // Use previous value
            curscore ^= grid[x][y];
        }

        if (x == m - 1 && y == n - 1) {
            // Reached end, update min
            minXor = min(minXor, curscore);
            return;
        }

        // Check and insert into visited history
        if (!seen[x][y].insert(curscore).second) return;

        // Traverse right
        if (x < m - 1) traverse(grid, x + 1, y, curscore);

        // Traverse down
        if (y < n - 1) traverse(grid, x, y + 1, curscore);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        seen.assign(grid.size(), vector<unordered_set<int>>(grid[0].size()));
        traverse(grid, 0, 0, 0);
        return minXor;
    }
};