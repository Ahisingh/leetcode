class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        
        for (int num : nums) {
            if (num <= first) {
                first = num;  // smallest number found so far
            } else if (num <= second) {
                second = num; // second smallest number found so far
            } else {
                // We found a number greater than both first and second
                return true;
            }
        }
        
        return false;
    }
};