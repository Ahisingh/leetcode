class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int z = x ^ y;
        for (int i = 0; i <= 31; i++) {  
            if (z & (1 << i)) {  
                ans++;  
            }
        }
        return ans;
    }
};
