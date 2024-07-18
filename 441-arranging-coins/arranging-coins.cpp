class Solution {
public:
    int arrangeCoins(long n) {
        long l = 0;
        long h = n;

        while (l <= h) {
            long m = l + (h - l) / 2;
            long long sum = m * (m + 1) / 2;

            if (sum == n) {
                return m;
            } else if (sum < n) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return h;
    }
};
