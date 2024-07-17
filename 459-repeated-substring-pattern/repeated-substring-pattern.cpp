class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        // Iterate over possible lengths of the repeating substring
        for (int i = 1; i <= n / 2; ++i) {
            // Check if the current length divides the total length evenly
            if (n % i == 0) {
                // Extract the substring of the current length
                string substring = s.substr(0, i);
                // Construct the repeated string
                string repeated = "";
                for (int j = 0; j < n / i; ++j) {
                    repeated += substring;
                }
                // Check if the constructed string matches the original string
                if (repeated == s) return true;
            }
        }
        // No repeating pattern found
        return false;
    }
};