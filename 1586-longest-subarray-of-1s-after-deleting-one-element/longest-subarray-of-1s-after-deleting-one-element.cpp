class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int j = 0, i = 0;
        int res = 0;
        int flag = 0; // Counts zeros in the current window

        while (j < nums.size()) {
            if (nums[j] == 0) {
                flag++;
            }
            while (flag > 1) { // More than one zero in the window
                if (nums[i] == 0) {
                    flag--;
                }
                i++;
            }
            res = max(res, j - i); // Calculate the length of the window minus the excluded zero
            j++;
        }

        return res;
    }
};
