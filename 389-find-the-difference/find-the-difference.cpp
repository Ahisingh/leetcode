class Solution {
public:
    char findTheDifference(string s, string t) {
        string ans = "";  
        int hash[256] = {0};
        for(int i = 0; i < t.size(); i++) {
            hash[t[i]]++;
        }
        for(int i = 0; i < s.size(); i++) {
            hash[s[i]]--;
        }
        for(int i = 0; i < t.size(); i++) {
            if(hash[t[i]] == 1) {
                ans.push_back(t[i]);
            }
        }
        return ans[0];  
    }
};