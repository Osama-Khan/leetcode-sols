class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int l = 1;
        // r will never be x, since r * r == x is the max possible
        int r = x / 2;

        // Iterate using binary search until match is found
        while (l < r) {
            const size_t mid = l + (r - l + 1) / 2;
            const long long power = mid * mid;

            // Match
            if (power == x) return mid;
            
            // Higher or lower, adjust pointers
            if (power < x) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};

int main() {
    const int res = Solution().mySqrt(8);
    return 0;
}