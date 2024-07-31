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
        
        // Compute the prefix sum array
        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }

        // Iterate over each starting point of the substring
        for (int i = 0; i < n; i++) {
            int zeros = 0, ones = 0;
            for (int j = i; j < s.length(); j++) {
                // Calculate the number of '1's in the substring from i to j
                ones = prefix[j];
                if (i != 0) {
                    ones -= prefix[i - 1];
                }
                
                // Calculate the number of '0's in the substring from i to j
                zeros = j - i + 1 - ones;

                // Check if the current substring does not satisfy the condition
                // If not, we increment j to potentially skip unnecessary iterations
                if (zeros * zeros > ones) {
                    j += ((zeros * zeros) - ones - 1);
                }

                // If the current substring satisfies the condition
                if (zeros * zeros <= ones) {
                    // Increment the count of valid substrings
                    ans++;

                    // Optimize further iterations
                    if (zeros * zeros < ones) {
                        int diff = sqrt(ones) - zeros;
                        int nextj = j + diff;
                        
                        // Ensure we don't go out of bounds
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
