class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        
        vector<vector<int>> ans;

        for( auto i : intervals){
            if(ans.empty() || ans.back()[1]   < i[0]){
                ans.push_back(i);
            }
            else if(ans.back()[1]   >= i[0] && ans.back()[1] < i[1]){
                ans.back()[1] = i[1];
                  
            }
        }
return ans;
    }
};