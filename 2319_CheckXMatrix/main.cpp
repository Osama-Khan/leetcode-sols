#include <vector>

using namespace std;

class Solution {
    const int NON_DIAG = 0;

public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        const size_t n = grid.size();

        for (size_t row = 0; row < n; row++) {
            for (size_t col = 0; col < n; col++) {
                const int cell = grid[row][col];

                // Whether the current cell falls in the top left to bottom right diagonal
                const bool ld = row == col;
                // Whether the current cell falls in the top right to bottom left diagonal
                const bool rd = row + col == n - 1;

                const bool isDiag = ld || rd;

                if (
                    // Non diagonal value in diagonal cell
                    (isDiag && cell == NON_DIAG) || 
                    // Diagonal value in non diagonal cell
                    (!isDiag && cell != NON_DIAG)) 
                {
                    return false;
                }
            }
        }

        return true;
    }
};