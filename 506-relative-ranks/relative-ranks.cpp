class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;  // This will hold the final result
        vector<int> temp = score;  // Copy of the original score vector for sorting
        
        // Sort temp in descending order
        sort(temp.begin(), temp.end(), greater<int>());
        
        unordered_map<int, string> mp;  // Map to store ranks or medals
        for (int i = 0; i < temp.size(); i++) {
            if (i == 0) mp[temp[i]] = "Gold Medal";
            else if (i == 1) mp[temp[i]] = "Silver Medal";
            else if (i == 2) mp[temp[i]] = "Bronze Medal";
            else {
                mp[temp[i]] = to_string(i + 1);  // Convert rank to string
            }
        }
        
        // Assign the ranks or medals to the result based on the original score
        for (int i = 0; i < score.size(); i++) {
            ans.push_back(mp[score[i]]);
        }
        
        return ans;
    }
};
