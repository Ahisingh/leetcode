class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int max_sum;

        for (int x = 0; x < k; x++) {
            sum += nums[x];
        }

        max_sum = sum;

        for (int i = 1; i <= nums.size() - k; i++) {
            sum = sum - nums[i - 1] + nums[i + k - 1];
            max_sum = max(max_sum, sum);
        }

        return double(max_sum) / k;
    }
};
