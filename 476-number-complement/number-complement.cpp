class Solution {
public:
    int findComplement(int num) {
        long long int result = 0;
        long long int bit = 1;

        while (num > 0) {
            result += (num % 2 ^ 1) * bit;
            num /= 2;
            bit *= 2;
        }

        return result;
    }
};

