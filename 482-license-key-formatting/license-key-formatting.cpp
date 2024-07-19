class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int itr = 0; // Initialize character count
        string res = ""; // Initialize result string
        
        // Traverse the string from the end to the beginning
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') continue; // Skip dashes
            
            // If itr is not zero and is a multiple of k, add a dash
            if (itr && (itr % k == 0)) res += '-';
            
            // Add the uppercase version of the character to the result
            res += toupper(s[i]);
            
            // Increment the character count
            itr++;
        }
        
        // Reverse the result string to correct the order
        reverse(res.begin(), res.end());
        return res; // Return the formatted string
    }
};
