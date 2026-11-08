#include <vector>

using namespace std;

// Indicates value of a server in the grid
const int SERVER = 1;

class Solution {
public:
    /// <summary>
    /// Creates an array of server locations in the grid (i,j), then matches rows and cols
    /// to calculate the server count.
    /// </summary>
    int countServers(vector<vector<int>>& grid) {
        // Server node locations (row,col) pair
        vector<pair<int, int>> serverNodes;

        const size_t m = grid.size();
        const size_t n = grid[0].size();

        // Iterate over the grid and fill in server nodes array
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] == SERVER) {
                    serverNodes.push_back({ i, j });
                }
            }
        }

        int count = 0;
        // Calculate count of servers with connections
        for (const auto& a : serverNodes) {
            for (const auto& b : serverNodes) {
                // Active server, skip
                if (a == b)
                    continue;
                // A server that matches the row or col of the server being tested
                if (a.first == b.first || a.second == b.second) {
                    count++;
                    break;
                };
            }
        }

        return count;
    }

    /// <summary>
    /// Maintains counts for servers in rows and cols using two arrays. Calculates total
    /// server count by using the row,col server count for a given cell.
    /// </summary>
    int countServers2(vector<vector<int>>& grid) {
        const size_t m = grid.size();
        const size_t n = grid[0].size();

        // Total servers in the row based on index
        vector<int> rowServers(m, 0);

        // Total servers in the col based on index
        vector<int> colServers(n, 0);

        // Iterate over the grid and fill row / col server counts
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] == SERVER) {
                    rowServers[i]++;
                    colServers[j]++;
                }
            }
        }

        int count = 0;
        // Calculate count of servers with connections
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] == SERVER) {
                    // If a given row / col has 2 or more servers, there are other servers
                    // in the row / col aside from the server at i,j. That would be 
                    // connected to the server at i,j so we increase count.
                    if (rowServers[i] >= 2 || colServers[j] >= 2) count++;
                }
            }
        }

        return count;
    }
};