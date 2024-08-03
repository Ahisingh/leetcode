class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleDigitSum = 0;
        int doubleDigitSum = 0;

        for (int num : nums) {
            if (num < 10) {
                singleDigitSum += num;
            } else if (num >= 10 && num < 100) {
                doubleDigitSum += num;
            }
        }

        return singleDigitSum!=doubleDigitSum;
    }
};