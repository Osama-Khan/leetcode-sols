class Solution {
public:
    bool canAliceWin(int n) {
        // Current number of removals to perform
        int removals = 10;

        // Keep removing until can't remove, i.e. n is lower than removals needed
        while (n >= removals) {
            n -= removals--;
        }

        // Odd-check can help as bob and alice alternate after removals
        // Odd = bob's turn failed, Even = alice's turn failed
        return removals % 2 == 1;
    }
};
