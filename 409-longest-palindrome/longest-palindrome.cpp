class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size(),pairs=0;
        map<char, int> c;
        for(int i=0;i<n;i++) {
            c[s[i]]++;
            if(c[s[i]]%2==0)pairs++;
        }
        return pairs*2==n?n:pairs*2+1;
    }
};