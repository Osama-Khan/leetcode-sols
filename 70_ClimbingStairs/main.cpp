#include <unordered_map>

class Solution {
    // Cache of how many steps it takes to climb given number of stairsm. [numStairs]: steps
    std::unordered_map<int, int> cache;

    // Recursively climb given number of stairs, updating cache
    int climb(int n) {
        // <= 2 steps == number of ways
        if (n <= 2) {
            return n;
        }

        // Cache hit, return previously calculated value
        if (cache.count(n)) {
            return cache[n];
        }

        // Climb and update cache for current step
        cache[n] = climb(n-1) + climb(n-2);

        return cache[n];
    }
public:
    int climbStairs(int n) {
        return climb(n);
    }
};
