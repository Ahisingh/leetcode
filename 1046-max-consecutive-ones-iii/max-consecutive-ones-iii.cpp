class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxCnt = 0;
        int zeroCount = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            // Expand the window by including the current element
            if (nums[right] == 0) {
                zeroCount++;
            }

            // Shrink the window from the left if there are more than k zeros
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // Calculate the length of the current valid window
            maxCnt = max(maxCnt, right - left + 1);
        }

        return maxCnt;
    }
};
