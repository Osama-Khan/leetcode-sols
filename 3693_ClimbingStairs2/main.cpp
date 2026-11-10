#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/// <summary>
/// Uses top-down DP (memoization) to solve Climbing Stairs II. Caches the minimum
/// cost to finish from each step, so every step is solved once. A revisited step
/// reuses its cached value instead of being traversed again.
/// </summary>
class Solution {
private:
	// Cache of the minimum cost to reach the end from [step]
	vector<unsigned int> dp;

	void traverse(int step, int& n, vector<int>& costs) {
		// Last step with dp already assigned, return
		if (step == n) return;

		unsigned int minCost = UINT32_MAX;
		// traverse possible paths
		for (int i = 1; i <= 3; i++) {
			const int effIndex = 3 - i;
			const int nextIndex = step + effIndex + 1;

			if (nextIndex <= n) {
				// Only traverse if not already explored
				if (dp[nextIndex] == UINT32_MAX) {
					traverse(nextIndex, n, costs);
				}

				// Update the cost achieved by next cache with jump costs
				const unsigned int diff = nextIndex - step;
				const unsigned int jumpCost = costs[nextIndex - 1] + (diff * diff);

				// Update minCost from the latest available dp data
				const unsigned int traversalCost = dp[nextIndex] + jumpCost;
				minCost = min(minCost, traversalCost);
			}
		}

		// Update current step cache
		dp[step] = minCost;
	}
public:
	int climbStairs(int n, vector<int>& costs) {
		dp = vector<unsigned int>(n + 1, UINT32_MAX);
		dp[n] = 0;

		traverse(0, n, costs);

		return dp[0];
	}
};