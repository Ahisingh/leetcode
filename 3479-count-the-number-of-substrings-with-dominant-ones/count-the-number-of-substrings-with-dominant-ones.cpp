class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        
        // Create a prefix sum array to count the number of '1's up to each index
        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                prefix[i] = 1;
            }
        }
        
        
        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }

        
        for (int i = 0; i < n; i++) {
            int zeros = 0, ones = 0;
            for (int j = i; j < s.length(); j++) {
                
                ones = prefix[j];
                if (i != 0) {
                    ones -= prefix[i - 1];
                }
                
                
                zeros = j - i + 1 - ones;

                
                if (zeros * zeros > ones) {
                    j += ((zeros * zeros) - ones - 1);
                }

                
                if (zeros * zeros <= ones) {
                    
                    ans++;

                    
                    if (zeros * zeros < ones) {
                        int diff = sqrt(ones) - zeros;
                        int nextj = j + diff;
                        
                        
                        if (nextj >= n) {
                            ans += (n - j - 1);
                        } else {
                            ans += diff;
                        }

                        // Update j to the next potential start point
                        j = nextj;
                    }
                }
            }
        }

        return ans;
    }
};
