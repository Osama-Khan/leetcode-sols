#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// Provides move types for grid traversal
/// </summary>
enum Move {
    Right,
    Down
};

/// <summary>
/// Traverses new paths in given grid while handling reflections, uses a state cache to skip visited
/// paths
/// </summary>
class Solution {
private:
    const int EMPTY = 0;
    const int MIRROR = 1;

    // Cache that holds valid paths at a state as [x][y][move] 3D array.
    vector<vector<vector<int>>> cache;

    /// <summary>
    /// Updates cache at given cell wrt last move
    /// </summary>
    /// <param name="x">Current row</param>
    /// <param name="y">Current col</param>
    /// <param name="lastMove">Last move direction</param>
    /// <param name="fromDir">The direction to update from. Right -> y + 1, Down -> x + 1</param>
    void updateCache(size_t x, size_t y, Move lastMove, Move fromDir) {
        bool isEmpty = cache[x][y][lastMove] == -1;
        size_t nextX = fromDir == Right ? x : x + 1;
        size_t nextY = fromDir == Right ? y + 1 : y;

        if (isEmpty) cache[x][y][lastMove] = 0;
        cache[x][y][lastMove] += cache[nextX][nextY][fromDir];
        cache[x][y][lastMove] %= 1000000007;

        return;
    }

    /// <summary>
    /// Traverses through the given grid at given positions using lastMove for reflections in case of mirrors
    /// </summary>
    /// <param name="grid">The binary data grid</param>
    /// <param name="x">Current row</param>
    /// <param name="y">Current col</param>
    /// <param name="lastMove">Last move direction</param>
    void traverse(vector<vector<int>>& grid, size_t x, size_t y, Move lastMove) {
        const size_t m = grid.size();
        const size_t n = grid[0].size();


        // Out of bounds, invalid path
        if (x >= m || y >= n) {
            return;
        }

        // Check cache and skip if already calculated
        const long long cachedValid = cache[x][y][lastMove];
        if (cachedValid != -1) return;

        // At mirror, Reflect
        if (grid[x][y] == MIRROR) {
            if (lastMove == Right) {
                // Reflect down
                traverse(grid, x + 1, y, Down);
                // Update if has row neighbor
                if (x < m - 1) updateCache(x, y, lastMove, Down);
                // Set to 0 if no row neighbor
                else cache[x][y][lastMove] = 0;
            }
            else {
                // Reflect right
                traverse(grid, x, y + 1, Right);
                // Update if has col neighbor
                if (y < n - 1) updateCache(x, y, lastMove, Right);
                // Set to 0 if no col neighbor
                else cache[x][y][lastMove] = 0;
            }
            return;
        }

        // At end of grid
        if (x == m - 1 && y == n - 1) {
            cache[x][y][lastMove] = 1;
            return;
        }

        // Normal path handling
        if (x < m - 1) {
            traverse(grid, x + 1, y, Down);
            updateCache(x, y, lastMove, Down);
        }
        if (y < n - 1) {
            traverse(grid, x, y + 1, Right);
            updateCache(x, y, lastMove, Right);
        }
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        const size_t m = grid.size();
        const size_t n = grid[0].size();
        
        // Reset cache state
        cache = vector(m, vector(n, vector<int>(2, -1)));

        // Start traversal
        traverse(grid, 0, 0, Right); // lastMove doesnt initially matter, put whatever
        return cache[0][0][Right];
    }
};

int main() {
    vector<vector<int>> grid = { {0, 1, 0, 0},{0, 0, 1, 0} };
    cout << Solution().uniquePaths(grid);
    return 0;
}