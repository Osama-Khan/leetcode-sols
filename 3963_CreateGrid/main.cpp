#include <iostream>
#include <vector>

using namespace std;

class Solution {
    const char FREE = '.';
    const char OBST = '#';
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, OBST));

        // Trace a valid path (right,right...,down,down...) until out of bounds
        size_t step = 0;

        // Top row fill
        for (size_t i = 0; i < n; i++) {
            grid[0][i] = FREE;
        }

        // Last column fill
        for (size_t i = 0; i < m; i++) {
            grid[i][n - 1] = FREE;
        }

        return grid;
    }
};