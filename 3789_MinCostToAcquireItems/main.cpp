#include <algorithm>

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        auto cost = 0LL;

        // costBoth is cheaper than separate costs, so its more efficient
        // to make at least some purchases with it 
        if (costBoth <= cost1 + cost2) {
            // The cost if we cover all purchases with costBoth
            long long costWithBoth = costBoth * 1LL * std::max(need1, need2);

            // Same needs, return the cost
            if (need1 == need2) return costWithBoth;

            // The remaining need to fill
            int remNeed;
            // The cost for the remaining need (cost1|cost2)
            int remCost;
            if (need1 > need2) {
                // need1 is higher, reach need2 with costBoth
                cost += 1LL * costBoth * need2;
                remNeed = need1 - need2;
                remCost = cost1;
            }
            else {
                // Same as above, inverted
                cost += 1LL * costBoth * need1;
                remNeed = need2 - need1;
                remCost = cost2;
            }

            // Use the minimum cost (cost1|cost2 against costBoth) to fill the rest
            int minCost = std::min(remCost, costBoth);
            long long dividedCost = cost + (1LL * remNeed * minCost);

            // Return minimum of buying all with costBoth vs our calculated cost
            return costWithBoth < dividedCost ? costWithBoth : dividedCost;
        }

        // costBoth would cost more than separately buying, so we use the separate costs
        cost += 1LL * need1 * cost1;
        cost += 1LL * need2 * cost2;

        return cost;
    }
};
