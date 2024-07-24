class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, maxLength = 1;
        
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1;
        };
        
        for (int i = 0; i < n; i++) {
            int len1 = expandAroundCenter(i, i);
            int len2 = expandAroundCenter(i, i + 1);
            int len = max(len1, len2);
            
            if (len > maxLength) {
                maxLength = len;
                start = i - (maxLength - 1) / 2;
            }
        }
        
        return s.substr(start, maxLength);
    }
};
