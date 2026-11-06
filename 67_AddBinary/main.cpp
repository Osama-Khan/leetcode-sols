#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;

        const size_t maxInd = max(a.size(), b.size());
        string out(maxInd, '0');

        for (size_t i = 0; i < maxInd; i++) {
            const int ai = a.size() - i - 1;
            const int bi = b.size() - i - 1;
            const int oi = maxInd - i - 1;

            // The - '0' part gives 1 or 0 as int for calculations
            const int av = ai < 0 ? 0 : a[ai] - '0';
            const int bv = bi < 0 ? 0 : b[bi] - '0';

            const int res = av + bv + (carry ? 1 : 0);

            // 0 or 2: output = 0, 1 or 3: output = 1 
            if (res % 2 == 0) out[oi] = '0';
            else out[oi] = '1';

            // > 1 with carry would mean carry is needed
            if (res > 1) carry = true;
            else carry = false;
        }

        if (carry) return '1' + out;

        return out;
    }
};